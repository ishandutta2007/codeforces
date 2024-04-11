#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;
int n, m, k;
const int N = 505;
int ry[] = {0, 0, -1, 1};
int rx[] = {1, -1, 0, 0};
int vis[N][N];
int freee[N][N];
int dfs(int y, int x) {
  vis[y][x] = 1;
  int acc = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + ry[i];
    int nx = x + rx[i];
    if (ny >= 1 && ny <= n && nx >= 1 && nx <= m && freee[ny][nx] && !vis[ny][nx]) {
      acc += dfs(ny, nx);
    }
  }
  if (acc == 1 && k) {
    freee[y][x] = 2;
    acc = 0;
    k--;
  }
  return acc;
}


int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cin>>n>>m>>k;
  int sy, sx;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin>>c;
      freee[i][j] = (c == '.');
      if (freee[i][j]) {
        sy = i;
        sx = j;
      }
    }
  }
  dfs(sy, sx);
      
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (freee[i][j] == 2) {
        cout<<"X";
      } else if (freee[i][j] == 1) {
        cout<<".";
      } else {
        cout<<"#";
      }
    }
    cout<<endl;
  }
  
  
  
  // nie zapomnij o ll
  return 0;
}