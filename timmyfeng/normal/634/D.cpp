#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int d, n, m;
  cin >> d >> n >> m;

  vector<array<int, 2>> station(m);
  for (auto &[x, p] : station) {
    cin >> x >> p;
  }
  sort(station.begin(), station.end());
  station.push_back({d, 0});

  long long ans = 0;
  map<int, int> tank;
  tank[0] = n;
  int prv = 0;

  for (auto [x, p] : station) {
    int dist = x - prv;
    if (dist > n) {
      cout << -1 << "\n";
      exit(0);
    }

    while (dist > 0) {
      assert(!tank.empty());
      auto [cost, count] = *tank.begin();
      if (count <= dist) {
        ans += (long long) count * cost;
        tank.erase(tank.begin());
        dist -= count;
      } else {
        ans += (long long) dist * cost;
        tank[cost] -= dist;
        dist = 0;
      }
    }

    int fill = x - prv;
    while (!tank.empty()) {
      auto [cost, count] = *(--tank.end());
      if (cost < p) {
        break;
      }
      tank.erase(--tank.end());
      fill += count;
    }

    tank[p] = fill;
    prv = x;

    int sum = 0;
    for (auto [a, b] : tank) {
      sum += b;
    }
  }

  cout << ans << "\n";
}