#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, int> freq;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++freq[a];
  }

  int ans = n;
  for (auto [a, b] : freq) {
    ans = min(ans, n - b);
  }

  cout << ans << "\n";
}