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
const int mid=200;

bool B[33][404][404];
int n, T[35], res;

bool get(int ind, bool boo, int x, int y)
{
  if(x<0 || y<0 || x>2*mid || y>2*mid)
    return false;
  if(boo==0)
    return B[ind][x][y];
  if(ind%2)
    return get(ind, 0, 2*mid-x, y);
  else
    return get(ind, 0, 2*mid-y, x);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  REP(i, n)
    scanf("%d", T+i);
  FORD(i, n-1, 0)
  {
    int x11, y11, x22, y22;
    if(i%2==0)
    {
      x11=1;
      y11=T[i];
      x22=-1;
      y22=T[i];
      REP(l, T[i])
        B[i][mid][mid+l]=1;
    }
    else
    {
      x11=T[i]-1;
      y11=T[i];
      x22=T[i];
      y22=T[i]-1;
      REP(l, T[i])
        B[i][mid+l][mid+l]=1;
    }
    REP(j, mid*2)
    {
      REP(k, mid*2)
      {
        if(get(i+1, 0, j-x11, k-y11) || get(i+1, 1, j-x22, k-y22))
          B[i][j][k]=1;
      }
    }
  }
  REP(i, mid*2+1)
    REP(j, mid*2+1)
      if(B[0][i][j])
        res++;
  printf("%d\n", res);
  return 0;
}