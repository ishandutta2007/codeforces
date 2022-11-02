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

int A[M], T[M], n;

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", T + i);
  }
  int pre = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    pre--;
    pre = max(pre, T[i] + 1);
    A[i] = pre;
  }
  LL res = 0;
  for (int i = 1; i < n; i++)
  {
    A[i] = max(A[i - 1], A[i]);
    res += A[i] - T[i] - 1;
  }
  printf("%lld\n", res);
  return 0;
}