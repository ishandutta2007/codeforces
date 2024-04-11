#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

Int F[100050], dp[100050];

int main()
{
  int n = in();
  for (int i = 0; i < n; ++i) {
    ++F[in()];
  }

  dp[0] = 0;
  dp[1] = F[1];
  for (int i = 2; i <= 100000; ++i) {
    dp[i] = max(i * F[i] + dp[i - 2], dp[i - 1]);
  }

  cout << dp[100000] << endl;

  return 0;
}