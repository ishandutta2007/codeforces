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

int n;
char C[100];

int get(PII x)
{
  printf("%d %d\n", x.F, x.S);
  fflush(stdout);
  scanf("%s", C);
  if (C[0] == 'w')
  {
    return 0;
  }
  return 1;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d", &n);
  
  int st = get(MP(0, 0));
  n--;
  
  if (n == 0)
  {
    printf("1 0 1 1\n");
    fflush(stdout);
    return 0;
  }
  
  PII x = MP(0, 0), pre = x;
  int tmp = st, i = 28;
  while (n > 0 && tmp == st && i > 0)
  {
    pre = x;
    x.F += (1<<i);
    i--;
    n--;
    tmp = get(x);
  }
  
  if (n == 0)
  {
    if (tmp == st)
    {
      printf("%d %d %d %d\n", x.F + 1, 0, x.F + 1, 1);
    }
    else
    {
      printf("%d %d %d %d\n", pre.F + 1, 0, pre.F + 1, 1);
    }
    fflush(stdout);
    return 0;
  }
  if (tmp == st)
  {
    pre = x;
  }
  
  PII up = MP(pre.F, 0);
  i = 28;
  tmp = st;
  while (tmp == st && n > 0)
  {
    up.S += (1<<i);
    i--;
    n--;
    tmp = get(up);
  }
  
  if (n == 0)
  {
    if (tmp == st)
    {
      printf("%d %d %d %d\n", up.F + 1, 0, up.F, up.S + 1);
    }
    else
    {
      printf("%d %d %d %d\n", up.F + 1, 0, up.F, up.S - 1);
    }
    fflush(stdout);
    return 0;
  }
  
  PII down = MP(up.F, up.S - (1<<(i + 1)));
  PII mid = MP(up.F, (up.S + down.S) / 2);
  while (n > 0)
  {
    //debug(down, up, mid);
    n--;
    if (get(mid) == st)
    {
      down = mid;
    }
    else
    {
      up = mid;
    }
    mid = MP(up.F, (up.S + down.S) / 2);
  }
  //debug(down, up, mid);
  printf("%d %d %d %d\n", up.F + 1, 0, up.F, up.S - 1);
  fflush(stdout);
  return 0;
}