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
const int M = 1024 * 10;

bitset<M> waz[M], niewaz;
int n, l, r, res, wa;
int T[M][2];
vector<int> W;

void check(int rem, int len)
{
  int remm = rem, lenn = len;
  if (!waz[wa][rem])
  {
    return;
  }
  int ind = wa;
  int rr = 0;
  while (ind >= 0)
  {
    if (ind == 0)
    {
      assert(rem == 0);
      break;
    }
    if (len < 0)
    {
      break;
    }
    if (ind > 0 && waz[ind - 1][rem])
    {
      rr++;
      len -= W[ind - 1];
    }
    else
    {
      rem -= W[ind - 1];
    }
    ind--;
  }
  //debug(remm, lenn, rr);
  res = max(res, rr);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d%d%d", &n, &l, &r);
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", T[i] + j);
    }
  }
  waz[0][0] = true;
  niewaz[0] = true;
  for (int i = 0; i < n; i++)
  {
    if (T[i][1])
    {
      W.PB(-T[i][0]);
    }
    else
    {
      //debug(T[i][0]);
      niewaz |= (niewaz<<(T[i][0]));
    }
  }
  wa = siz(W);
  sort(ALL(W));
  for (int i = 0; i < wa; i++)
  {
    W[i] *= -1;
    waz[i + 1] = waz[i] | (waz[i]<<W[i]);
  }
  //debug(niewaz, l, r);
  for (int i = l; i <= r; i++)
  {
    if (niewaz[i])
    {
      //debug("lol", r, i);
      check(0, r - i);
      break;
    }
  }
  for (int i = 1; i <= r; i++)
  {
    for (int j = max(l, i); j - i < l; j++)
    {
      if (niewaz[j])
      {
        break;
      }
      if (niewaz[j - i])
      {
        check(i, r - j);
        break;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}