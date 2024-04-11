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

vector<int> V;
map<int, int> dp[2005][10];
int n, pos[2005][10];
vector<PII> Q[10];
priority_queue<pair<PII, PII>> QQ;

vector<int> getVec(int x)
{
  vector<int> V;
  while (x > 0)
  {
    V.PB(x % 10);
    x /= 10;
  }
  return V;
}

int getInt(vector<int>& V)
{
  sort(ALL(V));
  int x = 0;
  for (auto v : V)
  {
    x *= 10;
    x += v;
  }
  return x;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  /*dp[0][1].PB(MP(0, 0));
  for (int i = 0; i < 10000; i++)
  {
    vector<int> X;
    int tmp = i;
    bool boo = true;
    for (int j = 0; j < 4; j++)
    {
      X.PB(tmp % 10);
      tmp /= 10;
      if (j > 0 && X[j] < X[j - 1])
      {
        boo = false;
        break;
      }
    }
    if (boo)
    {
      V.PB(i);
    }
  }
  printf("%d", siz(V));*/
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    Q[a].PB(MP(i, b));
    pos[i][a] = siz(Q[a]) - 1;
    for (int j = 1; j < 10; j++)
    {
      if (j != a)
      {
        pos[i][j] = -1;
      }
    }
  }
  dp[0][1][0] = 0;
  QQ.push(MP(MP(0, 0), MP(0, 1)));
  while (!QQ.empty())
  {
    pair<PII, PII> x = QQ.top();
    QQ.pop();
    PII a = x.S, p = x.F;
    p.F *= -1;
    if (p.F != dp[a.F][a.S][p.S])
    {
      continue;
    }
    //p.F = dist, p.S = ludzie, a.F = pref, a.S = pietro
    vector<int> X = getVec(p.S);
    for (int k = 1; k < 10; k++)
    {
      vector<int> XX;
      int tim = p.F;
      for (auto x : X)
      {
        if (x != k)
        {
          XX.PB(x);
        }
        else
        {
          tim++;
        }
      }
      int ii = a.F;
      while (ii + 1 <= n && siz(XX) < 4 && pos[ii + 1][k] != -1)
      {
        XX.PB(Q[k][pos[ii + 1][k]].S);
        ii++;
        tim++;
      }
      tim += abs(k - a.S);
      int pep = getInt(XX);
      //debug("go", ii, k, pep, tim);
      if (dp[ii][k].count(pep) == 0 || dp[ii][k][pep] > tim)
      {
        dp[ii][k][pep] = tim;
        QQ.push(MP(MP(-tim, pep), MP(ii, k)));
      }
    }
  }
  int res = 1e9;
  for (int i = 1; i < 10; i++)
  {
    if (dp[n][i].count(0) != 0)
    {
      res = min(res, dp[n][i][0]);
    }
  }
  printf("%d\n", res);
  return 0;
}