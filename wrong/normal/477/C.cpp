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

int to[2048];
int N, M;
char S[2048], P[512];

int dp[2048][2048], ans[2048];

int main()
{
  scanf("%s%s", S, P);
  N = strlen(S);
  M = strlen(P);

  for (int i = 0; i < N; ++i) {
    int j, ptr = 0;
    for (j = i; j < N && ptr < M; ++j) {
      if (S[j] == P[ptr]) {
        ++ptr;
      }
    }
    to[i] = ptr == M ? j : -1;
  }

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] < INF) {
        chmin(dp[i + 1][j], dp[i][j]);
        if (to[i] != -1) {
          chmin(dp[to[i]][j + 1], dp[i][j] + (to[i] - i - M));
        }
      }
    }
  }

  for (int i = 0; i <= N; ++i) {
    for (int j = dp[N][i]; j <= N; ++j) {
      chmax(ans[j], i);
    }
  }
  for (int i = 0; i <= N; ++i) {
    printf("%d%c", min(ans[i], (N - i) / M), i == N ? '\n' : ' ');
  }

  return 0;
}