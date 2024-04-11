#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

multiset<int64_t> cost_d[N];
int64_t cost_a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<array<int, 3>> arrival;
  vector<array<int, 3>> departure;
  for (int i = 0; i < m; ++i) {
    int d, f, t, c;
    cin >> d >> f >> t >> c;

    if (f == 0) {
      departure.push_back({d, t, c});
      cost_d[t].insert(c);
    } else {
      arrival.push_back({d, f, c});
    }
  }

  sort(departure.rbegin(), departure.rend());
  sort(arrival.rbegin(), arrival.rend());
  fill(cost_a + 1, cost_a + n + 1, 1e13);

  int64_t res = 0;
  for (int i = 1; i <= n; ++i) {
    res += cost_a[i];
    cost_d[i].insert(1e13);
    res += *cost_d[i].begin();
  }
  int64_t ans = res;

  for (int i = -k; i <= 1e6; ++i) {
    while (!departure.empty() && departure.back()[0] <= i + k) {
      auto [d, t, c] = departure.back();
      departure.pop_back();
      res -= *cost_d[t].begin();
      cost_d[t].erase(cost_d[t].find(c));
      res += *cost_d[t].begin();
    }

    while (!arrival.empty() && arrival.back()[0] <= i) {
      auto [d, f, c] = arrival.back();
      arrival.pop_back();
      res -= cost_a[f];
      cost_a[f] = min(cost_a[f], int64_t(c));
      res += cost_a[f];
    }
    ans = min(ans, res);
  }

  cout << (ans < 1e13 ? ans : -1) << "\n";
}