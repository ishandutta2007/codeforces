#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LL long long
#define FI first
#define SE second
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>
#define st first
#define nd second
#define rd third

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0) cout
#endif

template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
  template<class T> void ResizeVec(T&, vector<int>) {}
  template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
    vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
    for (T& v : vec) { ResizeVec(v, sz); }
  }
  typedef Triple<int, int, int> TIII;
  template<class A, class B, class C>
  ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
  template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }


typedef long double D;
const D eps = 1e-8;
const D inf = 1e14;

class MinCostFlow {
  
  struct MCEdge {
    int to, cost, flow;
    MCEdge* next;
    MCEdge(){}
    MCEdge(int t, int c, int f) : to(t), cost(c), flow(f) {}
  };
  
  const int Infty = 1010101010;
  
  vector<vector<MCEdge*>> adjList;
  int N, Source, Sink;
  vector<int> dist;
  vector<MCEdge*> prev, Edges;
  
  inline bool zero_edge(MCEdge& E){
    return (E.flow == 0);
  }
  
  bool bellman_improve(){
    bool result = false;
    for(int v = 0; v < N; v++){
      for(MCEdge* E: adjList[v]){
        int s = E->to;
        if(E->flow == 0) continue;
        
        int newDist = dist[v] + E->cost;
        if(newDist < dist[s]){
          dist[s] = newDist;
          prev[s] = E->next;
          result  = true;
        }
      }
    }
    return result;
  }
  
  void bellman_shortest_path(){
    fill(dist.begin(), dist.end(), Infty);
    dist[Source] = 0;
    
    int maxImprove = N;
    while(bellman_improve() && maxImprove--);
  }
  
  int reduce_cost(){
    int result = dist[Sink];
    for(int v = 0; v < N; v++){
      for(MCEdge* E: adjList[v]){
        E->cost += dist[v] - dist[E->to];
      }
    }
    return result;
  }
  
  void dijkstra_shortest_path(){
    fill(dist.begin(), dist.end(), Infty);
    dist[Source] = 0;
    
    priority_queue<pair<int,int>> Q;
    Q.push(make_pair(0, Source));
    
    while(!Q.empty()){
      int dst, v;
      tie(dst, v) = Q.top(); Q.pop();
      dst = -dst;
      if(dst != dist[v]) continue;
      
      for(MCEdge* E: adjList[v]){
        int s = E->to;
        if(E->flow == 0) continue;
        
        int newDist = dist[v] + E->cost;
        if(newDist < dist[s]){
          dist[s] = newDist;
          prev[s] = E->next;
          Q.push(make_pair(-newDist, s));
        }
      }
    }
  }
  
public:
  MinCostFlow(){}
  MinCostFlow(int _N){
    N = _N;
    dist = vector<int>(N, 0);
    prev.resize(N);
    adjList.resize(N);
    sinkCost = 0;
  }
  ~MinCostFlow(){
    for(MCEdge* E: Edges)
      delete E;
  }
  int numEdges = 0;
  
  void add_edge(int u, int v, int flow, int cost){
    numEdges++;
    MCEdge * E1, * E2;
    E1 = new MCEdge(v, cost, flow);
    E2 = new MCEdge(u, -cost, 0);
    Edges.push_back(E1);
    Edges.push_back(E2);
    E1->next = E2;
    E2->next = E1;
    adjList[u].push_back(E1);
    adjList[v].push_back(E2);
  }
  int sinkCost;
  pair<int,int> get_min_cost_flow(int s, int t){
    //cout << numEdges << endl;
    Source = s; Sink = t;
    int cost = 0, flow = 0;
    
    bellman_shortest_path();
    
    if(dist[Sink] > Infty/2) return {0,0};
    sinkCost += reduce_cost();
    
    while(true){
      dijkstra_shortest_path();
      if(dist[Sink] > Infty/2) break;
      sinkCost += reduce_cost();
      
      int maxSend = Infty;
      for(int v = Sink; v != Source; v = prev[v]->to){
        maxSend = min(maxSend, prev[v]->next->flow);
      }
      
      for(int v = Sink; v != Source; v = prev[v]->to){
        MCEdge* E1 = prev[v];
        MCEdge* E2 = E1->next;
        E1->flow += maxSend;
        E2->flow -= maxSend;
      }
      
      flow += maxSend;
      cost += maxSend * sinkCost;
    }
    
    return {flow, cost};
  }
};
typedef long double LD;
#define MAX 2501
int n,m,s,t;
int a[MAX],b[MAX],c[MAX],d[MAX];
// D licz(int z){
//   
//   MCF.add_edge(t, n, z, 0);
//   auto flow_cost = MCF.get_min_cost_flow(s, n);
//   if(flow_cost.first < z)
//     return inf;
//   else
//     return D(flow_cost.second + p) / z;
// }

const int W = 1e5 + 5;
//LD res[W];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  
  cin >> n >> m;
  s = 0;
  t = n - 1;
  R(i,m){
    cin >> a[i] >> b[i] >> d[i];
    c[i] = 1;
    a[i]--;
    b[i]--;
  }
  MinCostFlow MCF(n + 1);
  R(i,m)
  MCF.add_edge(a[i], b[i], c[i], d[i]);
//   {
//     MCF.add_edge(t, n, 2, 0);
//     debug(MCF.get_min_cost_flow(s, n));
//     return 0;
//   }
  VI flow_costs{0};
  while (1) {
    MCF.add_edge(t, n, 1, 0);
    auto flow_cost = MCF.get_min_cost_flow(s, n);
    debug(flow_cost);
    //auto flow2 = MCF.get_min_cost_flow(s, n);
    //debug(flow2);
    if (flow_cost.first == 1) {
      flow_costs.PB(flow_costs.back() + flow_cost.second);
    } else {
      break;
    }
  }
  debug(flow_costs);
  
  
  int q;
  cin>>q;
  RE (ii, q) {
    int p;
    cin>>p;
    int po = 1, ko = SZ(flow_costs);
    function<LD(int)> licz = [&](int z) {
      return LD(flow_costs[z] + p) / z;
    };
    while((ko - po) > 3){
      debug(po,ko);
      int m1 = (po+ko)/2;
      D w1 = licz(m1);
      if(w1 > inf / 10){
        ko = m1;
        continue;
      }
      int m2 = m1 + 1;
      LD w2 = licz(m2);
      if(w2 < w1){
        po = m1;
      }else
        ko = m2;
    }
    D res = inf;
    for(int i = po; i < ko; i++){
      LD cand = licz(i);
      debug(i, cand, flow_costs[i], p);
      mini(res,cand);
    }
    cout << res << "\n";
    //cout<<res[ask]<<"\n";
  }
  
//   int q;
//   cin>>q;
//   RE (ii, q) {
//     cin>>p;
//     int po = 1, ko = 20001;
//     while((ko - po) > 3){
//       debug(po,ko);
//       int m1 = (po+ko)/2;
//       D w1 = licz(m1);
//       if(w1 > inf / 10){
//         ko = m1;
//         continue;
//       }
//       int m2 = m1 + 1;
//       D w2 = licz(m2);
//       if(w2 < w1){
//         po = m1;
//       }else
//         ko = m2;
//     }
//     D res = inf;
//     for(int i = po; i < ko; i++){
//       mini(res,licz(i));
//     }
//     cout << res << endl;
//   }
  
}