#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

array<int, 3> edges[N];
array<int, 2> ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[i] = {a, -b, i};
  }
  sort(edges, edges + m);

  int k = 1, it1 = 3, it2 = 2;
  for (int i = 0; i < m; ++i) {
    auto [w, t, id] = edges[i];
    if (t == -1) {
      ans[id] = {1, ++k};
    } else {
      if (it1 > k) {
        cout << -1 << "\n";
        exit(0);
      }

      ans[id] = {it2, it1};
      if (++it2 == it1) {
        it2 = 2;
        ++it1;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    for (auto j : ans[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
}