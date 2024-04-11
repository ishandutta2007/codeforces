/**
 *    author:  wxhtzdy
 *    created: 24.01.2022 14:51:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, q;
  cin >> n >> q;       
  vector<vector<int>> qs(4 * n);
  function<void(int, int, int, int, int, int)> Update = [&](int node, int l, int r, int ll, int rr, int x) {
    if (l > r || l > rr || r < ll) {
      return;
    }
    if (ll <= l && r <= rr) {
      qs[node].push_back(x);
      return;
    }
    int mid = l + r >> 1;
    Update(node * 2, l, mid, ll, rr, x);
    Update(node * 2 + 1, mid + 1, r, ll, rr, x);
  };
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    --l; --r;
    Update(1, 0, n - 1, l, r, x);
  }                                                                    
  const int N = 10005;
  typedef bitset<N> state;
  state ans;
  function<void(int, int, int, state)> Solve = [&](int node, int l, int r, state st) {
    for (int x : qs[node]) {
      st |= (st << x);
    }
    if (l == r) {
      ans |= st;
      return;  
    }
    int mid = l + r >> 1;
    Solve(node * 2, l, mid, st);
    Solve(node * 2 + 1, mid + 1, r, st);
  };
  state a;
  a.set(0);
  Solve(1, 0, n - 1, a);
  vector<int> b;            
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 1) {
      b.push_back(i);
    }
  }
  cout << b.size() << '\n';
  for (int i = 0; i < (int) b.size(); i++) {
    cout << b[i] << " ";
  }
  cout << '\n';
  return 0;
}