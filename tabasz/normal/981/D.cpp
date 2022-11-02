#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define PLL pair<LL, LL>
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
#define RE(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ALL(x) x.begin(), x.end()
#define siz(x) ((int)x.size())
#define Sim template <class s
Sim, class d> ostream & operator<<(ostream &os, pair<s,d> x){return os << "<" << x.F << ", " <<
  x.S << "> ";}
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
const int M = 60;

int n, k;
LL res, T[M], S[M][M];
bool dp[M][M];

bool check()
{
  REP(i, M)
  {
    REP(j, M)
    {
      dp[i][j] = false;
    }
  }
  dp[0][0] = true;
  
  for (int i = 1; i <= k; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int l = 1; l <= j; l++)
      {
        if ((S[l][j] & res) == res && dp[i - 1][l - 1])
        {
          dp[i][j] = true;
          break;
        }
      }
    }
  }
  return dp[k][n];
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d%d", &n, &k);
  RE(i, n)
  {
    scanf("%lld", T + i);
  }
  RE(i, n)
  {
    for (int j = i; j <= n; j++)
    {
      S[i][j] = T[j];
      if (j > i)
      {
        S[i][j] += S[i][j - 1];
      }
    }
  }
  int i = 60;
  while (i >= 0)
  {
    res += (1LL<<i);
    if (!check())
    {
      res -= (1LL<<i);
    }
    i--;
  }
  printf("%lld\n", res);
  return 0;
}