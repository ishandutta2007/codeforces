#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  map<long long, long long> cost;
  while (q--) {
    int t;
    long long u, v;
    cin >> t >> u >> v;
    if (u > v) {
      swap(u, v);
    }

    if (t == 1) {
      int w;
      cin >> w;

      while (__lg(u) < __lg(v)) {
        cost[v] += w;
        v /= 2;
      }

      while (u != v) {
        cost[u] += w;
        cost[v] += w;
        u /= 2;
        v /= 2;
      }
    } else {
      long long ans = 0;
      while (__lg(u) < __lg(v)) {
        ans += cost[v];
        v /= 2;
      }

      while (u != v) {
        ans += cost[u] + cost[v];
        u /= 2;
        v /= 2;
      }

      cout << ans << "\n";
    }
    cerr << "\n";
  }
}