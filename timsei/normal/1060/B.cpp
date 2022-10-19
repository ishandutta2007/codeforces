#include <bits/stdc++.h>
using namespace std;

const int N = 15;

#define int long long

int dp[N][2], n, m, x, y;

int bc(int x) {
  int res = 0;
  while(x) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

int bit(int x) {
  int res = 0;
  while(x) {
    res ++;
    x /= 10;
  }
  return res;
}

main() {
  cin >> n;
  if(n == 0) {
    puts("0");
    return 0;
  }
  int ans = bc(n);
  //cerr << ans << endl;
  int now = bit(n) - 1;
  ans += now * 9;
  int it = n;
  while(it % 10 == 9 && it != 9) ans -= 9, it /= 10;
  cout << ans << endl;
}