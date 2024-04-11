#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

long long st[4 * MAX];
long long lzy[4 * MAX];

void push(int node, int l, int r) {
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  st[node * 2] += lzy[node] * 1LL * (mid - l + 1);
  st[node * 2 + 1] += lzy[node] * 1LL * (r - mid);
  lzy[node * 2] += lzy[node];
  lzy[node * 2 + 1] += lzy[node];
  lzy[node] = 0;
}

void modify(int node, int l, int r, int ll, int rr, int x) {
  if (l > r || l > rr || r < ll) {
    return;
  }
  if (ll <= l && r <= rr) {
    st[node] += x * 1LL * (r - l + 1);
    lzy[node] += x;
    push(node, l, r);
    return;
  }
  push(node, l, r);
  int mid = l + r >> 1;
  modify(node * 2, l, mid, ll, rr, x);
  modify(node * 2 + 1, mid + 1, r, ll, rr, x);
  st[node] = st[node * 2] + st[node * 2 + 1];
}

long long get(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) {
    return 0;
  }
  if (ll <= l && r <= rr) {
    return st[node];
  }
  push(node, l, r);
  int mid = l + r >> 1;
  return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[i] = i; 
  }
  mp[n + 1] = n + 1;
  function<void(int)> Cut = [&](int x) {
    if (mp.find(x) == mp.end()) {
      auto it = prev(mp.lower_bound(x));
      mp[x] = it->second;
    }
  };
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      ++r;
      Cut(l);
      Cut(r);
      auto it = mp.find(l);
      while (it->first < r) {
        int L = it->first;
        int R = next(it)->first;
        int old_color = it->second;
        int d = abs(old_color - x);
        modify(1, 1, n, L, R - 1, d);
        it = mp.erase(it);
      }
      mp[l] = x;
    } else {
      int l, r;
      cin >> l >> r;
      cout << get(1, 1, n, l, r) << '\n';
    }
  }                                                                    
  return 0;
}