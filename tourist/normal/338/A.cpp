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

const long long md = 1000000009;

long long pw(long long a, long long b) {
  long long x = 1, step = 1LL << 60;
  while (step > 0) {
    x = x * x % md;
    if (step & b) x = x * a % md;
    step >>= 1;
  }
  return x;
}

int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long ll = 0, rr = m / k;
  while (ll < rr) {
    long long mid = (ll + rr) >> 1;
    long long N = n - mid * k;
    long long M = m - mid * k;
    if (N - N / k >= M) rr = mid;
    else ll = mid + 1;
  }
  long long p = ll;
  long long ans = m - p * k;
  long long u = (pw(2, p + 1) + md - 2) % md;
  ans = (ans + k * u) % md;
  cout << ans << endl;
  return 0;
}