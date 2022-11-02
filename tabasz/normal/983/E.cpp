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
const int M = 1024 * 256;

int pr[M], po[M], dep[M], prv[M];
vector<int> V[M], D[2 * M];
int n, m, q, tmp = 1, T[20][M], TT[20][M];

void DFS(int v, int p, int d)
{
  dep[v] = d;
  T[0][v] = p;
  tmp++;
  pr[v] = tmp;
  debug("advaefeab", v, tmp);
  for (auto x : V[v])
  {
    if (x != p)
    {
      DFS(x, v, d + 1);
    }
  }
  po[v] = tmp;
}

bool ancestor(int v, int u)
{
  return pr[v] <= pr[u] && po[v] >= po[u];
}

int lca(int a, int b)
{
  if (ancestor(a, b))
  {
    return a;
  }
  if (ancestor(b, a))
  {
    return b;
  }
  int i = 19;
  while (i >= 0)
  {
    if (!ancestor(T[i][a], b))
    {
      a = T[i][a];
    }
    i--;
  }
  return T[0][a];
}

void DFS2(int v, int p)
{
  for (auto x : V[v])
  {
    if (x != p)
    {
      DFS2(x, v);
      if (dep[TT[0][x]] < dep[TT[0][v]])
      {
        TT[0][v] = TT[0][x];
      }
    }
  }
}

int mini(int a, int b)
{
  int r = 0;
  int i = 19;
  while (i >= 0)
  {
    if (!ancestor(TT[i][a], b))
    {
      debug(i, a, b, TT[i][a]);
      r += (1<<i);
      a = TT[i][a];
    }
    i--;
  }
  return r + 1;
}

int go(int v, int dist)
{
  int i = 0;
  while (dist != 0)
  {
    if (dist % 2)
    {
      v = TT[i][v];
    }
    dist /= 2;
    i++;
  }
  return v;
}

void add(int v, int w)
{
  v += M;
  D[v].PB(w);
  while (v > 1)
  {
    v /= 2;
    D[v].PB(w);
  }
}

bool jestt(int v, int a, int b)
{
  auto it = lower_bound(ALL(D[v]), a);
  if (it != D[v].end() && *it <= b)
  {
    debug(v - M, a, b, *it);
    return true;
  }
  return false;
}

bool jest(int p, int k, int a, int b)
{
  p += M;
  k += M;
  if (jestt(p, a, b) || jestt(k, a, b))
  {
    return true;
  }
  while (p / 2 != k / 2)
  {
    if (p % 2 == 0)
    {
      if (jestt(p + 1, a, b))
      {
        return true;
      }
    }
    p /= 2;
    if (k % 2 == 1)
    {
      if (jestt(k - 1, a, b))
      {
        return true;
      }
    }
    k /= 2;
  }
  return false;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d", &n);
  for (int i = 2; i <= n; i++)
  {
    int a;
    scanf("%d", &a);
    V[a].PB(i);
    V[i].PB(a);
  }
  
  DFS(1, 0, 0);
  po[0] = tmp + 1;
  for (int i = 1; i <= n; i++)
  {
    TT[0][i] = i;
  }
  for (int i = 1; i < 20; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      T[i][j] = T[i - 1][T[i - 1][j]];
    }
  }
 // return 0;
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    int lc = lca(a, b);
    debug(a, b, lc);
    if (dep[TT[0][a]] > dep[lc])
    {
      TT[0][a] = lc;
    }
    if (dep[TT[0][b]] > dep[lc])
    {
      TT[0][b] = lc;
    }
    add(pr[a], pr[b]);
    add(pr[b], pr[a]);
  }
  for (int i = 0; i < 2 * M; i++)
  {
    sort(ALL(D[i]));
  }
  DFS2(1, 0);
  for (int i = 1; i <= n; i++)
  {
    debug(TT[0][i]);
  }
  for (int i = 1; i < 20; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      TT[i][j] = TT[i - 1][TT[i - 1][j]];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    debug("qwe", TT[1][i]);
  }
  for (int i = 1; i <= n; i++)
  {
    debug("qwe", TT[2][i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    int lc = lca(a, b);
    debug(a, b, lc);
    if (lc == a)
    {
      int r = mini(b, lc);
      if (r > m)
      {
        printf("-1\n");
      }
      else
      {
        printf("%d\n", r);
      }
      continue;
    }
    if (lc == b)
    {
      int r = mini(a, lc);
      if (r > m)
      {
        printf("-1\n");
      }
      else
      {
        printf("%d\n", r);
      }
      continue;
    }
    int minia = mini(a, lc);
    int minib = mini(b, lc);
    debug(minia, minib);
    if (minia + minib > 2 * m)
    {
      printf("-1\n");
      continue;
    }
    int va = go(a, minia - 1);
    int vb = go(b, minib - 1);
    debug("qwe", a, b, lc, minia, minib, va, vb);
    if (jest(pr[va], po[va], pr[vb], po[vb]))
    {
      printf("%d\n", minia + minib - 1);
      continue;
    }
    /*if (jest(pr[va], po[va], pr[T[0][vb]], po[T[0][vb]]) || 
        jest(pr[T[0][va]], po[T[0][va]], pr[vb], po[vb]))
    {
      printf("%d\n", minia + minib - 1);
      continue;
    }*/
    if (minia + minib < 2 * m)
    {
      printf("%d\n", minia + minib);
    }
    else
    {
      printf("-1\n");
    }
  }
// debug(ancestor(0, 4), pr[0], po[0]);
  return 0;
}