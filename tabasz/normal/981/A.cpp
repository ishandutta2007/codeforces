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

bool good(string s)
{
  for (int i = 0; i < siz(s); i++)
  {
    if (s[i] != s[siz(s) - i - 1])
    {
      return true;
    }
  }
  return false;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  string s;
  cin >> s;
  int n = siz(s), res = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      string ss = s.substr(i, j - i + 1);
      if (good(ss))
      {
        res = max(res, j - i + 1);
      }
    }
  }
  cout << res << "\n";
  return 0;
}