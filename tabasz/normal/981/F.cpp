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

int n, l;
vector<int> V[2];
vector<PII> X;

void jebaj(int p, int k, int i)
{
  while (p < i)
  {
    p += n;
    k += n;
  }
  debug(p, k);
  X.PB(MP(p - i, 1));
  X.PB(MP(k + 1 - i, -1));
}

bool checkX()
{
  int tmp = 0;
  for(auto x : X)
  {
    tmp += x.S;
    if (tmp == n)
    {
      return true;
    }
  }
  return false;
}

bool check(int m)
{
  X.clear();
  debug(m);
  REP(i, n)
  {
    auto lef = lower_bound(ALL(V[1]), V[0][i] - m);
    auto rig = upper_bound(ALL(V[1]), V[0][i] + m);
    PII x = MP(lef - V[1].begin(), rig - V[1].begin() - 1);
    if (x.F > x.S)
    {
      return false;
    }
    if (x.S - x.F >= n)
    {
      x.S = x.F + n - 1;
    }
    debug("qwe", V[0][i] - m, V[0][i] + m, x);
    while (x.S < i + n)
    {
      x.F += n;
      x.S += n;
    }
    if (x.F < i + n && x.S >= i + n)
    {
      jebaj(x.F, i + n - 1, i + n);
      jebaj(i + n, x.S, i + n);
    }
    else
    {
      jebaj(x.F, x.S, i + n);
    }
  }
  sort(ALL(X));
  return checkX();
}

main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%lld%lld", &n, &l);
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < n; i++)
    {
      int a;
      scanf("%lld", &a);
      V[j].PB(l * (1 - j) + a);
    }
    sort(ALL(V[j]));
  }
  for (int i = 0; i < n; i++)
  {
    V[1].PB(V[1][i] + l);
  }
  for (int i = 0; i < n; i++)
  {
    V[1].PB(V[1][i] + 2 * l);
  }
  int st = 0, en = l, mid = (st + en) / 2, r = l;
  while (st <= en)
  {
    if (check(mid))
    {
      r = min(r, mid);
      en = mid - 1;
    }
    else
    {
      st = mid + 1;
    }
    mid = (st + en) / 2;
  }
  printf("%lld\n", r);
  return 0;
}