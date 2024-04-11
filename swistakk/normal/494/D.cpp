#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
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
using std::bitset;
using std::abs;
using std::__gcd;
using std::unordered_set;
using std::unordered_map;
using std::sqrt;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int P = 1e9 + 7;
struct LCA {
  LCA(const vector<vector<PII> >& their_slo, int root = 1) {
    M = 1;
    while (M <= 2 * their_slo.size()) {
      M *= 2;
    }
    my_slo.resize(M);
    REP (i, their_slo.size()) {
      for (auto nei : their_slo[i]) {
        my_slo[i].PB(nei);
      }
    }
    drz.resize(2 * M + 5);
    pre.resize(M);
    inv.resize(M);
    vis.resize(M);
    ind.resize(M);
    dep.resize(M);
    d=1;
    akt=1;
    dfs(root);
    for(int i=M-1; i>=1; i--)
    {
        drz[i]=min(drz[2*i], drz[2*i+1]);
    }
  }
  int M;
  vector<int> drz;
  vector<int> pre;
  vector<int> inv;
  vector<int> vis;
  vector<int> ind;
  vector<int> dep;
  vector<vector<PII> > my_slo;
  int d;
  int akt;
  
  int Lca(int a, int b) // pobiera a i b, a zwraca ich lca (przy ukorzenieniu w jedynce (ale to mozna zmienic zapuszczajac skad inad dfsa) )
  {
      a=pre[a];
      b=pre[b];
      int w;
      w=czyt(min(ind[a], ind[b]), max(ind[a], ind[b]) );
      return inv[w];
  }
  
  int Dis(int a, int b) {
    return (dep[a] + dep[b] - 2 * dep[Lca(a, b)] + 3 * P) % P;
  }
  
private:
  int czyt(int a, int b)
  {
      a+=M-1;
      b+=M-1;
      int mini=M;
      mini=min(mini, drz[a]);
      mini=min(mini, drz[b]);
      while(a/2 != b/2)
      {
          if(a%2==0)
          {
              mini=min(mini, drz[a+1]);
          }
          if(b%2==1)
          {
              mini=min(mini, drz[b-1]);
          }
          a/=2;
          b/=2;
      }
      return mini;
  }
  void dfs(int v)
  {
    vis[v]=1;
    pre[v]=d;
    inv[d]=v;
    d++;
    drz[akt+M-1]=pre[v];
    ind[pre[v]]=akt;
    akt++;
    for (auto p : my_slo[v]) {
      int nei = p.st;
      int w = p.nd;
      if (vis[nei]) {
        continue;
      }
      dep[nei] = (dep[v] + w) % P;
      dfs(nei);
      drz[akt+M-1]=pre[v];
      ind[pre[v]]=akt;
      akt++;
    }
  }
}; 

const int N = 1e5 + 5;
vector<vector<PII>> slo;
int sum_down[N][3];
int sum_all[N][3];
int vis[N];
int d;
int pre[N];
int post[N];
void Dfs1(int v) {
  vis[v] = 1;
  pre[v] = d;
  d++;
  sum_down[v][0] = 1;
  for (auto p : slo[v]) {
    int nei = p.st;
    int w = p.nd;
    if (vis[nei]) { continue; }
    Dfs1(nei);
    sum_down[v][0] += sum_down[nei][0];
    sum_down[v][1] += w * sum_down[nei][0] + sum_down[nei][1];
    sum_down[v][2] += w * w % P * sum_down[nei][0] + 2 * w * sum_down[nei][1] + sum_down[nei][2];
    REP (tr, 3) {
      sum_down[v][tr] %= P;
    }
  }
  post[v] = d;
  d++;
  debug(v);
  debug3(sum_down[v][0], sum_down[v][1], sum_down[v][2]);
}

void Dfs2(int v, int n) {
  vis[v] = 1;
  for (auto p : slo[v]) {
    int nei = p.st;
    int w = p.nd;
    if (vis[nei]) { continue; }
    sum_all[nei][1] = sum_all[v][1] + (n - 2 * sum_down[nei][0] + 2 * P) % P * w;
    sum_all[nei][2] = sum_all[v][2] + (n - 2 * sum_down[nei][0] + 2 * P) % P * w % P * w % P
        + 2 * w * ((sum_all[v][1] - sum_down[nei][1] - w * sum_down[nei][0] % P - sum_down[nei][1] + 5 * P) % P) % P;
    REP (tr, 3) {
      sum_all[nei][tr] %= P;
    }
    debug(nei);
    debug3(sum_all[nei][0], sum_all[nei][1], sum_all[nei][2]);
    Dfs2(nei, n);
  }
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  slo.resize(n + 5);
  RE (i, n - 1) {
    make3(int, a, b, c);
    slo[a].PB(MP(b, c));
    slo[b].PB(MP(a, c));
  }
  LCA lca(slo);
  Dfs1(1);
  RE (i, n) {
    vis[i] = 0;
    sum_all[i][0] = n;
  }
  REP (tr, 3) {
    sum_all[1][tr] = sum_down[1][tr];
  }
  Dfs2(1, n);
  
  make(int, q);
  RE (i, q) {
    make2(int, u, v);
    debug2(u, v);
    int dis = lca.Dis(u, v);
    if (pre[u] >= pre[v] && post[u] <= post[v]) {
      cout<<((sum_all[u][2] - 2 * (sum_all[v][2] - sum_down[v][2] + (n - sum_down[v][0]) * dis % P * dis +
          + (sum_all[v][1] - sum_down[v][1]) * 2 * dis )) % P + P) % P<<"\n";
    } else {
      
      //debug3(u, v, dis);
      cout<<((-sum_all[u][2] + 2 * (sum_down[v][2] + 2 * dis % P * sum_down[v][1] % P + dis * dis % P * sum_down[v][0])) % P + P) % P<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}