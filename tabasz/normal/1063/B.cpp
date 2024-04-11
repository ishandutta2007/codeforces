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

const int M = 1024 * 2;
const int inf = 1e7;

char C[M];
int dist[M][M];
int T[M][M];
int n, m, r, c, x, y, res;
priority_queue<pair<int, PII>> Q;
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

void dijkstra(PII v)
{
  Q.push(MP(0, v));
  
  while (!Q.empty())
  {
    PII p = Q.top().S;
    int d = -Q.top().F;
    Q.pop();
    
    if (dist[p.F][p.S] != d)
    {
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      PII pp = MP(p.F + mx[i], p.S + my[i]);
      if (!T[pp.F][pp.S])
      {
        continue;
      }
      int dd = d;
      if ((p.S > c && i == 3) || (p.S < c && i == 1))
      {
        dd++;
      }
      if (dist[pp.F][pp.S] > dd)
      {
        dist[pp.F][pp.S] = dd;
        Q.push(MP(-dd, pp));
      }
    }
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
  for (int i = 1; i <= n; i++)
  {
    scanf("%s", C);
    for (int j = 1; j <= m; j++)
    {
      if (C[j - 1] == '.')
      {
        T[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < M; i++)
  {
  	for (int j = 0; j < M; j++)
  	{
  		dist[i][j] = inf;
  	}
  }
  dist[r][c] = 0;
  
  dijkstra(MP(r, c));
  
  for (int i = 1; i <= n; i++)
  {
  	for (int j = 1; j <= m; j++)
  	{
  		int xx = dist[i][j];
  		int yy = dist[i][j];
  		if (dist[i][j] == inf)
  		{
  		  continue;
  		}
  		///debug(i, j, dist[i][j]);
  		//cerr << dist[i][j] << " ";
  		if (j <= c)
  		{
  			xx += c - j;
  		}
  		else
  		{
  			yy += j - c;
  		}
  		if (xx <= x && yy <= y)
  		{
  			res++;
  		}
  	}
  	//cerr << "\n";
  }
  printf("%d\n", res);
  return 0;
}