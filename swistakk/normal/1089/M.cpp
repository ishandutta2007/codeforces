#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

struct SSS {
  vector<VI> d, drev; VI ord, ss, cz;
  int is,n;
  SSS(int _n):n(_n) {
    d.resize(n);drev.resize(n);cz.resize(n);ss.resize(n,-1);
  }
  void add_edge(int a, int b) {
    d[a].PB(b); drev[b].PB(a);
  }
  void dfs(int nr) {
    if (cz[nr]) return;
    cz[nr] = 1;
    for (int ak : d[nr])
      dfs(ak);
    ord.PB(nr);
  }
  void dfs2(int nr, int s) {
    if (ss[nr] != -1) { return; }
    ss[nr] = s;
    for (int ak : drev[nr])
      dfs2(ak,s);
  }
  void licz() {
    R(i,n) dfs(i);
    is = 0;
    reverse(ALL(ord));
    for (int el : ord)
      if (ss[el] == -1) {
        dfs2(el, is);
        ++is;
      }
  }
  vector<VI> stworzgraf() {
    vector<VI> res(is);
    R(i,n)for(int ak:d[i]) {
      if(ss[i] != ss[ak])
        res[ss[i]].PB(ss[ak]);
    }
    for (auto &el:res) {
      sort(ALL(el));
      el.resize(unique(ALL(el)) - el.begin());
    }
    return res;
  }
};

int N;

int can_reach[13][13];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> N;
  SSS sss(N);
  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> can_reach[i][j];
      if (can_reach[i][j])
        sss.add_edge(i, j);
    }
  }
  
  sss.licz();
  auto graph = sss.stworzgraf();
  const int S = SZ(graph);
  
  cout << N * 3 << " " << N * 3 << " " << S * 4 << "\n";
  vector<string> empty_board(N * 3, string(N * 3, '.'));
  
  auto PrintLayer = [&](const vector<string> &layer) {
    for (string s : layer)
      cout << s << "\n";
    cout << "\n";
  };
  
  for (int layer = 0; layer < S; ++layer) {
    PrintLayer(empty_board);
    
    const int X = layer * 3;
    
    auto top_layer = empty_board;
    for (int i = 0; i < N * 3; ++i) {
      if (i == X + 1) { continue; }
      top_layer[X][i] = top_layer[X + 2][i] = '#';
      top_layer[i][X] = top_layer[i][X + 2] = '#';
    }
    
    PrintLayer(top_layer);
    
    auto main_layer = top_layer;
    for (int i = 0; i < N; ++i)
      if (sss.ss[i] == layer)
        main_layer[X + 1][i] = '0' + i + 1;
    
    for (int edge : graph[layer]) {
      main_layer[X + 2][3 * edge + 1] = '.';
    }
    
    PrintLayer(main_layer);
    
    auto bottom_layer = empty_board;
    for (int i = 0; i < N * 3; ++i) {
      bottom_layer[X + 1][i] = bottom_layer[i][X + 1] = '#';
    }
    
    PrintLayer(bottom_layer);
  }
}