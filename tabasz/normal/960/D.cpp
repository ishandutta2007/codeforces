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
#define PLL pair<LL, LL>
const int M = 61;

LL sh[M], len[M + 1];
int q;

PLL getplace(LL x)
{
  LL xx = x;
  LL ind = 0;
  while (xx > 1)
  {
    ind++;
    xx /= 2;
  }
  LL pos = (x - sh[ind]) % len[ind];
  return MP(ind, pos);
}

LL getval(PLL x)
{
  return (x.S + sh[x.F]) % len[x.F] + len[x.F];
}

int main()
{
  len[0] = 1;
  for (int i = 1; i <= M; i++)
  {
    len[i] = len[i - 1] * 2;
  }
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    LL a, b, c;
    scanf("%lld%lld", &a, &b);
    PLL x = getplace(b);
    if (a == 3)
    {
      while (x.F >= 0)
      {
        printf("%lld ", getval(x));
        x.F--;
        x.S /= 2;
      }
      printf("\n");
      continue;
    }
    scanf("%lld", &c);
    c *= -1;
    c = (c + len[x.F]) % len[x.F];
    if (a == 1)
    {
      sh[x.F] = (sh[x.F] + len[x.F] + c) % len[x.F];
    }
    else
    {
      for (int i = x.F; i < M; i++)
      {
        sh[i] = (sh[i] + len[i] + c) % len[i];
        c *= 2;
        c %= len[i + 1];
      }
    }
  }
  return 0;
}