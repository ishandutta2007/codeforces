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

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  int n;
  scanf("%d", &n);
  REP(i, n)
  {
    LL p, q, b;
    scanf("%lld%lld%lld", &p, &q, &b);
    LL gc = __gcd(p, q);
    if (p == 0)
    {
      gc = q;
    }
    p /= gc;
    q /= gc;
    //debug(p, q);
    while (true)
    {
      gc = __gcd(q, b);
      if (gc == 1)
      {
        break;
      }
      q /= gc;
      b = gc;
    }
    if (q == 1)
    {
      printf("Finite\n");
    }
    else
    {
      printf("Infinite\n");
    }
  }
  return 0;
}