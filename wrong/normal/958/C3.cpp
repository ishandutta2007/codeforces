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
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

// struct BIT {
//   int N;
//   vector<int> B;
//   BIT(int n) : N(n), B(n, INF) { }
//   void update(int x, int v) {
//     for (; x <= N; x += x & -x) chmin(B[x], v);
//   }
//   int mini(int x) {
//     int r = INF;
//     for (; x > 0; x -= x & -x) chmin(r, B[x]);
//     return r;
//   }
// };

int N, K, P, A[500005], S[500005], nxt[500005][101];
vector<int> pos[101];

int dp[101][10001];

int main() {
  N = in();
  K = in();
  P = in();
  int s = 0;
  for (int i = 0; i < N; ++i) {
    A[i] = in() % P;
    S[i] = ((s += A[i]) %= P);
    pos[s].push_back(i);
  }

  vector<int> nx(P, INF);
  for (int i = 0; i < P; ++i) {
    pos[i].push_back(INF);
    nx[i] = pos[i][0];
  }

  s = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < P; ++j) {
      nxt[i][(j - s + P) % P] = nx[j];
    }
    (s += A[i]) %= P;
    nx[s] = *upper_bound(pos[s].begin(), pos[s].end(), i);
  }

  for (int i = 0; i <= 100; ++i) {
    fill(dp[i], dp[i] + 10001, INF);
  }

  dp[0][0] = 0;
  for (int k = 0; k + 1 < K; ++k) {
    for (int x = 0; x < K * P; ++x) {
      if (dp[k][x] >= N) continue;
      const int f = dp[k][x];
      for (int p = 0; p < P; ++p) {
        if (nxt[f][p] == INF) continue;
        chmin(dp[k + 1][x + p], nxt[f][p] + 1); 
      }
    }
  }

  int res = INF;
  for (int x = 0; x < K * P; ++x) {
    if (dp[K - 1][x] >= N) continue;
    int v = dp[K - 1][x];
    int t = (S[N - 1] - S[v - 1] + P) % P;
    chmin(res, x + t);
  }

  printf("%d\n", res);

  return 0;
}