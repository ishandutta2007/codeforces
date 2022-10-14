/**
 *    author:  wxhtzdy
 *    created: 01.02.2022 14:13:53
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int st[4 * N];

void modify(int node, int l, int r, int ll, int rr, int x) {
  if (l > r || l > rr || r < ll) {
    return;
  }
  if (ll <= l && r <= rr) {
    st[node] += x;
    return;
  }
  int mid = l + r >> 1;
  modify(node + node, l, mid, ll, rr, x);
  modify(node + node + 1, mid + 1, r, ll, rr, x);   
}

int get(int node, int l, int r, int x) {
  if (l == r) {
    return st[node];
  }
  int mid = l + r >> 1;
  if (x <= mid) {
    return st[node] + get(node + node, l, mid, x);
  } else {
    return st[node] + get(node + node + 1, mid + 1, r, x);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = i - a[i] + 1;
  }
  vector<vector<pair<int, int>>> qs(n);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    int l = x;
    int r = n - y - 1;
    qs[r].emplace_back(l, i);
  }
  vector<int> ans(q);
  for (int i = 0; i < n; i++) {
    int low = 0, high = i, pos = -1;
    while (low <= high) {
      int mid = low + high >> 1;
      if (get(1, 0, n - 1, mid) >= a[i]) {
        pos = mid;
        low = mid + 1;  
      } else {
        high = mid - 1;
      }
    }
    if (a[i] >= 0 && pos != -1) {
      modify(1, 0, n - 1, 0, pos, 1);
    }
    for (auto x : qs[i]) {
      ans[x.second] = get(1, 0, n - 1, x.first);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }              
  return 0;
}