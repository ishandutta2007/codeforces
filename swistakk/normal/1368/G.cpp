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


typedef bitset<200> B;
const int N = 3e5;
vector<int> slo[N];
vector<int> trans[N];
int outdeg[N];
// bool vis[N];
// int ktop[N];
// int ss[N];
// int d;
// int cnt;
// //int n, m;
// #define n cnt
// int licz;
// vector<int> tmp[N];
// vector<int> nowy[N];
// int czybyl[N];
// void dfs1(int w) // liczy postorder^{-1}, tzn jak post[v]=d, to ktop[d]=w
// {
//   vis[w]=1;
//   for(int g=0; g<slo[w].size(); g++)
//   {
//     if(vis[slo[w][g]]==0)
//     {
//       dfs1(slo[w][g]);
//     }
//   }
//   d++;
//   ktop[d]=w;
// }
// void dfs2(int v) // lazi po jednej silnie spojnej
// {
//   ss[v]=licz;
//   for(int i=0; i<trans[v].size(); i++)
//   {
//     if(ss[trans[v][i]]==0)
//     {
//       dfs2(trans[v][i]);
//     }
//   }
// }
// void podziel() // przypisuje wierzcholkom numer ich silnie spojnej
// {
//   for(int i=1; i<=n; i++)
//   {
//     if(vis[i]==0)
//     {
//       dfs1(i);
//     }
//   }
//   licz=0;
//   for(int i=n; i>0; i--) // idzie od najwiekszych numerow postorder
//   {
//     if(ss[ktop[i]]==0) // jezeli ktop[i] nie jest przydzielony do zadnej, to pomaluj jego silnie spojna
//     {
//       licz++;
//       dfs2(ktop[i]);
//     }
//   }
// }
// void stworzgraf() // jezeli potrzebne jest stworzenie grafu silnie spojnych, to bedzie on w tablicy wektorow "nowy"
// {
//   for(int i=1; i<=n; i++)
//   {
//     for(int j=0; j<slo[i].size(); j++)
//     {
//       int s1=ss[i];
//       int s2=ss[slo[i][j]];
//       if(s1!=s2)
//       {
//         tmp[s1].push_back(s2);
//       }
//     }
//   }
//   for(int i=1; i<=licz; i++)
//   {
//     for(int j=0; j<tmp[i].size(); j++)
//     {
//       if(czybyl[tmp[i][j]]!=i)
//       {
//         czybyl[tmp[i][j]]=i;
//         nowy[i].push_back(tmp[i][j]);
//       }
//     }
//   }
// }
// #undef n

struct Rect {
  int x1, x2, y1, y2;
};
struct Ev {
  int y1, y2;
  int typ;
//   bool operator<(const Ev& oth) const {
//     if (x != oth.x) { return x < oth.x; }
//     
};

struct Node {
  int add, nonzero, wid;
};

const int M = 1 << 18;
Node drz[2 * M + 5];

Node Merge(Node L, Node R) {
  Node res;
  res.add = 0;
  res.nonzero = L.nonzero + R.nonzero;
  res.wid = L.wid + R.wid;
  return res;
}

void Add(int pos, int v) {
  Node& n = drz[pos];
  n.add += v;
  if (n.add > 0) {
    n.nonzero = n.wid;
  } else {
    if (pos >= M) {
      n.nonzero = 0;
    } else {
      n.nonzero = drz[2 * pos].nonzero + drz[2 * pos + 1].nonzero;
    }
  }
}

void Add(int bl, int br, int l, int r, int v, int val) {
  if (bl > r || br < l) { return; }
  if (l <= bl && br <= r) {
    Add(v, val);
    return;
  }
  int m = (bl + br) / 2;
  int cp = drz[v].add;
  Add(bl, m, l, r, 2 * v, val);
  Add(m + 1, br, l, r, 2 * v + 1, val);
  drz[v] = Merge(drz[2 * v], drz[2 * v + 1]);
  Add(v, cp);
}
int indeg[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  VVI id(n + 2, VI(m + 2));
  vector<vector<char>> board(n + 2, vector<char>(m + 2));
  
  
  int cnt = 1;
  //int cnt = 1;
  RE (i, n) {
    RE (j, m) {
      id[i][j] = cnt++;
    }
  }
  cnt--;
  VI reach(cnt + 2);
  //VVI neis(cnt + 2);
  RE (i, n) {
    RE (j, m) {
      cin>>board[i][j];
      int ni = i, nj = j;
      if (board[i][j] == 'U') {
        ni = i + 2;
      } else if (board[i][j] == 'D') {
        ni = i - 2;
      } else if (board[i][j] == 'L') {
        nj = j + 2;
      } else if (board[i][j] == 'R') {
        nj = j - 2;
      } else {
        assert(false);
      }
      if (id[ni][nj] != 0) {
        slo[id[ni][nj]].PB(id[i][j]);
        outdeg[id[ni][nj]]++;
        indeg[id[i][j]]++;
        trans[id[i][j]].PB(id[ni][nj]);
      }
    }
  }
  
  VI sz(cnt + 2);
  VI pre(cnt + 2);
  REP (tr, 2) {
    int d = 0;
    function<void(int)> Dfs = [&](int v) {
      d++;
      sz[v] = 1;
      pre[v] = d;
      for (auto nei : slo[v]) {
        Dfs(nei);
        sz[v] += sz[nei];
      }
    };
    RE (i, n) {
      RE (j, m) {
        if ((i + j) % 2 != tr) { continue; }
        if (indeg[id[i][j]]) { continue; }
        Dfs(id[i][j]);
        
      }
    }
  }
  RE (i, n) {
    RE (j, m) {
      cerr<<pre[id[i][j]]<<" ";
    }
    cerr<<endl;
  }
  RE (i, n) {
    RE (j, m) {
      cerr<<sz[id[i][j]]<<" ";
    }
    cerr<<endl;
  }
  vector<Rect> rects;
  RE (i, n) {
    RE (j, m) {
      if (board[i][j] == 'U') {
        rects.PB({pre[id[i][j]], pre[id[i][j]] + sz[id[i][j]] - 1, pre[id[i + 1][j]], pre[id[i + 1][j]] + sz[id[i + 1][j]] - 1});
        if ((i + j) % 2) {
          swap(rects.back().x1, rects.back().y1);
          swap(rects.back().x2, rects.back().y2);
        }
        //res += reach[id[i][j]] * reach[id[i + 1][j]];
      } else if (board[i][j] == 'L') {
        rects.PB({pre[id[i][j]], pre[id[i][j]] + sz[id[i][j]] - 1, pre[id[i][j + 1]], pre[id[i][j + 1]] + sz[id[i][j + 1]] - 1}); 
        if ((i + j) % 2) {
          swap(rects.back().x1, rects.back().y1);
          swap(rects.back().x2, rects.back().y2);
        }
        //res += reach[id[i][j]] * reach[id[i][j + 1]];
      }
    }
  }
  vector<vector<Ev>> evs(cnt + 2);
  for (auto rect : rects) {
    debug(rect.x1, rect.x2, rect.y1, rect.y2);
    evs[rect.x1].PB({rect.y1, rect.y2, 1});
    evs[rect.x2 + 1].PB({rect.y1, rect.y2, -1});
  }
  
  int res = 0;
  FORD (i, 2 * M, 1) {
    if (i >= M) {
      drz[i].wid = 1;
    } else {
      drz[i].wid = drz[2 * i].wid * 2;
    }
  }
  RE (i, cnt) {
    for (auto ev : evs[i]) {
      debug(i, ev.y1, ev.y2, ev.typ);
      Add(1, M, ev.y1, ev.y2, 1, ev.typ);
    }
    debug(i, drz[1].nonzero);
    res += drz[1].nonzero;
  }
  cout<<res<<endl;
          
  
//   podziel();
//   stworzgraf();
  //vector<B> can_reach(cnt + 2);
//   RE (i, licz) {
//     debug(i, nowy[i]);
//   }
//   VI que;
//   RE (i, cnt) {
//     if (outdeg[i] == 0) {
//       que.PB(i);
//     }
//   }
//   for (int ii = 0; ii < SZ(que); ii++) {
//     int v = que[ii];
//     for (auto pr : trans[v]) {
//       outdeg[pr]--;
//       if (outdeg[pr] == 0) {
//         que.PB(pr);
//       }
//     }
//   }
//   int L = 200;
//   for (int turn = 0; ; turn++) {
//     int beg = L * turn + 1;
//     if (beg > cnt) { break; }
//     RE (i, cnt) {
//       can_reach[i].reset();
//       if (i - beg < L && i - beg >= 0) {
//         can_reach[i][i - beg] = 1;
//       }
//     }
//     for (auto v : que) {
//       for (auto nei : slo[v]) {
//         can_reach[v] |= can_reach[nei];
//       }
//     }
//     RE (i, cnt) {
//       reach[i] += can_reach[i].count();
//     }
//   }
//   RE (i, cnt) {
//     debug(i, reach[i]);
//   }
  
  
  

//   cout<<res<<endl;
  
  return 0;
}