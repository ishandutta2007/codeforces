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
const LL p=10007;
const LL mod=1000000007;

int n, m;
map<LL, bool> mapa;
string a[5];
bool B[5005][1005];
PLL dzia[5005];
int rodz[5005];//1-OR, 2-XOR, 3-AND
LL has[5005];
bool R[2][1005];//mini, maxi

LL geth(int ind)
{
  if(a[ind][0]=='?')
    return 0;
  LL h=0;
  REP(i, a[ind].size())
    h=(h*p+(LL)a[ind][i])%mod;
  return h;
}

int getres(int pos, int x)
{
  int res=0;
  mapa[0]=x;
  //res+=x;
  REP(i, n)
  {
    int tmp=0;
    if(rodz[i]==0)
    {
      if(B[i][pos])
        tmp=1;
    }
    else
    {
     // debug("%d %d %d %d %d %d\n", pos, x, i, mapa[dzia[i].F], mapa[dzia[i].S], rodz[i]);
      if(rodz[i]==1)
        tmp=mapa[dzia[i].F]|mapa[dzia[i].S];
      if(rodz[i]==2)
        tmp=mapa[dzia[i].F]^mapa[dzia[i].S];
      if(rodz[i]==3)
        tmp=mapa[dzia[i].F]&mapa[dzia[i].S];
    }
    mapa[has[i]]=tmp;
    res+=tmp;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> n >> m;
  REP(i, n)
  {
    cin>> a[0] >> a[1] >> a[2];
    //cout<< a[0] << "  " << a[1] << "  " << a[2] << '\n';
    has[i]=geth(0);
    if(a[2][0]=='0' || a[2][0]=='1')
    {
      REP(j, m)
        if(a[2][j]=='1')
          B[i][j]=1;
    }
    else
    {
      cin>> a[3] >> a[4];
      LL h1=geth(2), h2=geth(4);
      dzia[i]=MP(h1, h2);
      if(a[3][0]=='O')
        rodz[i]=1;
      if(a[3][0]=='X')
        rodz[i]=2;
      if(a[3][0]=='A')
        rodz[i]=3;
    }
   // cerr<< i << "     " << rodz[i] << '\n';
  }
  REP(i, m)
  {
    int a0=getres(i, 0), a1=getres(i, 1);
   // debug("%d: %d %d\n", i, a0, a1);
    if(a0<a1)
      R[1][i]=1;
    if(a0>a1)
      R[0][i]=1;
  }
  REP(i, m)
    cout<< R[0][i];
  cout<< '\n';
  REP(i, m)
    cout<< R[1][i];
  cout<< '\n';
  return 0;
}