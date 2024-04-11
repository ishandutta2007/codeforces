#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, q, x, y, A[N][N], t, r, c;
pair <int, int> B[N][N];

#define Exit throw;

const int ini = -1e9 - 1;

vector < pair <int, int> > cxt;

void perform(int t, int x) {
  if(t == 1) {
    A[x][m + 1] = A[x][1];
    B[x][m + 1] = B[x][1];
    for(int i = 1; i <= m; ++ i) A[x][i] = A[x][i + 1], B[x][i] = B[x][i + 1];
    return;
  }
  A[n + 1][x] = A[1][x];
  B[n + 1][x] = B[1][x];
  for(int i = 1; i <= n; ++ i) A[i][x] = A[i + 1][x], B[i][x] = B[i + 1][x];
  return;
}

int ans[N][N];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j)
      A[i][j] = ini, B[i][j] = make_pair(i, j);
  }
  for(; q --;) {
    scanf("%d", &t);
    if(t == 3) {
      scanf("%d%d%d", &r, &c, &x);
      if(A[r][c] != x) {
	if(A[r][c] == ini) A[r][c] = x;
	else Exit;
      }
    }
    else {
      scanf("%d", &x);
      cxt.push_back(make_pair(t, x));
      perform(t, x);
    }
  }
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j) {
      if(A[i][j] == ini) {
	ans[B[i][j].first][B[i][j].second] = 123123;
      }
      else ans[B[i][j].first][B[i][j].second] = A[i][j];
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++ j)
      printf("%d ", ans[i][j]);
    puts("");
  }
}