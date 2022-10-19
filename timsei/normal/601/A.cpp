#include <bits/stdc++.h>
using namespace std;

const int N = 405;
const int M = N * N * N;

int n, m, way[N][N], x, y;

int dp[N][N][2];

typedef pair <int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector < pii > T[N * 2][2];

int main() {
  cin >> n >> m;
  for(int i = 1; i <= m; ++ i) cin >> x >> y, way[x][y] = way[y][x] = 1;
  memset(dp, -1, sizeof(dp));
  T[0][0].push_back(mp(1, 1));
  dp[1][1][0] = 0;
  for(int i = 0; T[i][0].size(); ++ i) {
    for(int j = 0; j < (int) T[i][0].size(); ++ j) {
      int now = T[i][0][j].first;
      for(int k = 1; k <= n; ++ k)
	if((((now != k) || (k == n)) && way[now][k]) || (now == n)) {
	  if(dp[k][T[i][0][j].second][1] == -1) {
	    T[i][1].push_back(mp(k, T[i][0][j].second));
	    dp[k][T[i][0][j].second][1] = i;
	  }
	}
    }
    for(int j = 0; j < (int) T[i][1].size(); ++ j) {
      int now = T[i][1][j].second;
      for(int k = 1; k <= n; ++ k)
	if((way[now][k] == 0 && ((k != T[i][1][j].first && k != now) || k == n)) || now == n) {
	  if(dp[T[i][1][j].first][k][0] == -1) {
	    T[i + 1][0].push_back(mp(T[i][1][j].first, k));
	    dp[T[i][1][j].first][k][0] = i + 1;
	  }
	}
    }
  }
  cout << dp[n][n][0] << endl;
}