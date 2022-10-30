#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int INF = 1001001001;

char F[1024];
int S[1024];
int dp[1024][2];
int n, m, x, y;

int solve(int c, int col)
{
  if(dp[c][col] != INF) {
    return dp[c][col];
  }

  if(c == m+1) {
    return 0;
  }

  int& res = dp[c][col];
  int cost = 0;

  for(int p=c; p<c+x; ++p) {
    if(col == 0) {
      cost += S[p];
    } else {
      cost += n - S[p];
    }
  }

  for(int nxt = c+x; nxt <= m+1 && nxt <= c+y; ++nxt) {
    res = min(res, solve(nxt, 1-col) + cost);

    if(col == 0) {
      cost += S[nxt];
    } else {
      cost += n - S[nxt];
    }
  }

  return res;
}

int main()
{
  while(~scanf("%d%d%d%d", &n, &m, &x, &y)) {
    memset(S, 0, sizeof(S));

    for(int i=0; i<n; ++i) {
      scanf("%s", F);

      for(int j=0; j<m; ++j) {
        if(F[j] == '#') {
          S[j+1]++;
        }
      }
    }

    for(int i=0; i<=m+1; ++i) {
      dp[i][0] = dp[i][1] = INF;
    }

    int res = min(solve(1, 0), solve(1, 1));
    printf("%d\n", res);
  }

  return 0;
}