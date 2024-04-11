#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define LD long double
#define VI vector <int>
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

LL k, d, t;

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%lld%lld%lld", &k, &d, &t);
  LD kk = k, tt = t;
  if (k % d == 0 || t <= k)
  {
    printf("%lld\n", t);
    return 0;
  }
  LL tim = d * ((k + d - 1) / d);
  LL res = 0;
  LD il = (LD)(k + tim) / (2 * tt);
  LL st = 0, en = 1e18, mid = (st + en) / 2;
  while (st <= en)
  {
    if (il * mid >= 1)
    {
      en = mid - 1;
    }
    else
    {
      st = mid + 1;
      res = max(res, mid);
    }
    mid = (st + en) / 2;
  }
  LD rest = 1.0 - mid * il;
  LD rr = 0;
  if (rest <= kk / tt)
  {
    rr = (LD)res * tim + rest * tt;
  }
  else
  {
    rr = (LD)res * tim + kk;
    rest -= kk / tt;
    rr += rest * tt * 2;
  }
  printf("%.10Lf\n", rr);
  return 0;
}