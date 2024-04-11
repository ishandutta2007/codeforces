#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

long long a[424242];

long long gcd(long long a, long long b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

void update(long long &a, long long &b, long long c, long long d) {
  if (b < d) {
    long long tmp;
    tmp = a; a = c; c = tmp;
    tmp = b; b = d; d = tmp;
  }
  while (a % d != c) a += b;
  b *= d;
}

int main() {
  long long n, m;
  int k;
  cin >> n >> m >> k;
  for (int i=0;i<k;i++) {
    a[i] = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
      a[i] = a[i] * 10 + ch - 48;
      ch = getchar();
    }
  }
  long long lcm = 1;
  for (int i=0;i<k;i++) {
    long long g = gcd(lcm, a[i]);
    lcm /= g;
    if (1.0 * lcm * a[i] > 1e15) {
      puts("NO");
      return 0;
    }
    lcm *= a[i];
  }
  if (lcm > n) {
    puts("NO");
    return 0;
  }
  long long x = lcm;
  vector < pair <long long, int> > primes;
  for (long long j = 2; j * j <= x; j++)
    if (x % j == 0) {
      int cnt = 0;
      while (x % j == 0) {
        x /= j;
        cnt++;
      }
      primes.push_back(make_pair(j, cnt));
    }
  if (x > 1) primes.push_back(make_pair(x, 1));
  int sz = primes.size();
  vector <long long> power, rem;
  for (int i=0;i<sz;i++) {
    power.push_back(1);
    int cnt = primes[i].second;
    for (int j=0;j<cnt;j++) power[i] *= primes[i].first;
    for (int j=0;j<k;j++)
      if (a[j] % power[i] == 0) {
        long long z = (-j) % power[i];
        if (z < 0) z += power[i];
        rem.push_back(z);
        break;
      }
  }
  long long num = 0, den = 1;
  for (int i=0;i<sz;i++) {
    update(num, den, rem[i], power[i]);
  }
  if (num == 0) num += den;
  if (num + k - 1 > m) puts("NO"); else {
    for (int i=0;i<k;i++)
      if (gcd(lcm, num + i) != a[i]) {
        puts("NO");
        return 0;
      }
    puts("YES");
  }
  return 0;
}