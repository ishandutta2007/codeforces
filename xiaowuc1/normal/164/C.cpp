#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct Edge {
  int i, j;
  ll cap, flow, cost;
  Edge *rev;
  Edge(int ii, int jj, ll cc, ll ff, ll C) {
    i = ii;
    j = jj;
    cap = cc;
    flow = ff;
    cost = C;
    rev = NULL;
  }
};

struct MinCostMaxFlow {
  int n;
  vector<ll> ex;
  vector<vector<Edge*>> adj;

  MinCostMaxFlow(int NN) {
    n = NN;
    ex.resize(n);
    adj.resize(n);
  }

  void AddEdge(int i, int j, ll cap, ll cost) {
    Edge *forward = new Edge(i, j, cap, 0, cost);
    Edge *reverse = new Edge(j, i, 0, 0, -cost);
    forward->rev = reverse;
    reverse->rev = forward;
    adj[i].push_back(forward);
    adj[j].push_back(reverse);
  }

  pair<ll, ll> GetMaxFlow(int source, int sink) {
    vector<bool> canU;
    canU.resize(n);
    vector<bool> hasU;
    hasU.resize(n);
    vector<ll> dist;
    dist.resize(n);
    vector<ll> width;
    width.resize(n);
    vector<Edge*> prev;
    prev.resize(n);
    while(true) {
      for(int i = 0; i < n; i++) dist[i] = 1LL << 60;
      dist[source] = 0;
      width[source] = 1LL << 60;
      bool updated = hasU[source] = true;
      while(updated) {
        updated = false;
        for(int i = 0; i < n; hasU[i++] = false) {
          canU[i] = hasU[i];
        }
        for(int i = 0; i < n; i++) {
          if(canU[i]) {
            for(Edge* e : adj[i]) {
              if(e->flow != e->cap && dist[e->j] > dist[e->i] + e->cost) {
                dist[e->j] = dist[e->i] + (prev[e->j] = e)->cost;
                width[e->j] = min(width[e->i], e->cap - e->flow);
                hasU[e->j] = updated = true;
              }
            }
          }
        }
      }
      if(dist[sink] >= 1LL << 60) {
        break;
      }
      for(Edge* e = prev[sink]; e != NULL; e = prev[e->i]) {
        e->rev->flow = -(e->flow += width[sink]);
      }
    }
    ll flow = 0;
    ll cost = 0;
    for(Edge *e: adj[source]) {
      if(e->flow > 0) {
        flow += e->flow;
      }
    }
    for(int i = 0; i < n; i++) {
      for(Edge* e : adj[i]) {
        if(e->flow > 0 && e->i != sink && e->j != source) {
          cost += e->flow * e->cost;
        }
      }
    }
    return {flow, cost};
  }
};

int startT[1005];
int duration[1005];
int profit[1005];
int orig[1005];
int ret[1005];

void solve() {
  int n, k;
  cin >> n >> k;
  /*
  construction is
  0 is source
  2*n-1 and 2*n are machines
  2*n-1 to 2n cap 1 cost profit (negative!)
  2n to all 2i+1 that are feasible
  2N+1 is fake sink
  2N+2 is real sink
  2N+1 to 2N+2 with capacity k
  */
  MinCostMaxFlow mcmf(2*n+3);
  for(int i = 1; i <= n; i++) {
    orig[i] = i;
    cin >> startT[i] >> duration[i] >> profit[i];
  }
  while(true) {
    bool upd = false;
    for(int i = 1; i <= n-1; i++) {
      if(startT[i] > startT[i+1]) {
        swap(startT[i], startT[i+1]);
        swap(duration[i], duration[i+1]);
        swap(profit[i], profit[i+1]);
        swap(orig[i], orig[i+1]);
        upd = true;
      }
    }
    if(!upd) break;
  }
  for(int i = 1; i <= n; i++) {
    mcmf.AddEdge(2*i-1, 2*i, 1, -profit[i]);
    mcmf.AddEdge(2*i, 2*n+1, k, 0);
    if(i == 1) mcmf.AddEdge(0, 2*i-1, k, 0);
    if(i <= n-1) mcmf.AddEdge(2*i-1, 2*i+1, k, 0);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i+1; j <= n; j++) {
      if(i == j) continue;
      if(startT[i] + duration[i] <= startT[j]) {
        mcmf.AddEdge(2*i, 2*j-1, k, 0);
        break;
      }
    }
  }
  mcmf.AddEdge(2*n+1, 2*n+2, k, 0);
  pair<ll, ll> unused = mcmf.GetMaxFlow(0, 2*n+2);
  for(int i = 1; i <= n; i++) {
    for(Edge* out: mcmf.adj[2*i-1]) {
      if(out->j == 2*i) {
        ret[orig[i]] = out->flow;
        break;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << ret[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}