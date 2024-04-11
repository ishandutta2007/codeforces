#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> ans;
  vector<bool> sieve(n + 1);
  for (int i = 2; i <= n; ++i) {
    if (!sieve[i]) {
      for (int j = i; j <= n; j *= i) {
        ans.push_back(j);
      }
      for (int j = 2 * i; j <= n; j += i) {
        sieve[j] = true;
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}