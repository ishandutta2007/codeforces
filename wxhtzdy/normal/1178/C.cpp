#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

long long mypow(long long n) {
  long long res = 1;
  while (n > 0) {
    res *= 2;  
    res %= md;
    n--;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  long long h, w;
  cin >> h >> w;
  long long k = h + w;
  long long ans = mypow(k);
  cout << ans << '\n';
  return 0;
}