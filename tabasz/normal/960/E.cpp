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
const int M = 1024 * 256;
const LL mod = 1e9 + 7;

int n;
vector<int> V[M];
LL res;
LL S[M], sum[M], T[M];

void DFS(int v, int pre)
{
  sum[v] = T[v];
  for (auto x : V[v])
  {
    if (x == pre)
    {
      continue;
    }
    DFS(x, v);
    S[v] += S[x];
    sum[v] -= sum[x];
    sum[v] = (sum[v] + mod + S[x] * T[v]) % mod;
  }
  S[v]++;
}

void DFS2(int v, int pre, LL sup)
{
  LL all = (sum[v] + mod - sup + T[v] * (n - S[v])) % mod;
  res += all;
  debug(v, all, sup);
  for (auto x : V[v])
  {
    if (x == pre)
    {
      continue;
    }
    DFS2(x, v, (all + sum[x] - (S[x] * T[v]) % mod) % mod);
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", T + i);
    T[i] = (T[i] + mod) % mod;
  }
  for (int i = 1; i < n; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    V[a].PB(b);
    V[b].PB(a);
  }
  DFS(0, 0);
  DFS2(0, 0, 0);
  printf("%lld\n", res % mod);
  return 0;
}