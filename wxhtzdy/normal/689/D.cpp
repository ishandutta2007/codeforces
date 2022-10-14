#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct segtree {
  vector<pair<int, int>> a;
  segtree(int n) {
    a.resize(4 * n);
  }
  void build(int node, int l, int r, vector<int>& L, vector<int>& R) {
    if (l > r) return;
    if (l == r) {
      a[node] = {R[r], L[l]};
      return;
    }
    int mid = l + r >> 1;
    build(node * 2, l, mid, L, R);
    build(node * 2 + 1, mid + 1, r, L, R);
    a[node].first = min(a[node * 2].first, a[node * 2 + 1].first);
    a[node].second = max(a[node * 2].second, a[node * 2 + 1].second);
  }
  pair<int, int> get(int node, int l, int r, int ll, int rr) {
    if (l > r || l > rr || r < ll) return {1e9, -1e9};
    if (ll <= l && r <= rr) return a[node];
    int mid = l + r >> 1;
    auto L = get(node * 2, l, mid, ll, rr);
    auto R = get(node * 2 + 1, mid + 1, r, ll, rr);
    pair<int, int> ret;
    ret.first = min(L.first, R.first);
    ret.second = max(L.second, R.second);
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& i : a) cin >> i;

  vector<int> b(n);
  for (int& i : b) cin >> i;

  segtree st(n);
  st.build(1, 0, n - 1, a, b);

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int bot = i, top = n - 1 , L = i;

    while (bot <= top) {
      int mid = bot + top >> 1;
      pair<int, int> x = st.get(1, 0, n - 1, i, mid);
      if (x.second - x.first < 0) {
        bot = mid + 1;
      } else {
        if (x.first == x.second) L = mid;
        top = mid - 1;
      }
    }

    int R = i - 1;
    bot = i, top = n - 1;

    while (bot <= top) {
      int mid = bot + top >> 1;
      pair<int, int> x = st.get(1, 0, n - 1, i, mid);
      if (x.second - x.first <= 0) {
        if (x.first == x.second) R = mid;
        bot = mid + 1;
      } else {
        top = mid - 1;
      }
    }

    ans += R - L + 1;
  }
  cout << ans << '\n';
}