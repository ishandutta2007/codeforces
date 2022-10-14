#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct segtree {
  vector<int> st;
  segtree(int n) {
    st.resize(4 * n);
  }
  void build(int node, int l, int r, vector<int>& niz) {
    if (l > r) return;
    if (l == r)  {
      st[node] = l;
      return;
    }
    int mid = l + r >> 1;
    build(node * 2, l, mid, niz);
    build(node * 2 + 1, mid + 1, r, niz);
    if (niz[st[node * 2]] > niz[st[node * 2 + 1]]) st[node] = st[node * 2];
    else st[node] = st[node * 2 + 1];
  }
  int get(int node, int l, int r, int ll, int rr, vector<int>& niz) {
    if (l > r || l > rr || r < ll) return ll;
    if (ll <= l && r <= rr) return st[node];
    int mid = l + r >> 1;
    int L = get(node * 2, l, mid, ll, rr, niz);
    int R = get(node * 2 + 1, mid + 1, r, ll, rr, niz);
    if (niz[L] > niz[R]) return L;
    else return R;
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (int& i : a) cin >> i, --i;
  a.push_back(n - 1);
  segtree st(n);
  st.build(1, 0, n - 1, a);
  vector<ll> dp(n);
  for (int i = n - 2; i >= 0; i--) {
    int j = st.get(1, 0, n - 1, i + 1, a[i], a);
    dp[i] = dp[j] - (a[i] - j) + n - i - 1;
  }
  cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
}