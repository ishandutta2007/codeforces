#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    vector<int> t(n);
    for (auto &i : t) {
      cin >> i;
    }
    sort(t.begin(), t.end());

    int max_t = t.back() + n;
    vector<int> cost(max_t + 1);
    for (auto i : t) {
      int prefix = cost[0];
      for (int j = 1; j <= max_t; ++j) {
        int res = prefix == INT_MAX ? INT_MAX : prefix + abs(i - j);
        prefix = min(prefix, cost[j]);
        cost[j] = res;
      }
      cost[0] = INT_MAX;
    }

    cout << *min_element(cost.begin(), cost.end()) << "\n";
  }
}