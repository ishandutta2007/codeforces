/**                       
 *    author:  milos
 *    created: 03.09.2021 16:53:03       
**/
#include <bits/stdc++.h>
 
using namespace std;

const int N = 6e5;
const int M = 4 * N;

pair<int, int> st[M], lzy[M];

void push(int x, int l, int r) {
  st[x] = max(st[x], lzy[x]);
  if (l != r) {
    lzy[x + x] = max(lzy[x + x], lzy[x]);
    lzy[x + x + 1] = max(lzy[x + x + 1], lzy[x]);
  }
}

void modify(int x, int l, int r, int ll, int rr, pair<int, int> val) {
  push(x, l, r);
  if (l > r || l > rr || r < ll) return;
  if (ll <= l && r <= rr) {
    lzy[x] = max(lzy[x], val);
    push(x, l, r);
    return;
  }
  int mid = l + r >> 1;
  modify(x + x, l, mid, ll, rr, val);
  modify(x + x + 1, mid + 1, r, ll, rr, val);
  st[x] = max(st[x + x], st[x + x + 1]);
}

pair<int, int> get(int x, int l, int r, int ll, int rr) {
  push(x, l, r);
  if (l > r || l > rr || r < ll) return {0, 0};
  if (ll <= l && r <= rr) return st[x];
  int mid = l + r >> 1;
  return max(get(x + x, l, mid, ll, rr), get(x + x + 1, mid + 1, r, ll, rr));
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;                                      
  vector<vector<pair<int, int>>> segs(n + 1);
  vector<int> xs;
  for (int i = 0; i < m; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    segs[x].push_back({l, r});
    xs.push_back(l);
    xs.push_back(r);                        
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  auto Get = [&](int x) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;   
  };
  for (int i = 1; i <= n; i++) {
    for (auto &seg : segs[i]) {
      seg.first = Get(seg.first);
      seg.second = Get(seg.second);
    }
  }
  vector<int> lst(n + 1);
  for (int i = 1; i <= n; i++) {
    pair<int, int> mx = make_pair(0, 0);
    for (auto seg : segs[i]) {
      mx = max(mx, get(1, 1, xs.size(), seg.first, seg.second));
    }
    lst[i] = mx.second;
    for (auto seg : segs[i]) {
      modify(1, 1, xs.size(), seg.first, seg.second, make_pair(mx.first + 1, i));
    }
  }
  auto mx = get(1, 1, xs.size(), 1, xs.size());
  cout << n - mx.first << '\n';
  vector<bool> take(n + 1, false);
  int ind = mx.second;
  while (ind != 0) {
    take[ind] = true;
    ind = lst[ind];
  }
  for (int i = 1; i <= n; i++) {
    if (!take[i]) {
      cout << i << " ";
    }
  }
  return 0;
}