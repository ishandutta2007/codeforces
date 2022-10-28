#include <bits/stdc++.h>
using namespace std;

const int OO = 1e5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int& i : a) {
    cin >> i;
  }

  int ans = 0;
  vector<bool> used(n + 1);
  for (int i = 0; i < n; ++i) {
    vector<int> cost(n + 1, -1);
    for (int j = 1; j <= n; ++j) {
      if (used[j]) {
        cost[j] = OO;
      }
    }

    for (int j = 0; j < int(a.size()); ++j) {
      if (cost[a[j]] == -1) {
        cost[a[j]] = j;
      } else {
        cost[a[j]] += j - 1;
      }
    }

    int optimal = min_element(cost.begin() + 1, cost.end()) - cost.begin();
    for (int i = int(a.size()) - 1; i >= 0; --i) {
      if (a[i] == optimal) {
        a.erase(a.begin() + i);
      }
    }
    used[optimal] = true;
    ans += cost[optimal];
  }

  cout << ans << "\n";
}