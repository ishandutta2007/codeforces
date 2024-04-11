#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define LD long double
#define VI vector<int>
#define VPII vector<PII>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define pb pop_back
#define FOR(a,s,d) for (int a = (s); a <= (int)(d); ++a)
#define FORD(a,s,d) for (int a = (s); a >= (int)(d); --a)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(x) x.begin(), x.end()
#define siz(x) ((int)x.size())
#define Sim template <class s
Sim, class d> ostream & operator<<(ostream &os, pair<s,d> x){return os << "<" << x.f << ", " <<
  x.s << "> ";}
Sim> auto operator<<(ostream &os, s x) -> typename enable_if<!is_same<s,string>::value,
  decltype(x.begin(), os)>::type
{ int o = 0; os << "{"; for (auto c : x) {if(o++) os << ", "; os << c;}return os << "} ";}
void dor() {cerr << endl;}
Sim, class ...t> void dor(s x, t...y) {cerr << x << " "; dor(y...);}
#ifdef DEB
#define debug(c...) dor(__FUNCTION__, ":", __LINE__, ": ", c)
#else
#define debug(...)
#endif
const int M = 100;

LL X[M], Y[M];
char C[M];

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf(" %s", C);
    for (int j = 0; j < m; j++)
    {
      if (C[j] == '#')
      {
      //  debug(i, j);
        X[i] ^= (1LL<<j);
        Y[j] ^= (1LL<<i);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if ((X[i] & X[j]) != 0LL)
      {
       // printf("%lld\n", X[i] & X[j]);
        //debug(i, j, X[i], X[j], (X[i] & X[j]) != 0);
        if (X[i] != X[j])
        {
          
          printf("No\n");
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = i + 1; j < m; j++)
    {
      if ((Y[i] & Y[j]) != 0LL)
      {
        if (Y[i] != Y[j])
        {
          printf("No\n");
          return 0;
        }
      }
    }
  }
  printf("Yes\n");
  return 0;
}