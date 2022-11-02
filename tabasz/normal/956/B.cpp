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

int n, m;
int T[M];
double res = -1;

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", T + i);
  }
  int last = 0;
  for (int i = 0; i < n - 2; i++)
  {
    while (last + 1 < n && T[last + 1] - T[i] <= m)
    {
      last++;
    }
    if (i + 1 < last)
    {
      //debug(i, i + 1, last);
      //debug((double)(T[last] - T[i + 1]) / (double)(T[last] - T[i]));
      res = max(res, (double)(T[last] - T[i + 1]) / (double)(T[last] - T[i]));
    }
  }
  if (res < 0)
  {
    printf("-1\n");
  }
  else
  {
    printf("%.10lf\n", res);
  }
  return 0;
}