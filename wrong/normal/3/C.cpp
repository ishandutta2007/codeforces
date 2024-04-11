#include<cstdio>

using namespace std;

int p3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561};

bool vis[20000];
int bd[3][3];

bool win(int bd[3][3])
{
  for(int i=0; i<3; ++i) {
    if(bd[i][0] == bd[i][1] && bd[i][1] == bd[i][2] && bd[i][0] != 0)
      return true;
    if(bd[0][i] == bd[1][i] && bd[1][i] == bd[2][i] && bd[0][i] != 0)
      return true;
  }
  if(bd[0][0] == bd[1][1] && bd[1][1] == bd[2][2] && bd[0][0] != 0)
    return true;
  if(bd[0][2] == bd[1][1] && bd[1][1] == bd[2][0] && bd[0][2] != 0)
    return true;
  return false;
}

void dfs(int pat, int turn)
{
  if(vis[pat]) return;
  vis[pat] = true;
  if(win(bd)) return;
  for(int i=0; i<3; ++i) {
    for(int j=0; j<3; ++j) {
      if(bd[i][j] == 0) {
	bd[i][j] = turn;
	dfs(pat + p3[i*3+j]*turn, turn == 1 ? 2 : 1);
	bd[i][j] = 0;
      }
    }
  }
}

int main()
{
  dfs(0, 1);
  char s[3][4];
  for(int i=0; i<3; ++i) scanf("%s", s[i]);
  int enc = 0;
  int c1 = 0, c2 = 0;
  for(int i=0; i<3; ++i)
    for(int j=0; j<3; ++j)
      if(s[i][j] == 'X')
	enc += p3[i*3+j], bd[i][j] = 1, c1++;
      else if(s[i][j] == '0')
	enc += p3[i*3+j]*2, bd[i][j] = 2, c2++;
  if(!win(bd) && c1+c2 == 9 && c1-c2 == 1) puts("draw");
  else if(!vis[enc]) puts("illegal");
  else if(win(bd)) puts(c1 == c2 ? "the second player won" : "the first player won");
  else  puts(c1 == c2 ? "first" : "second");
  return 0;
}