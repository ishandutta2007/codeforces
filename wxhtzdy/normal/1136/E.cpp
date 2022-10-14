/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 17:42:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> k(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> k[i];
  }
  vector<long long> pref(n);
  pref[0] = k[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + k[i];
  }
  set<pair<int, int>> segs;
  for (int i = 0; i < n; i++) {
    segs.emplace(i, i);
  }                        
  const long long inf = 1e18;
  vector<long long> st(8 * n), lzy(8 * n);
  function<void(int, int, int)> push = [&](int v, int l, int r) {
    if (l == r || lzy[v] == -inf) {
      return;
    }
    int mid = l + r >> 1;
    st[v * 2] += lzy[v] * 1LL * (mid - l + 1);
    st[v * 2 + 1] += lzy[v] * 1LL * (r - mid);
    lzy[v * 2] += lzy[v];
    lzy[v * 2 + 1] += lzy[v];
    lzy[v] = 0;
  };
  function<void(int, int, int, int, int, int)> modify = [&](int v, int l, int r, int ll, int rr, int x) {
    if (l > rr || r < ll || l > r || ll > rr) {
      return;
    }
    if (ll <= l && r <= rr) {
      st[v] += x * 1LL * (r - l + 1);
      lzy[v] += x;
      push(v, l, r);
      return;
    }
    push(v, l, r);
    int mid = l + r >> 1;
    modify(v * 2, l, mid, ll, rr, x);
    modify(v * 2 + 1, mid + 1, r, ll, rr, x);
    st[v] = st[v * 2] + st[v * 2 + 1];
  };
  function<long long(int, int, int, int, int)> get = [&](int v, int l, int r, int ll, int rr) {
    push(v, l, r);
    if (l > r || l > rr || r < ll || ll > rr) {
      return 0LL;
    }
    if (ll <= l && r <= rr) {
      return st[v];
    }
    int mid = l + r >> 1;
    long long L = get(v * 2, l, mid, ll, rr);
    long long R = get(v * 2 + 1, mid + 1, r, ll, rr);
    st[v] = st[v * 2] + st[v * 2 + 1];
    return L + R;
  };
  for (int i = 0; i < n; i++) {
    modify(1, 0, n - 1, i, i, a[i]);
  }
  function<void(int, int)> Update = [&](int i, long long x) {
    auto it = prev(segs.lower_bound({i + 1, 0}));
    int l = it->first;
    int r = it->second;
    segs.erase(it);
    if (l < i) {
      segs.emplace(l, i - 1);
    }
    modify(1, 0, n - 1, i, r, x);
    long long me = get(1, 0, n - 1, i, i);
    int border = r;
    while (true) {
      auto it = segs.lower_bound({i + 1, 0});
      if (it == segs.end()) {
        break;
      }
      int L = it->first;
      int R = it->second;
      long long he = get(1, 0, n - 1, L, L);
      long long new_he = me + pref[L - 1] - (i > 0 ? pref[i - 1] : 0LL);
      if (he >= new_he) {
        break;
      }
      segs.erase(it);
      modify(1, 0, n - 1, L, R, new_he - he);
      border = R;
    }
    segs.emplace(i, border);
  };
  int q;
  cin >> q;
  while (q--) {
    char op;
    cin >> op;
    if (op == '+') {
      int i, x;
      cin >> i >> x;
      --i;
      Update(i, x); 
    } else {
      int l, r;
      cin >> l >> r;
      --l; --r;
      cout << get(1, 0, n - 1, l, r) << '\n';
    }
  }
  return 0;
}