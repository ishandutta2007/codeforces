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

const int N = 1e6 + 5;
int per[N];
int vis[N];
int wh[N];
VPII res;
void Move(int a, int b) { // zamien pozycje a i b
  res.PB({a, b});
  //a = wh[per[a]];
  //b = wh[per[b]];
  //swap(wh[per[a]], wh[per[b]]);
  swap(per[a], per[b]);
  per[a] *= -1;
  per[b] *= -1;
}
int n;
void Deb() {
#ifdef LOCAL
  RE (i, n) {
    cerr<<per[i]<<" ";
  }
  cerr<<endl;
#endif
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n) {
    cin>>per[i];
    wh[per[i]] = i;
  }
  VVI cycs;
  RE (i, n) {
    if (i == per[i]) { continue; }
    if (vis[i]) { continue; }
    int cur = per[i];
    VI cyc;
    //vis[cur] = 1;
    while (cur != i) {
      cyc.PB(cur);
      vis[cur] = 1;
      cur = per[cur];
    }
    vis[cur] = 1;
    cyc.PB(i);
    cycs.PB(cyc);
  }
  debug(cycs);
  while (SZ(cycs) >= 2) {
    auto c1 = cycs.back();
    cycs.pop_back();
    auto c2 = cycs.back();
    cycs.pop_back();
    debug(c1, c2);
    int p1 = wh[c1[0]];
    int p2 = wh[c2[0]];
    Move(p1, p2);
    Deb();
    RE (i, SZ(c1) - 1) {
      Move(p2, wh[c1[i]]);
      Deb();
    }
    RE (i, SZ(c2) - 1) {
      Move(p1, wh[c2[i]]);
      Deb();
    }
    Move(p1, p2);
    Deb();
  }
  if (SZ(cycs)) {
    auto c1 = cycs.back();
    if (SZ(c1) < n) {
      debug(c1);
      VI c2;
      RE (i, n) {
        if (per[i] == i) {
          c2 = {i};
          break;
        }
      }
      int p1 = wh[c1[0]];
      int p2 = wh[c2[0]];
      Move(p1, p2);
      Deb();
      RE (i, SZ(c1) - 1) {
        Move(p2, wh[c1[i]]);
        Deb();
      }
      RE (i, SZ(c2) - 1) {
        Move(p1, wh[c2[i]]);
        Deb();
      }
      Move(p1, p2);
      Deb();
    } else {
      debug("all");
      int p1 = wh[c1[0]];
      int p2 = wh[c1[1]];
      int p3 = wh[c1[2]];
      debug(p1, p2, p3);
      Move(p2, p3);
      Deb();
      Move(p1, p3);
      Deb();
      FOR (i, 3, SZ(c1) - 1) {
        Move(p2, wh[c1[i]]);
        Deb();
      }
      Move(p2, p1);
      Move(p2, p3);
      Deb();
    }
  }
  RE (i, n) {
    cerr<<per[i]<<" ";
  }
  cerr<<endl;
  cout<<SZ(res)<<endl;
  for (auto p : res) {
    cout<<p.st<<" "<<p.nd<<"\n";
  }
    
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}