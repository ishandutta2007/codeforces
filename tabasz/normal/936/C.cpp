#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define LD long double
#define VI vector <int>
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

int n, T[100];
string a, b;
vector<int> V;

void jebaj(int pos)
{
  if (pos == n)
  {
    return;
  }
  V.PB(n - pos);
  string s;
  //debug(pos, a);
  string end = a.substr(pos, n - pos);
  reverse(end.begin(), end.end());
  s = end + a.substr(0, pos);
  swap(a, s);
  //debug("tera", a);
}

int find(char c)
{
  int ind = n - 1;
  while (ind >= 0 && a[ind] != c)
  {
    ind--;
  }
  return ind;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++)
  {
    T[a[i] - 'a']++;
    T[b[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++)
  {
    if (T[i] != 0)
    {
      printf("-1\n");
      return 0;
    }
  }
  int st = n / 2;
  for (int i = 0; i < n; i++)
  {
    int ind = find(b[st]);
    //debug(i, st, b[st], ind);
    jebaj(ind);
    jebaj(n + i - ind);
    jebaj(n - i - 1);
    if (i % 2 == 1)
    {
      st += i + 1;
    }
    else
    {
      st -= i + 1;
    }
  }
  if (n % 2 == 0)
  {
    jebaj(0);
  }
  assert(a == b);
  printf("%d\n", siz(V));
  for (int i = 0; i < siz(V); i++)
  {
    printf("%d ", V[i]);
  }
  printf("\n");
  return 0;
}