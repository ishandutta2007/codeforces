#include<bits/stdc++.h>
using namespace std;
# ifdef DEB
# define debug(...) fprintf(stderr, __VA_ARGS__)
# else
# define debug(...)
#endif
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define VI vector<int> 
#define VPI vector<PII> 
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define ALL(x) (x).begin(), (x).end()
#define siz(V) ((int)V.size())

int n, m;
vector<PII> V[2];
char C[2][55][55];

void rotatel(int ind, int x, int y)
{
  V[ind].PB(MP(x, y));
  C[ind][x][y]='U';
  C[ind][x][y+1]='U';
  C[ind][x+1][y]='D';
  C[ind][x+1][y+1]='D';
}

void rotateu(int ind, int x, int y)
{
  V[ind].PB(MP(x, y));
  C[ind][x][y]='L';
  C[ind][x][y+1]='R';
  C[ind][x+1][y]='L';
  C[ind][x+1][y+1]='R';
}

void solve(int ind)
{
  while(true)
  {
    int tmp=0;
    bool boo=0;
    REP(i, n-1)
    {
      REP(j, m-1)
      {
        if(C[ind][i][j]!='U' && C[ind][i][j]!='D')
          boo=1;
        if(C[ind][i][j]=='L' && C[ind][i+1][j]=='L')
        {
          tmp++;
          rotatel(ind, i, j);
        }
      }
    }
    int booo=0;
    if(tmp==0 && boo)
    {
      REP(i, n-1)
      {
        REP(j, m-1)
        {
          if(C[ind][i][j]=='U' && C[ind][i][j+1]=='U')
          {
            rotateu(ind, i, j);
            booo++;
          }
          if(boo>1000)
            break;
        }
        if(booo>1000)
          break;
      }
    }
    else
    {
      if(boo==0)
        break;
    }
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  REP(i, 2)
  {
    REP(j, n)
    {
      scanf("%s", C[i][j]);
    }
  }
  REP(i, 2)
    solve(i);
  printf("%d\n", siz(V[0])+siz(V[1]));
  REP(i, siz(V[0]))
    printf("%d %d\n", V[0][i].F+1, V[0][i].S+1);
  for(int i=siz(V[1])-1; i>=0; i--)
    printf("%d %d\n", V[1][i].F+1, V[1][i].S+1);
  return 0;
}