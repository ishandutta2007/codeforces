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
#define int LL
const int M = 2 * 1024 * 128;

struct event
{
  LL a, b, i;
  event(LL a_, LL b_, LL c) : a(a_), b(b_), i(c) {}
};

LL n, w, res;
int D[2 * M];
int start[M];
vector<event> X[3];

int sum(int p, int k)
{
  if (p > k)
  {
    return 0;
  }
  p += M;
  k += M;
  int r = D[p];
  if (p != k)
  {
    r += D[k];
  }
  while (p / 2 != k / 2)
  {
    if (p % 2 == 0)
    {
      r += D[p + 1];
    }
    if (k % 2 == 1)
    {
      r += D[k - 1];
    }
    p /= 2;
    k /= 2;
  }
  return r;
}

void add(int w, int v)
{
  v += M;
  D[v] += w;
  while (v > 1)
  {
    v /= 2;
    D[v] = D[2 * v] + D[2 * v + 1];
  }
}

bool cmp(event x, event y)
{
  if (x.a * y.b == x.b * y.a)
  {
    return x.i > y.i;
  }
  return x.a * y.b < x.b * y.a;
}

bool cmp2(event x, event y)
{
  if (x.a * y.b == x.b * y.a)
  {
    if (x.i * y.i < 0 || x.i > 0)
    {
      return x.i > y.i;
    }
    return x.a > y.a;
  }
  return x.a * y.b < x.b * y.a;
}

bool les(event x, event y)
{
  return x.a * y.b < x.b * y.a;
}

void solve(int ind)
{
  for (int i = 0; i < 2 * M; i++)
  {
    D[i] = 0;
  }
  sort(ALL(X[ind]), cmp2);
  int tmp = 0;
  for (int i = 0; i < siz(X[ind]); i++)
  {
    if (i > 0 && les(X[ind][i - 1], X[ind][i]))
    {
      tmp++;
    }
    if (X[ind][i].i > 0)
    {
      start[X[ind][i].i] = tmp;
    }
    else
    {
      LL qwe = sum(start[-X[ind][i].i], tmp);
      res += qwe;
      assert(qwe >= 0);
      add(1, start[-X[ind][i].i]);
    }
  }
}

void solve2()
{
  sort(ALL(X[2]), cmp);
  int live[3] = {0, 0, 0};
  for (auto x : X[2])
  {
    if (x.i > 0)
    {
      live[x.i]++;
    }
    else
    {
      res += live[3 + x.i];
      assert(live[3 + x.i] >= 0);
      live[-x.i]--;
    }
  }
}

main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%lld%lld", &n, &w);
  for (int i = 1; i <= n; i++)
  {
    int x, v;
    scanf("%lld%lld", &x, &v);
    if (x > 0)
    {
      X[0].PB(event(x, abs(v) + w, i));
      X[0].PB(event(x, abs(v) - w, -i));
      X[2].PB(event(x, abs(v) + w, 1));
      X[2].PB(event(x, abs(v) - w, -1));
    }
    else
    {
      X[1].PB(event(-x, abs(v) + w, i));
      X[1].PB(event(-x, abs(v) - w, -i));
      X[2].PB(event(-x, abs(v) + w, 2));
      X[2].PB(event(-x, abs(v) - w, -2));
    }
  }
  debug(siz(X[0]), siz(X[1]));
  solve(0);
  debug(res);
  solve(1);
  debug(res);
  solve2();
  printf("%lld\n", res);
  return 0;
}