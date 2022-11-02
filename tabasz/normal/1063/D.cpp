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
#define int LL

const LL midd = 1e6;
LL n, l, r, k, d;

bool solve(LL s)
{
  LL mi = d + max(0LL, s - n + d - 1);
  LL ma = d + min(d, s);
  //debug(s, mi, ma, k);
  if (ma < mi)
  {
    return false;
  }
  
  if (ma >= k && mi <= k)
  {
    return true;
  }
  if (mi > k)
  {
    return false;
  }
  LL lef = k - ma;
  LL rig = k - mi;
  //debug(lef, rig, s + n);
  if (rig < s + n)
  {
    return false;
  }
  if ((rig / (s + n)) * (s + n) >= lef)
  {
    return true;
  }
  /*if (rig - lef >= (s + n) || rig % (s + n) <= lef % (s + n))
  {
    return true;
  }*/
  return false;
}

LL solveOkr(LL o)
{
  //debug("o", o);
  LL ka = k - (n * o + d);
//  debug("ka", ka);
  if (ka < 0)
  {
    return -1;
  }
  
  if (o == 0)
  {
    if (ka > d)
    {
      return -1;
    }
   // debug("qwe", n - d + 1 + min(d - 1, ka));
    return n - d + 1 + min(d - 1, ka);
  }
  LL st = 0, en = min(ka / o + 1, n), mid = (st + en) / 2, r = -1;
  while (st <= en)
  {
    LL mi = o * mid + max(0LL, mid - n + d - 1);
    LL ma = o * mid + min(d, mid);
   // if (o == 14)
     // debug("               ", st, en, mid, mi, ma, ka);
    if (ka >= mi && ka <= ma)
    {
      r = max(r, mid);
      st = mid + 1;
    }
    else
    {
      if (ma < ka)
      {
        st = mid + 1;
      }
      else
      {
        en = mid - 1;
      }
    }
    mid = (st + en) / 2;
  }
//  debug("r", r);
  return r;
}

main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  LL rr = r;
  if (r < l)
  {
    rr = r + n;
  }
  d = rr - l + 1;
 // debug("d", d);
  if (n <= midd)
  {
    for (LL i = n; i >= 0; i--)
    {
      if (solve(i))
      {
        printf("%lld\n", i);
        return 0;
      }
    }
    printf("-1\n");
    return 0;
  }
  LL res = -1;
  for (LL i = 0; i * n <= k; i++)
  {
    res = max(res, solveOkr(i));
  }
  printf("%lld\n", res);
  return 0;
}