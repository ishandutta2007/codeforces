#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> limit(n);
  for (auto &i : limit) {
    cin >> i;
  }

  int count = 0, ans = 0;
  vector<bool> visited(n);

  for ( ; count < n; ans += (count < n)) {
    for (int i = 0; i < n; ++i) {
      if (!visited[i] && limit[i] <= count) {
        visited[i] = true;
        ++count;
      }
    }
    reverse(visited.begin(), visited.end());
    reverse(limit.begin(), limit.end());
  }

  cout << ans << "\n";
}