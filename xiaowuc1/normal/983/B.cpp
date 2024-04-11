#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;

int list[5005];

int dp[5005][5005];
int exact[5005][5005];

int solveExact(int l, int r) {
  if(l > r) return 0;
  if(l == r) return list[l];
  if(exact[l][r] >= 0) return exact[l][r];
  int mask = r-l;
  int last = 0;
  while(mask) {
    last = mask;
    mask &= mask-1;
  }
  mask = r-l;
  exact[l][r] = solveExact(l, l+(last^mask)) ^ solveExact(l+last, (l+last)+(last^mask));
  return exact[l][r];
}

int solve(int l, int r) {
  if(dp[l][r] >= 0) return dp[l][r];
  if(l == r) {
    dp[l][r] = list[l];
  }
  else {
    dp[l][r] = solveExact(l, r);
    dp[l][r] = max(dp[l][r], solve(l, r-1));
    dp[l][r] = max(dp[l][r], solve(l+1, r));
  }
  return dp[l][r];
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &list[i]);
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = -1;
      exact[i][j] = -1;
    }
  }
  int qq;
  scanf("%d", &qq);
  while(qq--) {
    int lhs, rhs;
    scanf("%d %d", &lhs, &rhs);
    lhs--;
    rhs--;
    printf("%d\n", solve(lhs, rhs));
  }
}