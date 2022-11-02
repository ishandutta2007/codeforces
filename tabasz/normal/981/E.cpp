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
const int MM = 10001;
const int M = 1024 * 16;

bitset<MM> res;
vector<bitset<MM>> V;
vector<int> D[2 * M];
int n, q;

void add(int p, int k, int x)
{
  p += M;
  k += M;
  D[p].PB(x);
  if (p != k)
  {
    D[k].PB(x);
  }
  while (p / 2 != k / 2)
  {
    if (p % 2 == 0)
    {
      D[p + 1].PB(x);
    }
    p /= 2;
    if (k % 2 == 1)
    {
      D[k - 1].PB(x);
    }
    k /= 2;
  }
}

void go(int v)
{
  bitset<MM> B = V[siz(V) - 1];
  for (auto x : D[v])
  {
    B |= B<<x;
  }
  V.PB(B);
  res |= B;
  if (v < M)
  {
    go(2 * v);
    go(2 * v + 1);
  }
  V.pb();
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++)
  {
    int a, b, x;
    scanf("%d%d%d", &a, &b, &x);
    add(a, b, x);
  }
  V.PB(bitset<MM>());
  V[0][0] = 1;
  go(1);
  int r = 0;
  RE(i, n)
  {
    if (res[i])
    {
      r++;
    }
  }
  printf("%d\n", r);
  for (int i = 1; i <= n; i++)
  {
    if (res[i])
    {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}