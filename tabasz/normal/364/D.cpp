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
const int M = 1024 * 1024;
const int REPEATS = 10;

int n;
LL T[M], res = 1;
vector<PLL> D;
unordered_map<LL, int> mapa;
set<LL> secik;

void solve(int ind)
{
  D.clear();
  mapa.clear();
  for (LL i = 1; i * i <= T[ind]; i++)
  {
    if (T[ind] % i == 0)
    {
      D.PB(MP(i, 0));
      if (i * i != T[ind])
      {
        D.PB(MP(T[ind] / i, 0));
      }
    }
  }
  sort(ALL(D));
  for (int i = 0; i < siz(D); i++)
  {
    mapa[D[i].F] = i;
  }
  for (int i = 0; i < n; i++)
  {
    D[mapa[__gcd(T[ind], T[i])]].S++;
  }
  for (int i = siz(D) - 1; i >= 0; i--)
  {
    if (D[i].F <= res)
    {
      break;
    }
    int sum = 0;
    for (int j = i; j < siz(D); j++)
    {
      if (D[j].F % D[i].F == 0)
      {
        sum += D[j].S;
      }
    }
    if (sum * 2 >= n)
    {
      res = max(res, D[i].F);
    }
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", T + i);
  }
  for (int i = 0; i < REPEATS; i++)
  {
    int ind = (((LL)rand()<<16LL) + (LL)rand()) % n;
    if (secik.find(T[ind]) == secik.end())
    {
      solve(ind);
      secik.insert(T[ind]);
    }
  }
  printf("%lld\n", res);
  return 0;
}