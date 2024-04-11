#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

template< typename flow_t >
struct FordFulkerson {
  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
  };

  vector< vector< edge > > graph;
  vector< int > used;
  const flow_t INF;
  int timestamp;

  FordFulkerson(int n) : INF(numeric_limits< flow_t >::max()), timestamp(0) {
    graph.resize(n);
    used.assign(n, -1);
  }

  void add_edge(int from, int to, flow_t cap) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true});
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    used[idx] = timestamp;
    for(auto &e : graph[idx]) {
      if(e.cap > 0 && used[e.to] != timestamp) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    for(flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) {
      flow += f;
    }
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

int main(){
  int n,h,m;
  cin >> n >> h >> m;
  FordFulkerson<int> ff(n*(h+2)+m+2);
  int sz=n*(h+2);
  int s=sz+m,t=sz+m+1;
  int rw=n*h*h;
  for(int i=0;i<n;i++){
    ff.add_edge(s,i*(h+2),IINF);
  }
  for(int i=0;i<n;i++){
    ff.add_edge((i+1)*(h+2)-1,t,IINF);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=h;j++){
      ff.add_edge(i*(h+2)+j,i*(h+2)+j+1,h*h-j*j);
    }
  }
  int l,r,x,c;
  for(int i=0;i<m;i++){
    cin >> l >> r >> x >> c;
    ff.add_edge(sz+i,t,c);
    for(int j=l-1;j<r;j++){
      if(x<h) ff.add_edge(j*(h+2)+x+1,sz+i,IINF);
    }
  }
  cout << rw-ff.max_flow(s,t) << endl;
  return 0;
}