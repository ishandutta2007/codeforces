#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

int n,l,k;
const int SIZE = 810;
double dp[SIZE][201];
int raise = SIZE / 2;

int main(){
  memset(dp, 0, sizeof(dp));
  scanf("%d %d %d", &n, &l, &k);
  vector<int> p;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    p.push_back(v);
  }
  dp[raise + k][0] = 1;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    if (v == -1) {
      for (int j = 0; j < SIZE - 1; ++j) {
    for (int k = i; k >= 0; --k) {
      dp[j][k+1] += dp[j+1][k] * p[i] / 100.0;
      dp[j+1][k] *= (100 - p[i]) / 100.0;
    }
      }
    } else {
      for (int j = SIZE - 1; j >= 0; --j) {
    int next = j + v;
    if (next >= SIZE) next = SIZE - 1;
    for (int k = i; k >= 0; --k) {
      dp[next][k+1] += dp[j][k] * p[i] / 100.0;
      dp[j][k] *= (100 - p[i]) / 100.0;
      //      cout << next << " " << k << " " << dp[next][k+1] << endl;
    }
      }
    }
  }

  double ans = 0;
  for (int i = raise; i < SIZE; ++i) {
    for (int j = l; j <= n; ++j) {
      //      cout << i << " " << j << " " << dp[i][j] << endl;
      ans += dp[i][j];
    }
  }

  printf("%.15f\n", ans);
  return 0;
}