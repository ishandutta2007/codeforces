#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;

const int maxm = 2005;
const int maxn = 2005;
const int INF = 1e9 + 7;

int n, m, d;
int dp[maxn][maxm][3];
char s[maxn], t[maxn];

int main(){
  scanf("%d%d", &m, &d);
  scanf("%s%s", s, t);
  n = strlen(s);
  FOR(i, 0, n)
    s[i] -= '0';
  FOR(i, 0, n)
    t[i] -= '0';
  int i = 0, rem = 0;
  for(; i < n && s[i] == t[i]; ++i){
    if((!(i & 1)) + (s[i] == d) != 1){
      puts("0");
      return 0;
    }
    ((rem *= 10) += s[i]) %= m;
  }
  if(i == n){
    puts((rem == 0) ? "1" : "0");
    return 0;
  }
  REP(x, s[i], t[i]) if((!(i & 1)) + (x == d) == 1){
    dp[i + 1][(rem * 10 + x) % m][(x == s[i] ? 0 : (x == t[i] ? 2 : 1))] += 1;
  }
  for(++i; i < n; ++i) FOR(j, 0, m){
      /*    if(dp[i][j][0])
      printf("i = %d j = %d 0 dp = %d\n", i, j, dp[i][j][0]);
    if(dp[i][j][1])
      printf("i = %d j = %d 1 dp = %d\n", i, j, dp[i][j][1]);
    if(dp[i][j][2])
      printf("i = %d j = %d 2 dp = %d\n", i, j, dp[i][j][2]);
      */
    FOR(x, s[i], 10) if((!(i & 1)) + (x == d) == 1){
      (dp[i + 1][(j * 10 + x) % m][x == s[i] ? 0 : 1] += dp[i][j][0]) %= INF;
    }
    FOR(x, 0, 10) if((!(i & 1)) + (x == d) == 1){
      (dp[i + 1][(j * 10 + x) % m][1] += dp[i][j][1]) %= INF;
    }
    REP(x, 0, t[i]) if((!(i & 1)) + (x == d) == 1){
      (dp[i + 1][(j * 10 + x) % m][x == t[i] ? 2 : 1] += dp[i][j][2]) %= INF;
    }
  }
  printf("%d\n", ((dp[n][0][0] + dp[n][0][1]) % INF + dp[n][0][2]) % INF);
  return 0;
}