#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int R, N;
int X[100001];
int Y[100001];
int T[100001];

int main() {
  scanf("%d %d", &R, &N);
  T[0] = 0;
  X[0] = Y[0] = 1;
  for (int i = 1; i <= N; ++i) {
    scanf("%d %d %d", T + i, X + i, Y + i);
  }
  vector<int> dp(N + 1, -N);
  dp[0] = 0;
  vector<int> ma(N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      int dt = T[i] - T[j];
      if (dt >= 2 * R) {
        dp[i] = max(dp[i], ma[j] + 1);
        break;
      }
      int dist = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
      if (dist <= dt) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ma[i] = max(dp[i], ma[i - 1]);
  }
  cout << ma[N] << endl;
}