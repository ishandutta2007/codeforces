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
const int M = 1024 * 128;
const LL inf = 1e18;

struct edge
{
  int p, k, val, ind;
};

int n, m;
int pos[M], first[M], last[M];
LL res, D[2 * M];
edge E[M];
vector<edge> V;

bool cmp(edge x, edge y)
{
  if (x.k == y.k)
  {
    if (x.val == y.val)
    {
      return x.ind < y.ind;
    }
    return x.val < y.val;
  }
  return x.k < y.k;
}

void add(int v, LL x)
{
  v += M;
  D[v] = x;
  while (v > 1)
  {
    v /= 2;
    D[v] = max(D[2 * v], D[2 * v + 1]);
  }
}

LL maxi(int p, int k)
{
  if (p > k)
  {
    return 0;
  }
  p += M;
  k += M;
  LL r = max(D[p], D[k]);
  while (p / 2 != k / 2)
  {
    if (p % 2 == 0)
    {
      r = max(r, D[p + 1]);
    }
    if (k % 2 == 1)
    {
      r = max(r, D[k - 1]);
    }
    p /= 2;
    k /= 2;
  }
  return r;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    edge x;
    scanf("%d%d%d", &x.p, &x.k, &x.val);
    x.p--;
    x.k--;
    x.ind = i;
    V.PB(x);
    E[i] = x;
  }
  for (int i = 0; i < n; i++)
  {
    first[i] = M;
  }
  sort(ALL(V), cmp);
  for (int i = 0; i < m; i++)
  {
    pos[V[i].ind] = i;
    debug(V[i].ind, i);
    first[V[i].k] = min(first[V[i].k], i);
    last[V[i].k] = max(last[V[i].k], i);
  }
  for (int i = 0; i < m; i++)
  {
    int st = first[E[i].p], en = last[E[i].p], mid = (st + en) / 2, r = st - 1;
    debug(i, st, en);
    while (st <= en)
    {
      if (V[mid].val < E[i].val)
      {
        r = max(r, mid);
        st = mid + 1;
      }
      else
      {
        en = mid - 1;
      }
      mid = (st + en) / 2;
    }
    debug(i, first[E[i].p], r);
    LL best = maxi(first[E[i].p], r);
    res = max(res, best + 1);
    debug(E[i].p, E[i].k, E[i].val, res);
    add(pos[i], best + 1);
  }
  printf("%lld\n", res);
  return 0;
}