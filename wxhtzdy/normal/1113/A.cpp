#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, v;
  cin >> n >> v;
  int ans = 0, curr = 0;    
  for (int i = 1; i <= n; i++) {
    while (curr < (n - i) && curr < v) {
      curr++;
      ans += i;
    }
    curr--;
  }
  cout << ans << '\n';
  return 0;
}