#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA...a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream&operator<<(ostream&os, vector<T> V) {
  os<<"[";
  for (auto v : V)os<<v<<",";
  return os << "]";
}
template<class L, class R> ostream&operator<<(ostream&os, pair<L,R> P) {
  return os<<"("<<P.st<<","<<P.nd<<")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 505;

int N;
vector<int> adj[MaxN];

void Input() {
  int M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int t, a;
    cin >> t >> a;
    for (int j = 1; j < t; ++j) {
      int b;
      cin >> b;
      adj[a].PB(b);
      adj[b].PB(a);
      a = b;
    }
  }
}

int available[MaxN];
int iter_idx;
int dist[MaxN];
vector<int> bests[MaxN];
int neigh_counts[MaxN];
vector<int> cur_avail;
map<VI, int> query_memo;

void FindBestFor(int v) {
  debug(v, N);
  fill_n(dist, N + 1, 1e9);
  for (int i = 1; i <= N; ++i)
    bests[i].clear();
  dist[v] = 0;
  queue<int> Q;
  for (int s : adj[v]) {
    if (available[s] != iter_idx) { continue; }
    dist[s] = 1;
    bests[s].PB(s);
    Q.push(s);
  }
  
  while (!Q.empty()) {
    const int s = Q.front();
    Q.pop();
    
    for (int neigh : adj[s]) {
      if (available[neigh] != iter_idx) { continue; }
      if (dist[neigh] > dist[s] + 1) {
        dist[neigh] = dist[s] + 1;
        Q.push(neigh);
        bests[neigh] = bests[s];
      } else if (dist[neigh] == dist[s] + 1) {
        if (bests[s] == bests[neigh]) { continue; }
        vector<int> old_bests;
        swap(old_bests, bests[neigh]);
        set_union(ALL(old_bests), ALL(bests[s]), back_inserter(bests[neigh]));
      }
    }
  }
  
  /*for (int i = 1; i <= N; ++i)
    if (available[i] == iter_idx) */
}

int FindBest() {
  auto iter = query_memo.find(cur_avail);
  if (iter != query_memo.end())
    return iter->second;
  
  int best_max = 1e9;
  int best_who = -1;
  
  for (int v : cur_avail) {
  //for (int v = 1; v <= N; ++v) {
    if (available[v] != iter_idx) { continue; }
    FindBestFor(v);
    
    for (int s : cur_avail)
      neigh_counts[s] = 0;
    
    for (int i : cur_avail) {
      for (int b : bests[i])
        ++neigh_counts[b];
    }
    
    int worst_case = 0;
    for (int s : adj[v]) {
      if (available[s] != iter_idx) { continue; }
      maxi(worst_case, neigh_counts[s]);
    }
    
    debug(v, worst_case);
    
    if (worst_case < best_max) {
      best_max = worst_case;
      best_who = v;
    }
  }
  assert(best_who != -1);
  
  return query_memo[cur_avail] = best_who;
}

void DoSearch() {
  iter_idx = 1;
  cur_avail.resize(N);
  iota(ALL(cur_avail), 1);
  fill_n(available + 1, N, iter_idx);
  
  while (SZ(cur_avail) > 1) {
    const int v = FindBest();
    cout << v << endl;
    string s;
    cin >> s;
    if (s == "FOUND") { return; }
    int nxt;
    cin >> nxt;
    
    FindBestFor(v);
    ++iter_idx;
    
    VI next_avail;
    for (int i : cur_avail)
      if (count(ALL(bests[i]), nxt)) {
        debug(i);
        available[i] = iter_idx;
        next_avail.PB(i);
      }
    cur_avail = next_avail;
  }
  
  int which = cur_avail[0];
  
  cout << which << endl;
  string s;
  cin >> s;
  assert(s == "FOUND");
}

int32_t main() {
  Input();
  for (int i = 0; i < N; ++i)
    DoSearch();
}