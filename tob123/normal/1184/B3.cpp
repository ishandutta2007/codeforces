#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int INF2 = 100000;
int N, M;
int S, B;
ll K, H;
ll G[110][110];
vector<tuple<int,int,int,int,int>> sh;
vector<tuple<int,int,int>> bases;
ll maxR[110];
int in[100010];
int mapTo[100010];
vector<int> P2[100010];
vector<int> P[100010];
ll R[100010], R2[100010];
ll RESULT;
int newSI[100010];

typedef long long LL;

// Adjacency list implementation of FIFO push relabel maximum flow
// with the gap relabeling heuristic.  This implementation is
// significantly faster than straight Ford-Fulkerson.  It solves
// random problems with 10000 vertices and 1000000 edges in a few
// seconds, though it is possible to construct test cases that
// achieve the worst-case.
// Running time:
//     O(|V|^3)
// INPUT:
//     - graph, constructed using AddEdge()
//     - source, sink
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).

const LL INF = 1e15;
struct Edge {
  int from, to;
  LL cap, flow;
  int index;
  Edge(int from, int to, LL cap, LL flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N; vector<vector<Edge> > G; vector<LL> excess;
  vector<int> dist, active, count; queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, LL cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }

  void Push(Edge &e) {
    LL amt = min(excess[e.from], LL(e.cap - e.flow));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++)
      if (G[v][i].cap - G[v][i].flow > 0)
  dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1)
  Gap(dist[v]);
      else
  Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};




void main2(int NN){
  /*
  for(int i=0; i<NN; i++){
    cout << R[i] << " (" << i << "): ";
    for(int x : P[i]){
      cout << x << " ";
    }
    cout << endl;
  }
  cout << "RES: " << RESULT << endl;
  */

  NN += 2;
  int source = NN-2, sink = NN-1;
  auto PR = PushRelabel(NN);
  ll sum = 0;
  for(int v= 0; v < NN-2;++v){
    if(R[v] >= 0){
      PR.AddEdge(source, v, R[v]);
      sum += R[v];
    }else{
      PR.AddEdge(v, sink, -R[v]);
    }
    for(int c : P[v]){
      PR.AddEdge(v, c, INF);
    }
  }
  LL res = sum-PR.GetMaxFlow(source, sink);
  cout << res + RESULT << endl;
}

int main(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      G[i][j] = INF;
    }
    G[i][i] = 0;
  }
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u][v] = 1;
    G[v][u] = 1;
  }
  cin >> S >> B >> K;
  for(int i=0; i<S; i++){
    int x, a, f, p;
    cin >> x >> a >> f >> p;
    x--;
    sh.push_back(make_tuple(a, x, f, p, i));
  }
  for(int i=0; i<B; i++){
    int x, d, g;
    cin >> x >> d >> g;
    x--;
    bases.push_back(make_tuple(d,x,g));
  }
  sort(sh.begin(), sh.end());
  sort(bases.begin(), bases.end());
  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
      }
    }
  }
  int bi=0;
  for(int i=0; i<N; i++){
    maxR[i] = -INF;
  }
  for(int i=0; i<S; i++){
    R2[i] = -INF;
    int xs, a, f, p, shInd;
    tie(a, xs, f, p, shInd) = sh[i];
    newSI[shInd] = i;
    for(; bi<B; bi++){
      int xb, d, g;
      tie(d, xb, g) = bases[bi];
      if(a < d){
        break;
      }
      maxR[xb] = max(maxR[xb], (ll)g);
    }
    //cout << "ship " << i << ": ";
    for(int j=0; j<N; j++){
      if(G[xs][j] <= f){
        //cout << "(->" << j << " " << maxR[j] << ") ";
        R2[i] = max(R2[i], maxR[j]-p);
      }
    }
    //cout << endl;
    //cout << R2[i] << " ";
  }
  //cout << endl;
  for(int i=0; i<K; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    P2[newSI[u]].push_back(newSI[v]);
    in[newSI[v]]++;
    in[newSI[u]]++;
  }
  int cnt = 0;
  for(int i=0; i<S; i++){
    if(in[i]){
      R[cnt] = R2[i];
      mapTo[i] = cnt++;
    }
    else{
      RESULT += max(R2[i], 0ll);
    }
  }
  for(int i=0; i<S; i++){
    if(in[i]==0)
      continue;
    for(int x : P2[i]){
      P[mapTo[i]].push_back(mapTo[x]);
    }
  }
  main2(cnt);

  return 0;
}