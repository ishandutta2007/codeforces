#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 12) + 1;
const int Q = (1 << 16);
const int K = 2200000;

map<array<int, 4>, int> id;
array<int, 2> par[K];
int value[N];
int ans[Q];
int m;

int get(int l, int r, int a, int b) {
  for ( ; l <= r && (value[l] < a || value[l] > b); ++l);
  for ( ; l <= r && (value[r] < a || value[r] > b); --r);

  if (l > r) {
    return 0;
  }

  if (id.count({l, r, a, b}) == 0) {
    if (a == b) {
      id[{l, r, a, b}] = l;
    } else {
      int c = (a + b) / 2;
      int u = get(l, r, a, c);
      int v = get(l, r, c + 1, b);
      if (u == 0 || v == 0) {
        id[{l, r, a, b}] = u ^ v;
      } else {
        id[{l, r, a, b}] = ++m;
        par[m] = {u, v};
      }
    }
  }
  return id[{l, r, a, b}];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  m = n;
  for (int i = 1; i <= n; ++i) {
    cin >> value[i];
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    ans[i] = get(l, r, 1, n);
  }

  cout << m << "\n";
  for (int i = n + 1; i <= m; ++i) {
    for (auto j : par[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}