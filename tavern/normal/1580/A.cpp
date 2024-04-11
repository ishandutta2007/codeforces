#include <bits/stdc++.h>

using namespace std;

const int maxn = 405;

int n, m;
int f[maxn];
int row[maxn][maxn], col[maxn][maxn], sum[maxn][maxn];
char s[maxn][maxn];

inline int calc(int x_1, int y_1, int x_2, int y_2){
  int ret = sum[x_2][y_2];
  if(x_1)
    ret -= sum[x_1 - 1][y_2];
  if(y_1)
    ret -= sum[x_2][y_1 - 1];
  if(x_1 && y_1)
    ret += sum[x_1 - 1][y_1 - 1];
  return ret;
}

inline void solve(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
      row[i][j] = (j ? row[i][j - 1] : 0) + (s[i][j] == '0');
      col[i][j] = (i ? col[i - 1][j] : 0) + (s[i][j] == '0');
    }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      sum[i][j] = (s[i][j] == '1');
      if(i)
	sum[i][j] += sum[i - 1][j];
      if(j)
	sum[i][j] += sum[i][j - 1];
      if(i && j)
	sum[i][j] -= sum[i - 1][j - 1];
    }
  }

  int ans = 0x3f3f3f3f;
  
  for(int l = 0; l < m; ++l){
    for(int r = l + 3; r < m; ++r){
      for(int i = 0; i < n; ++i){
	int res = row[i][r - 1] - row[i][l] - col[i][l] - col[i][r] - calc(0, l + 1, i, r - 1);
	f[i] = min(i ? f[i - 1] : 0x3f3f3f3f, res);
      }
      for(int i = 4; i < n; ++i){
	int res = row[i][r - 1] - row[i][l] + col[i - 1][l] + col[i - 1][r] + calc(0, l + 1, i - 1, r - 1);
	ans = min(ans, res + f[i - 4]);
      }
    }
  }

  printf("%d\n", ans);
  return;
}

int main(){
  //freopen("A.in", "r", stdin);

  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}