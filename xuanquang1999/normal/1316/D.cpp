#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dName[4] = {'U', 'R', 'D', 'L'};

int n, cnt, destX[MAXN][MAXN], destY[MAXN][MAXN], id[MAXN][MAXN];
char ans[MAXN][MAXN];
vector<pair<int, int>> start;

bool inBoard(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= n;
}

void dfs(int x, int y, int val) {
  id[x][y] = -2;

  for(int dir = 0; dir < 4; ++dir) {
    int u = x + dx[dir], v = y + dy[dir];
    if (inBoard(u, v) && id[u][v] == val) {
      ans[u-1][v-1] = dName[(dir+2)%4];
      dfs(u, v, val);
    }
  }
}

bool solve() {
  for(int x = 1; x <= n; ++x) {
    for(int y = 1; y <= n; ++y) {
      if (destX[x][y] == -1)
        id[x][y] = -1;
      else if (destX[x][y] == x && destY[x][y] == y) {
        id[x][y] = start.size();
        start.push_back({x, y});
      } else
        id[x][y] = -2;
    }
  }

  for(int x = 1; x <= n; ++x) {
    for(int y = 1; y <= n; ++y) {
      if (destX[x][y] != -1) {
        int u = destX[x][y], v = destY[x][y];
        if (destX[u][v] != u || destY[u][v] != v)
        // if (id[u][v] <= -1)
          return false;
        id[x][y] = id[u][v];
      }
    }
  }

  // for(int x = 1; x <= n; ++x) {
  //   for(int y = 1; y <= n; ++y)
  //     printf("%d ", id[x][y]);
  //   puts("");
  // }
  
  for(int x = 0; x < n; ++x) 
    for(int y = 0; y < n; ++y)
      ans[x][y] = '?';  

  for(int x = 1; x <= n; ++x) {
    for(int y = 1; y <= n; ++y) {
      if (id[x][y] == -1) {
        id[x][y] = -2;

        for(int dir = 0; dir < 4; ++dir) {
          int u = x + dx[dir], v = y + dy[dir];
          if (inBoard(u, v) && id[u][v] == -1) {
            dfs(u, v, -1);
            ans[u-1][v-1] = dName[(dir+2)%4];
            ans[x-1][y-1] = dName[dir];
          }          
        }
      }
    }
  }

  for(int i = 0; i < start.size(); ++i) {
    int x = start[i].first, y = start[i].second;
    dfs(x, y, i);
    ans[x-1][y-1] = 'X';
  }

  // for(int x = 0; x < n; ++x)
  //   printf("%s\n", ans[x]);

  for(int x = 0; x < n; ++x)
    for(int y = 0; y < n; ++y)
      if (ans[x][y] == '?')
        return false;
  return true;
}

int main() {
  scanf("%d", &n);
  for(int x = 1; x <= n; ++x) 
    for(int y = 1; y <= n; ++y) 
      scanf("%d%d", &destX[x][y], &destY[x][y]);

  if (!solve()) 
    puts("INVALID");
  else {
    puts("VALID");
    for(int x = 0; x < n; ++x)
      printf("%s\n", ans[x]);
  }
  
  return 0;
}