#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int f[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
int a[1005][1005][4];
bool b[1005][1005][4];
char c[1005][1005];
int n, m;
queue<int> q[4];
int main()
{
  cin >> n >> m;scanf("\n");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++) scanf("%c", &c[i][j]);
    scanf("\n");
  }
  c[n][m+1] = '.';
  q[0].push(n);
  q[1].push(m+1);
  q[2].push(2);
  q[3].push(0);
  int ans = 1000001;
  while (!q[0].empty())
  {
    int x = q[0].front();
    int y = q[1].front();
    int d = q[2].front();
    int v = q[3].front();
    q[0].pop();
    q[1].pop();
    q[2].pop();
    q[3].pop();
    for (int i = 0; i != 4; i++)
    if (i != d && c[x][y] != '#') continue;
    else
    {
      int xx = x+f[i][0];
      int yy = y+f[i][1];
      int nv;
      if (i == d) nv = v;else nv = v+1;
      if (xx <=0 || xx > n || yy <= 0 || yy >m)
      {
        if (xx == 1 && yy == 0 && nv < ans) ans = nv;
        continue;
      }
      if (!b[xx][yy][i] || a[xx][yy][i] > nv) 
      {
        b[xx][yy][i] = 1;
        a[xx][yy][i] = nv;
        q[0].push(xx);
        q[1].push(yy);
        q[2].push(i);
        q[3].push(nv);                  
      }
    }
  }
  if (ans==1000001) printf("-1");
  else printf("%d", ans);   
}