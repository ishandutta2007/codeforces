#include<cstdio>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int rev[] = {1, 0, 3, 2, 7, 6, 5, 4};
string mv[] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

int memo[8][8];
int dir[8][8];

int main()
{
  char s[4];
  int x1, y1, x2, y2;
  scanf("%s", s);
  x1 = s[0] - 'a'; y1 = s[1] - '1';
  scanf("%s", s);
  x2 = s[0] - 'a'; y2 = s[1] - '1';
  queue<int> qx, qy, qc;
  qx.push(x1); qy.push(y1); qc.push(0);
  for(int i=0; i<8; ++i)
    for(int j=0; j<8; ++j)
      memo[i][j] = 1000;
  memo[y1][x1] = 0;
  while(!qx.empty()) {
    int x = qx.front(); qx.pop();
    int y = qy.front(); qy.pop();
    int c = qc.front(); qc.pop();
    if(x == x2 && y == y2) {
      printf("%d\n", c);
      vector<string> o;
      while(x != x1 || y != y1) {
	o.push_back(mv[dir[y][x]]);
	x += dx[rev[dir[y][x]]];
	y += dy[rev[dir[y][x]]];
      }
      for(int i=o.size()-1; i>=0; --i)
	printf("%s\n", o[i].c_str());
      return 0;
    }
    for(int i=0; i<8; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 0 || ny < 0) continue;
      if(nx >= 8 || ny >= 8) continue;
      if(memo[ny][nx] > c+1) {
	memo[ny][nx] = c+1;
	dir[ny][nx] = i;
	qx.push(nx); qy.push(ny); qc.push(c+1);
      }
    }
  }
  return 0;
}