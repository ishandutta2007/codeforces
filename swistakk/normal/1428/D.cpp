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


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  VI a(n + 2);
  VI prv(n + 2);
  VVI stosy(4);
  VI wh_3;
  RE (i, n) {
    cin>>a[i];
    if (a[i] == 3) {
      wh_3.PB(i);
    }
  }
  RE (i, SZ(wh_3) - 1) {
    prv[wh_3[i]] = wh_3[i - 1];
  }
  RE (i, n) {
    if (a[i] == 3 && i < wh_3.back()) { continue; }
    if (a[i] == 0) { continue; }
    FOR (j, a[i] + 1, 3) {
      if (!stosy[j].empty()) {
        prv[i] = stosy[j].back();
        stosy[j].pop_back();
        break;
      }
    }
    stosy[a[i]].PB(i);
  }
  if (!stosy[3].empty() || !stosy[2].empty()) {
    cout<<"-1\n";
    return 0;
  }
  VI vis(n + 2);
  VPII booms;
  int nxt_row = 1;
  FORD (i, n, 1) {
    if (vis[i] || a[i] == 0) { continue; }
    int cur = i;
    VI here;
    while (cur) {
      vis[cur] = 1;
      here.PB(cur);
      cur = prv[cur];
    }
    reverse(ALL(here));
    VI as;
    for(auto x : here) {
      as.PB(a[x]);
    }
    //int last_row = nxt_row + 1;
    int trojki = 0;
    for (auto x : as) {
      trojki += (x == 3);
    }
    //last_row += trojki;
    booms.PB({nxt_row, here.back()});
    if (SZ(here) >= 2 && as[SZ(as) - 2] == 2) {
      booms.PB({nxt_row, here[SZ(here) - 2]});
    }
    nxt_row++;
    FORD (j, trojki - 1, 0) {
      booms.PB({nxt_row, here[j + 1]});
      booms.PB({nxt_row, here[j]});
      nxt_row++;
    }
//     if (as == VI{1}) {
//       booms.PB({nxt_row++, here[0]});
//     } else if (as == VI{2, 1}) {
//       booms.PB({nxt_row, here[0]});
//       booms.PB({nxt_row++, here[1]});
//     } else if (as == VI{3, 1}) {
//       booms.PB({nxt_row + 1, here[0]});
//       booms.PB({nxt_row + 1, here[1]});
//       booms.PB({nxt_row, here[1]});
//       nxt_row += 2;
//     } else if (as == VI{3, 2, 1}) {
//       booms.PB({nxt_row + 1, here[0]});
//       booms.PB({nxt_row + 1, here[1]});
//       booms.PB({nxt_row, here[1]});
//       booms.PB({nxt_row, here[2]});
//       nxt_row += 2;
//     } else {
//       debug(as);
//       assert(false);
//     }
  }
  cout<<SZ(booms)<<endl;
  for(auto p : booms) {
    cout<<n - p.st + 1<<" "<<p.nd<<"\n";
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}