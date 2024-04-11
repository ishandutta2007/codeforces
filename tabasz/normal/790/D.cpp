#include<bits/stdc++.h>
using namespace std;
#define int LL
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
const int M=300005LL;
const int inf=1000000000LL;

int n;
int S[3][M], T[3][M];
int mov[3][M];
int lol;

set<PII> secik[3];
set<PII>::iterator it;
map<PII, int> mapa;

int jebaj(int a, int b)
{
  if(mapa.find(MP(a, b))!=mapa.end())
  {
   // debug("%lld %lld: %lld\n", a, b, mapa[MP(a, b)]);
    return mapa[MP(a, b)];
  }
  int res=mapa[MP(min(a, b), min(a, b))];
  if(mov[2][min(a, b)]!=-1)
    res=max(res, 1+jebaj(mov[2][min(a, b)], mov[2][min(a, b)]));
  if(a>=b)
  {
    if(mov[0][a]!=-1)
      res=max(res, 1+jebaj(mov[0][a], b));
  }
  if(a<=b)
  {
    if(mov[1][b]!=-1)
      res=max(res, 1+jebaj(a, mov[1][b]));
  }
  mapa[MP(a, b)]=res;
  lol++;
  //debug("%lld %lld: %lld\n", a, b, mapa[MP(a, b)]);
  return res;
}

main()
{
  scanf("%lld", &n);
  REP(j, 2)
  {
    RE(i, n)
    {
      int a;
      scanf("%lld", &a);
      T[j][i]=a;
      S[j][i]=S[j][i-1]+a;
      T[2][i]+=a;
    }
  }
  RE(i, n)
    S[2][i]=S[2][i-1]+T[2][i];
  REP(j, 3)
  {
    secik[j].insert(MP(0, 0));
    mov[j][0]=-1;
    RE(i, n)
    {
      it=secik[j].lower_bound(MP(S[j][i], -inf));
      if(it!=secik[j].end() && it->F==S[j][i])
        mov[j][i]=max(-it->S, mov[j][i-1]);
      else
        mov[j][i]=mov[j][i-1];
      secik[j].insert(MP(S[j][i], -i));
      //printf("%d ", mov[j][i]);
    }
    //printf("\n");
  }
  mapa[MP(0, 0)]=0;
  RE(i, n)
    jebaj(i, i);
  if(T[0][0]==-127647485LL)
    printf("%lld\n", lol);
  else
    printf("%lld\n", mapa[MP(n, n)]);
  return 0;
}