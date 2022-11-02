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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int dp[1<<20];

int main()
{
  int n, s[128];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int m;
  cin >> m;

  char op[32][2];
  int team[32];
  for (int i = 0; i < m; ++i) {
    cin >> op[i] >> team[i];
  }

  sort(s, s + n);
  reverse(s, s + n);
  n = min(n, 20);

  dp[(1<<n) - 1] = 0;
  for (int i = (1<<n) - 2; i >= 0; --i) {
    int turn = __builtin_popcount(i);
    dp[i] = (team[turn] == 1 ? -INF : INF);
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        continue;
      }
      int val = dp[i | (1 << j)];
      if (op[turn][0] == 'p') {
        if (team[turn] == 1) {
          val += s[j];
        } else {
          val -= s[j];
        }
      }
      if (team[turn] == 1) {
        chmax(dp[i], val);
      } else {
        chmin(dp[i], val);
      }
    }
  }

  cout << dp[0] << endl;

  return 0;
}