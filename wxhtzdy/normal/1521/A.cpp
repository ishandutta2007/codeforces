#include <bits/stdc++.h>
 
using namespace std;
 
void run_case() {
  long long a, b;
  cin >> a >> b;
  if (b > 2) cout << "YES\n" << a * (b - 1) << ' ' << a << ' ' << a * b << '\n';
  else if(b == 1) cout << "NO" << '\n';
  else cout << "YES\n" << a << ' ' << a*3 << ' ' << a*4 << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    run_case();
  }
  return 0;
}