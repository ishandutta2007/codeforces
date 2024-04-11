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

int a[3];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < siz(s); i++)
  {
    a[s[i] - 'a']++;
    if (i > 0)
    {
      if (s[i] == 'a' && s[i - 1] == 'c')
      {
        printf("NO\n");
        return 0;
      }
      if (s[i] == 'a' && s[i - 1] == 'b')
      {
        printf("NO\n");
        return 0;
      }
      if (s[i] == 'b' && s[i - 1] == 'c')
      {
        printf("NO\n");
        return 0;
      }
    }
  }
  if (a[2] != a[1] && a[2] != a[0])
  {
    printf("NO\n");
    return 0;
  }
  if (a[0] == 0 || a[1] == 0)
  {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  return 0;
}