#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
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

class MinCostFlow {
  
  struct MCEdge {
    int to, cost, flow;
    MCEdge* next;
    MCEdge(){}
    MCEdge(int t, int c, int f) : to(t), cost(c), flow(f) {}
  };
  
  const int Infty = 1e18;
  
  vector<vector<MCEdge*>> adjList;
  int N, Source, Sink;
  vector<int> dist;
  vector<MCEdge*> prev, Edges;
  
  void spfa() {
    queue<int> Q; vector<bool> onQueue(N); fill(ALL(dist), Infty);
    Q.push(Source); onQueue[Source] = true; dist[Source] = 0;
    while (!Q.empty()) {
      int v = Q.front(); Q.pop(); onQueue[v] = false;
      for (MCEdge *E : adjList[v]) {
        int s = E->to;
        if (E->flow == 0) { continue; }
        
        int newDist = dist[v] + E->cost;
        if (newDist < dist[s]) {
          dist[s] = newDist;
          prev[s] = E->next;
          if (!onQueue[s]) {
            Q.push(s); onQueue[s] = true;
          }
        }
      }
    }
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
  MinCostFlow(){N=0;}
  ~MinCostFlow(){
    for(MCEdge* E: Edges)
      delete E;
  }
  int numEdges = 0;
  
  void fit(int size) {
    if (size > N) {
      N = size;
      dist.resize(size); prev.resize(size); adjList.resize(size);
    }
  }
  
  void add_edge(int u, int v, int flow, int cost, int bi_dir = 0){
    fit(max(u, v) + 1);
    numEdges++;
    MCEdge * E1, * E2;
    E1 = new MCEdge(v, cost, flow);
    if (bi_dir == 0) {
      E2 = new MCEdge(u, -cost, 0);
    } else {
      E2 = new MCEdge(u, -cost, flow);
    }
    Edges.push_back(E1);
    Edges.push_back(E2);
    E1->next = E2;
    E2->next = E1;
    adjList[u].push_back(E1);
    adjList[v].push_back(E2);
  }
  
  pair<int,PII> get_min_cost_flow(int s, int t){
    fit(max(s, t) + 1);
    //cout << numEdges << endl;
    Source = s; Sink = t;
    int cost = 0, flow = 0;
    
    spfa();
    
    if(dist[Sink] > Infty/2) return {0,{0, 0}};
    int sinkCost = reduce_cost();
    
    int best_cost = 0;
    while(true){
      dijkstra_shortest_path();
      if(dist[Sink] > Infty/2) break;
      sinkCost += reduce_cost();
      if (sinkCost >= 0) { break; }
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
      mini(best_cost, cost);
    }
    
    return {flow, {cost, best_cost}};
  }
};

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  VVI a(n + 2, VI(n + 2));
  VVI id(n + 2, VI(n + 2));
  RE (i, n) {
    RE (j, n) {
      cin>>a[i][j];
    }
  }
  int sum = 0;
  RE (i, n) {
    RE (j, n) {
      id[i][j] = n * (i - 1) + j;
      FOR (ni, i - 1, i + 1) {
        FOR (nj, j - 1, j + 1) {
          if (ni >= 1 && ni <= n && nj <= n && nj >= 1 && abs(i - ni) + abs(j - nj) == 1 && MP(i, j) < MP(ni, nj) && a[i][j] > 0 && a[ni][nj] > 0) {
            sum += abs(a[i][j] - a[ni][nj]);
          }
        }
      }
    }
  }
  debug(sum);
  
  MinCostFlow flow;
  int s = n * n + 1;
  int t = n * n + 2;
  
  FOR (i, 2, n - 1) {
    if (a[2][i] == 0) {
      flow.add_edge(s, id[2][i], 1, -a[1][i]);
      flow.add_edge(id[2][i], t, 1, a[1][i]);
    }
    if (a[n - 1][i] == 0) {
      flow.add_edge(s, id[n - 1][i], 1, -a[n][i]);
      flow.add_edge(id[n - 1][i], t, 1, a[n][i]);
    }
    if (a[i][2] == 0) {
      flow.add_edge(s, id[i][2], 1, -a[i][1]);
      flow.add_edge(id[i][2], t, 1, a[i][1]);
    }
    if (a[i][n - 1] == 0) {
      flow.add_edge(s, id[i][n - 1], 1, -a[i][n]);
      flow.add_edge(id[i][n - 1], t, 1, a[i][n]);
    }
  }
  FOR (i, 2, n - 1) {
    FOR (j, 2, n - 1) {
      REP (tr, 2) {
        int ni = i;
        int nj = j;
        if (tr == 0) {
          ni++;
        } else {
          nj++;
        }
        if (a[i][j] == 0 && a[ni][nj] == 0) {
          flow.add_edge(id[i][j], id[ni][nj], 1, 0, 1);
          //flow.add_edge(id[ni][nj], id[i][j], 1, 0);
        }
      }
    }
  }
  auto heh = flow.get_min_cost_flow(s, t);
  debug(heh);
  cout<<sum - heh.nd.nd<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}