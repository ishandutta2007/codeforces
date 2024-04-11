/* Zadanie PRZ
 * Rozwiazanie wzorcowe O(m)
 * Autor: Wojtek Nadara
 * Data: 11.01.2015
 */

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
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
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

const int N = 2e5 + 5;
int need_inc[N];

struct Edge {
  int a, b, c, inv;
};
Edge edge[N];
vector<int> adj[N];
vector<int> slo[N];
int vis[N];
int Dfs(int v) {
  vis[v] = 1;
  int acc = 1;
  for (auto nei : slo[v]) {
    if (!vis[nei]) {
      acc += Dfs(nei);
    }
  }
  return acc;
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, m);
  if (m == 0) {
    cout<<"TAK\n";
    return 0;
  }
  RE (i, m) {
    make3(int, a, b, c);
    edge[i] = Edge{a, b, c, -1};
    adj[a].PB(i);
    adj[b].PB(i);
    need_inc[a] += c;
    need_inc[b] += c;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  int cc_sz = Dfs(1);
  debug(cc_sz);
  if (vis[n] == 0) {
    cout<<"NIE\n";
    return 0;
  }
  vector<int> que{1};
  for (int ii = 0; ii < SZ(que); ii++) {
    int v = que[ii];
    for (auto ei : adj[v]) {
      Edge& e = edge[ei];
      int nei = e.a + e.b - v;
      if (e.inv != -1) { continue; }
      e.inv = (e.a != v);
      need_inc[nei] -= 2 * e.c;
      if (need_inc[nei] == 0 && nei != n) {
        que.PB(nei);
      }
    }
  }
  if (SZ(que) != cc_sz - 1) {
    cout<<"NIE\n";
    debugv(que);
    return 0;
  }
  //cout<<"TAK\n";
  RE (i, m) {
    cout<<edge[i].inv<<" ";
  }
  cout<<"\n";
  
  

  return 0;
}