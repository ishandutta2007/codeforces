#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int dis[N][N], n, m, x, y;

bool can[N][N];

queue < pair <int, int> > q;

void BFS(int x, int y) {
  q.push(make_pair(x, y));
  while(!q.empty()) {
    pair <int, int> ind = q.front();
    q.pop();
    int x = ind.first, y = ind.second;
    for(int i = -1; i <= 1; ++ i) {
      for(int j = -1; j <= 1; ++ j) {
	if(x + i <= n && x + i >= 0 && y + j <= n && y + j >= 0) {
	  if(!dis[x + i][y + j] && can[x + i][y + j]) {
	    dis[x + i][y + j] = 1;
	    q.push(make_pair(x + i, y + j));
	  }
	}
      }
    }
  }
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) can[i][j] = 1;
  }
  cin >> x >> y;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      if(i == x || j == y || abs(i - x) == abs(j - y)) {
	can[i][j] = 0;
      }
    }
  }
  cin >> x >> y;
  dis[x][y] = 1;
  BFS(x, y);
  cin >> x >> y;
  if(dis[x][y]) puts("YES");
  else puts("NO");
}