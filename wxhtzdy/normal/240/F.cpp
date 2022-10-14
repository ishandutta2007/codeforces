#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;
 
const int N = 1e5 + 5;
 
struct segtree {
  vector<int> st, lzy;
  segtree() {
    st.resize(4 * N);
    lzy.resize(4 * N);
  }
  void push(int node, int l, int r) {
    if (lzy[node] == 0) return;
    if (lzy[node] == -1) {
      st[node] = 0;
    } else {
      st[node] = r - l + 1;
    }
    if (l != r) {
      lzy[node * 2] = lzy[node];
      lzy[node * 2 + 1] = lzy[node];
    }
    lzy[node] = 0;
  }
  void update(int node, int l, int r, int ll, int rr, int val) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      lzy[node] = val;
      push(node, l, r);
      return;
    }
    int mid = l + r >> 1;
    update(node * 2, l, mid, ll, rr, val);
    update(node * 2 + 1, mid + 1, r, ll, rr, val);
    st[node] = st[node * 2] + st[node * 2 + 1];
  }
  int get(int node, int l, int r, int ll, int rr) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return 0;
    if (ll <= l && r <= rr) return st[node];
    int mid = l + r >> 1;
    return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
  }
} st[26];
 
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  ios::sync_with_stdio(!cin.tie(0));
 
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int c = (int) (s[i] - 'a');
    st[c].update(1, 0, n - 1, i, i, 1);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int sz = r - l + 1;
    vector<int> cnt(26);
    for (int i = 0; i < 26; i++) {
      cnt[i] = st[i].get(1, 0, n - 1, l, r);
    }
    int kol = 0;
    for (int i = 0; i < 26; i++) kol += (cnt[i] % 2);
    if (kol != sz % 2) {
      continue;
    }
    for (int i = 0; i < 26; i++) {
      st[i].update(1, 0, n - 1, l, r, -1);
    }
    for (int i = 0; i < 26; i++) {
      int x = cnt[i] - cnt[i] % 2;
      if (x == 0) {
        continue;
      }
      int y = x / 2;
      st[i].update(1, 0, n - 1, l, l + y - 1, 1);
      l += y;
      st[i].update(1, 0, n - 1, r - y + 1, r, 1);
      r -= y;
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) {
        st[i].update(1, 0, n - 1, l, l, 1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (st[j].get(1, 0, n - 1, i, i) == 1) {
        cout << (char) (j + 'a');
        break;
      }
    }
  }
  cout << '\n';
}