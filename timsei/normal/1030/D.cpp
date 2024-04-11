#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, m, k;

LL gcd(LL x, LL y) {
  return (!y) ? x : gcd(y, x % y);
}

main() {
  cin >> n >> m >> k;
  if(n * m * 2 % k != 0) {
    puts("No");
    return 0;
  }
  LL nn = n, mm = m;
  LL A = gcd(n, k);
  nn /= A, k /= A;
  LL B = gcd(m, k);
  mm /= B, k /= B;
  if(k == 1) k = 2; else k = 1;
  if(nn * k <= n) nn *= k;
  else mm *= k;
  puts("Yes");
  cout << "0 0" << endl;
  cout << nn <<" " << 0 << endl;
  cout << 0 <<" " << mm << endl;
}