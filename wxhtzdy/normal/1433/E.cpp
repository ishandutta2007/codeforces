#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = 1;
  for (int i = 1; i < n; i++) ans *= i;
  ans *= 2;
  ans /= n;
  cout << ans << '\n';
  return 0;
}