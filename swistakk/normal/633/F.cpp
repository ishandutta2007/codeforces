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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
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


const int N = 1e5 + 5;
int val[N];
vector<int> slo[N];
vector<PII> sons_hei[N];
vector<PII> sons_diam[N];
int vis1[N], vis2[N], diam[N];
int hei[N];
int dis[N];
int R;
int res, len, x, y;
void Dfs1(int v) {
  vis1[v] = 1;
  hei[v] = val[v];
  diam[v] = val[v];
  sons_hei[v].clear();
  sons_diam[v].clear();
  for (auto nei : slo[v]) {
    if (vis1[nei]) { continue; }
    dis[nei] = dis[v] + val[v];
    Dfs1(nei);
    maxi(diam[v], diam[nei]);
    maxi(hei[v], hei[nei] + val[v]);
    PII cand = {hei[nei], nei};
    int got = 0;
    REP (tr, SZ(sons_hei[v])) {
      if (cand > sons_hei[v][tr]) {
        sons_hei[v].PB({0, 0});
        for (int j = SZ(sons_hei[v]) - 2; j >= tr; j--) {
          sons_hei[v][j + 1] = sons_hei[v][j];
        }
        sons_hei[v][tr] = cand;
        got = 1;
        break;
      }
    }
    sons_diam[v].PB({diam[nei], nei});
    sort(ALL(sons_diam[v]), greater<PII>());
    if (SZ(sons_diam[v]) > 2) {
      sons_diam[v].pop_back();
    }
    if (!got && SZ(sons_hei[v]) < 3) {
      sons_hei[v].PB(cand);
    }
    if (SZ(sons_hei[v]) > 3) {
      sons_hei[v].pop_back();
    }
  }
//   if (SZ(sons_diam[v]) == 1) {
//     maxi(R, sons_diam[v][0].st);
//   } else if (SZ(sons_diam[v]) >= 2) {
//     maxi(R, sons_diam[v][0].st + sons_diam[v][1].st);
//   }
  if (sons_hei[v].empty()) {
    diam[v] = val[v];
  } else if (SZ(sons_hei[v]) == 1) {
    maxi(diam[v], sons_hei[v][0].st + val[v]);
  } else {
    maxi(diam[v], sons_hei[v][0].st + sons_hei[v][1].st + val[v]);
  }
  debugv(sons_hei[v]);
}
void Dfs2(int v, int diam_up, int heist_up_excl_me) {
  vis2[v] = 1;
  maxi(R, diam[v] + diam_up);
  for (auto nei : slo[v]) {
    if (vis2[nei]) { continue; }
    int max_with_me = 0;
    int max_diam_non_me = 0;
    assert(!sons_hei[v].empty());
    if (nei == sons_hei[v][0].nd) {
      if (SZ(sons_hei[v]) >= 2) {
        max_with_me = sons_hei[v][1].st;
      }
    } else {
      max_with_me = sons_hei[v][0].st;
    }
    max_with_me += val[v];
    if (nei == sons_diam[v][0].nd) {
      if (SZ(sons_diam[v]) >= 2) {
        max_diam_non_me = sons_diam[v][1].st;
      }
    } else {
      max_diam_non_me = sons_diam[v][0].st;
    }
    int got = 0;
    int acc_diam = 0;
    REP (tr, SZ(sons_hei[v])) {
      if (sons_hei[v][tr].nd != nei) {
        acc_diam += sons_hei[v][tr].st;
        got++;
      }
      if (got == 2) {
        break;
      }
    }
    acc_diam += val[v];
    Dfs2(nei, max(diam_up, max(max_diam_non_me, max(acc_diam, max_with_me + heist_up_excl_me))), max(heist_up_excl_me + val[v], max_with_me));
  }
}
    

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>val[i];
  }
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  Dfs1(1);
  Dfs2(1, 0, 0);
  cout<<R<<endl;
  return 0;
}