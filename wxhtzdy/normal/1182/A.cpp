#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 2 != 0) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = 1;
  for (int i = 0; i < n / 4; i++) {
    ans *= 4;
  }             
  if (n % 4 == 2) {
    ans *= 2;
  }
  cout << ans << '\n'; 
  return 0;
}