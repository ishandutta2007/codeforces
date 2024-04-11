#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

long long gcd(long long a, long long b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a+b;
}

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  long long n, res = 0, x, y, z, lcm, c = 50;
  cin >> n;
  for (x=n-c;x<=n;x++)
    for (y=n-c;y<=n;y++)
      for (z=n-c;z<=n;z++) {
        if (x < 1 || y < 1 || z < 1) continue;
        long long lcm = x/gcd(x, y)*y;
        lcm = lcm/gcd(lcm, z)*z;
        if (lcm > res) res = lcm;
      }
  cout << res << endl;
  return 0;
}