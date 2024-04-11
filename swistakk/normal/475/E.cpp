#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#include <complex>
#define MP make_pair
#define PB push_back
#define int long long
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::complex;
using std::sort;
using std::fill;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PII;
typedef pair<ll, ll> PLL;
typedef vector<ll> VI;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int N = 3e3;
vector<int> slo[5015];
int kraw[1005*1005][3];
int odw[5015];
int odw2[5015];
int low[5005];
int par[5015];
int ktoss[5015];
int degs[5015];
int newv, minlow;
int pre[5015];
int d=1;

int cc_sz[N];
void DFS(int v)
{
  pre[v]=d;
  low[v]=d;
  odw[v]=1;
  d++;
  for(int i=0; i<slo[v].size(); i++)
  {
    if(kraw[slo[v][i]][0]==v)
    {
      newv=kraw[slo[v][i]][1];
    }
    else
    {
      newv=kraw[slo[v][i]][0];
    }
    if(odw[newv]==0)
    {
      par[newv]=v;
      DFS(newv);
      if(kraw[slo[v][i]][0]==v)
      {
        newv=kraw[slo[v][i]][1];
      }
      else
      {
        newv=kraw[slo[v][i]][0];
      }
      if(low[newv]<low[v])
      {
        low[v]=low[newv];
      }
    }
    else
    {
      if(pre[newv]<low[v] && par[v]!=newv)
      {
        low[v]=pre[newv];
      }
    }
  }
}
void DFS2(int v)
{
  odw2[v]=1;
  for(int i=0; i<slo[v].size(); i++)
  {
    if(kraw[slo[v][i]][0]==v)
    {
      newv=kraw[slo[v][i]][1];
    }
    else
    {
      newv=kraw[slo[v][i]][0];
    }
    if(odw2[newv]==0)
    {
      DFS2(newv);
      if(kraw[slo[v][i]][0]==v)
      {
        newv=kraw[slo[v][i]][1];
      }
      else
      {
        newv=kraw[slo[v][i]][0];
      }
      if(low[newv]==pre[newv])
      {
        kraw[slo[v][i]][2]=1;
        // cout<<slo[v][i]<<" "<<v<<" "<<newv<<endl;
      }
    }
  }
}
void DFS3(int v, int licz)
{
  ktoss[v]=licz;
  cc_sz[licz]++;
  cerr<<v<<" ";
  for(int i=0; i<slo[v].size(); i++)
  {
    if(kraw[slo[v][i]][0]==v)
    {
      newv=kraw[slo[v][i]][1];
    }
    else
    {
      newv=kraw[slo[v][i]][0];
    }
    if( kraw[ slo[v][i] ][2]==0 && ktoss[newv]==0)
    {
      DFS3(newv, licz);
    }
  }
}



vector<int> SLO[N];
int dp[N];
int dep[N];
int sz[N];
int kub[N];
typedef long long ll;
void dfs1(int v) {
  sz[v] = cc_sz[v];
  for (int i = 0; i < SLO[v].size(); i++) {
    int nei = SLO[v][i];
    if (sz[nei] == 0) {
      dfs1(nei);
      sz[v] += sz[nei];
    }
  }
}
ll dfs2(int v, int dept) {
  ll to_ret = dept * cc_sz[v];
  dep[v] = dept;
  for (int i = 0; i < SLO[v].size(); i++) {
    int nei = SLO[v][i];
    if (dep[nei] == -1) {
      to_ret += dfs2(nei, dept + cc_sz[v]);
    }
  }
  return to_ret;
}
int knapsack(vector<int> s, int n) {
  for (int i = 0; i < n + 2; i++) {
    dp[i] = 0;
    kub[i] = 0;
  }
  dp[0] = -1;
  for (int i = 0; i < s.size(); i++) {
    kub[s[i]]++;
  }
  
  for (int i = 1; i < n + 2; i++) {
    if (kub[i] == 0) {
      continue;
    }
    for (int res = 0; res < i; res++) {
      int sum = 0;
      for (int k = 0; k < (n + 2) / i; k++) {
        int act_pos = k * i + res;
        if (sum > 0 && dp[act_pos] == 0) {
          dp[act_pos] = i;
        }
        if (dp[act_pos] < i && dp[act_pos]) {
          sum++;
        }
        if (k >= kub[i] && dp[(k - kub[i]) * i + res] < i && dp[(k - kub[i]) * i + res]) {
          sum--;
        }
      }
    }
  }
  for (int i = n / 2; i >= 0; i--) {
    if (dp[i]) {
      return i;
    }
  }
}



#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, v, e);
  for(int i=1; i<=e; i++)
  {
    int v1, v2;
    cin>>v1>>v2;
    kraw[i][0]=v1;
    kraw[i][1]=v2;
    slo[v1].push_back(i);
    slo[v2].push_back(i);
  }
  DFS(1);
  DFS2(1);
  int licz=1;
  for(int i=1; i<=v; i++)
  {
    if(ktoss[i]==0)
    {
      DFS3(i, licz);
      cerr<<endl;
      licz++;
    }
  }
  for(int i=1; i<=e; i++)
  {
    if(kraw[i][2]==1)
    {
      int a = ktoss[kraw[i][0]];
      int b = ktoss[kraw[i][1]];
      debug2(kraw[i][0], kraw[i][1]);
      SLO[a].PB(b);
      SLO[b].PB(a);
      debug2(a, b);
//       slo[ktoss[kraw[i][0]]].PB(kraw[i]
//       degs[ ktoss[ kraw[i][0] ]]++;
//       degs[ ktoss[ kraw[i][1] ]]++;
    }
  }
  int n = licz - 1;
  RE (i, n) {
    cerr<<cc_sz[i]<<" ";
  }
  cerr<<endl;
  if (n == 1) {
    cout<<v * v<<endl;
    return 0;
  }
  
  int dupa = 0;
  RE (i, n) {
    dupa += cc_sz[i] * cc_sz[i];
  }
  
    
    
    
    
    
    
    
    
    
//   for (int i = 1; i <= n - 1; i++) {
//     int a, b;
//     cin>>a>>b;
//     SLO[a].PB(b);
//     SLO[b].PB(a);
//   }
  dfs1(1);
  
  ll best = 0;
  for (int i = 1; i <= n; i++) {
    int largest = 0;
    vector<int> son_sizes;
    for (int j = 0; j < SLO[i].size(); j++) {
      int son_size = sz[SLO[i][j]];
      if (son_size > sz[i]) {
        son_size = v - sz[i];
      }
      son_sizes.PB(son_size);
      if (largest < son_size) {
        largest = son_size;
      }
    }
    if (largest > v / 2) {
      continue;
    }
    cerr<<i<<" is centroid"<<endl;
    fill(dep, dep + v + 1, -1);
    ll res = dfs2(i, 0);
    cerr<<"depths sum: "<<res<<endl;
    ll kn = knapsack(son_sizes, v - cc_sz[i]);
    best = max(best, res + kn * (v - cc_sz[i] - kn));
  }
  cout<<best + dupa<<endl;
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}