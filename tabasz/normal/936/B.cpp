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
const int M = 1024 * 256;

int dist[2][M];
int n, m;
vector<int> V[M];
bool draw = false, onPath[M];

void DFS(int v, int ind, int pre)
{
  if (dist[ind][v] != -1)
  {
    if (onPath[v])
    {
      draw = true;
    }
    return;
  }
  onPath[v] = true;
  dist[ind][v] = pre;
  for (auto u : V[v])
  {
    DFS(u, 1 - ind, v);
  }
  onPath[v] = false;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
  {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < a; j++)
    {
      int b;
      scanf("%d", &b);
      V[i].PB(b);
    }
  }
  int st;
  scanf("%d", &st);
  for (int i = 1; i <= n; i++)
  {
    dist[1][i] = -1;
    dist[0][i] = -1;
  }
  DFS(st, 0, 0);
  
  for (int i = 1; i <= n; i++)
  {
    if (siz(V[i]) == 0 && dist[1][i] != -1)
    {
      vector<int> R;
      int ind = i, qwe = 1;
      while (ind != 0)
      {
        R.PB(ind);
        ind = dist[qwe][ind];
        qwe = 1 - qwe;
      }
      printf("Win\n");
      for (int j = siz(R) - 1; j >= 0; j--)
      {
        printf("%d ", R[j]);
      }
      printf("\n");
      return 0;
    }
  }
  if (draw)
  {
    printf("Draw\n");
  }
  else
  {
    printf("Lose\n");
  }
  return 0;
}