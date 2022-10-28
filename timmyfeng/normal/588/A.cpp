#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int mini = INT_MAX, ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, p;
    cin >> a >> p;
    mini = min(mini, p);
    ans += a * mini;
  }

  cout << ans << "\n";
}