/**
 *    author:  wxhtzdy
 *    created: 13.06.2022 19:52:37
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
    --a[i];
  }
  vector<int> mx(4 * n, -1);
  function<void(int, int, int, int, int, int)> Update = [&](int node, int l, int r, int ll, int rr, int v) {
    if (l > r || l > rr || r < ll) {
      return;
    }
    if (ll <= l && r <= rr) {
      mx[node] = max(mx[node], v);
      return;
    }
    int mid = l + r >> 1;
    Update(node * 2, l, mid, ll, rr, v);
    Update(node * 2 + 1, mid + 1, r, ll, rr, v);
  };
  function<int(int, int, int, int)> Get = [&](int node, int l, int r, int i) {
    if (l == r) {
      return mx[node];
    }
    int mid = l + r >> 1;
    if (i <= mid) {
      return max(mx[node], Get(node * 2, l, mid, i));
    } else {
      return max(mx[node], Get(node * 2 + 1, mid + 1, r, i));
    }
  };
  vector<vector<int>> at(n + 1);
  for (int i = 0; i < n; i++) {
    at[a[i]].push_back(i);  
  }                     
  for (int i = 0; i < n + 1; i++) {
    vector<int> b;
    b.push_back(-1);       
    for (int j : at[i]) {
      b.push_back(j);
    }
    b.push_back(n);
    bool ok = false;
    for (int j = 0; j < (int) b.size() - 1; j++) {
      int L = b[j] + 1;
      int R = b[j + 1] - 1;
      if (L > R) {
        continue;
      }
      if (Get(1, 0, n - 1, L) <= R) {
        ok = true;
      }
      Update(1, 0, n - 1, L, R, R + 1);
    }
    if (!ok) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << n + 2 << '\n';
  return 0;
}