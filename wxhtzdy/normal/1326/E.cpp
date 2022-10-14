#include <bits/stdc++.h>

using namespace std;

namespace segtree {
  long long mx[4000005], lzy[4000005];
  void push(int node) {
    mx[node + node] += lzy[node];
    mx[node + node + 1] += lzy[node];
    lzy[node + node] += lzy[node];
    lzy[node + node + 1] += lzy[node];
    lzy[node] = 0;
  }
  void modify(int node, int l, int r, int ll, int rr, int v) {
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      mx[node] += v;
      lzy[node] += v;
      push(node);
      return;  
    }
    push(node);
    int mid = l + r >> 1;
    modify(node + node, l, mid, ll, rr, v);
    modify(node + node + 1, mid + 1, r, ll, rr, v);
    mx[node] = max(mx[node + node], mx[node + node + 1]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  segtree::modify(1, 0, n - 1, 0, pos[n - 1], 1);
  cout << n << " ";
  int ans = n - 1;
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    --q;
    if (i + 1 == n) {
      continue;
    }
    segtree::modify(1, 0, n - 1, 0, q, -1);
    while (ans > 0 && segtree::mx[1] <= 0) {
      ans--;
      segtree::modify(1, 0, n - 1, 0, pos[ans], 1); 
    }
    cout << ans + 1 << " ";
  }                                        
  return 0;
}