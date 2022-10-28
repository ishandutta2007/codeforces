#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> app(n);
    for (auto &i : app) {
      cin >> i[0];
    }

    for (auto &i : app) {
      cin >> i[1];
    }

    vector<int> ones, twos;
    for (auto [a, b] : app) {
      if (b == 1) {
        ones.push_back(a);
      } else {
        twos.push_back(a);
      }
    }
    sort(ones.rbegin(), ones.rend());
    sort(twos.rbegin(), twos.rend());

    long long memory = accumulate(twos.begin(), twos.end(), 0LL);
    int cost = 2 * twos.size();
    int j = twos.size();
    while (j > 0 && memory - twos[j - 1] >= m) {
      memory -= twos[j - 1];
      cost -= 2;
      --j;
    }

    int ans = (memory >= m) ? cost : INT_MAX;

    for (int i = 0; i < (int) ones.size(); ++i) {
      memory += ones[i];
      ++cost;
      while (j > 0 && memory - twos[j - 1] >= m) {
        memory -= twos[j - 1];
        cost -= 2;
        --j;
      }
      if (memory >= m) {
        ans = min(ans, cost);
      }
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
  }
}