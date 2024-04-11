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

const int inf = 1234567;

int n;
long long a[42];
vector <long long> primes;
int f[444];

void go(int t, int v, long long num, vector <int> buckets) {
  if (v == n) {
    int sz = buckets.size();
    int ft = 1;
    for (int i=0;i<sz;i++) ft += f[buckets[i]];
    int other = primes.size(), divs = 0;
    for (int i=0;i<other;i++)
      while (num % primes[i] == 0) {
        num /= primes[i];
        divs++;
      }
    if ((t & (t - 1)) == 0 && divs == 1) divs = 0;
    ft += divs;
    if (ft < f[t]) f[t] = ft;
    return;
  }
  if (t & (1 << v)) {
    if (num % a[v] == 0) {
      vector <int> q = buckets;
      q.push_back(1 << v);
      go(t, v + 1, num / a[v], q);
    }
    vector <int> q = buckets;
    int sz = q.size();
    for (int i=0;i<sz;i++) {
      q[i] += (1 << v);
      go(t, v + 1, num, q);
      q[i] -= (1 << v);
    }
  }
  else go(t, v + 1, num, buckets);
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  primes.clear();
  for (int i=0;i<n;i++) {
    long long x = a[i];
    for (long long j = 2; j * j <= x; j++)
      if (x % j == 0) {
        primes.push_back(j);
        while (x % j == 0) x /= j;
      }
    if (x > 1) primes.push_back(x);
  }
  sort(primes.begin(), primes.end());
  primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
  for (int t=1;t<(1 << n);t++) {
    int first = 0;
    for (int i=0;i<n;i++)
      if (t & (1 << i)) {
        first = i;
        break;
      }
    f[t] = inf;
    vector <int> empty;
    go(t, first + 1, a[first], empty);
  }
  int best = f[(1 << n) - 1];
  int g[444];
  for (int i=0;i<(1 << n);i++) g[i] = inf;
  g[0] = 0;
  for (int i=0;i<(1 << n);i++)
    for (int j=1;j<(1 << n);j++)
      if ((i & j) == 0)
        if (g[i] + f[j] < g[i + j]) g[i + j] = g[i] + f[j];
  int other = g[(1 << n) - 1] + 1;
  if (other < best) best = other;
  printf("%d\n", best);
  return 0;
}