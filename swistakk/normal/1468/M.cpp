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

struct Sol {
  void Test() {
    int n;
    cin>>n;
    vector<pair<VI, int>> sets;
    map<int, int> mapuj;
    RE (i, n) {
      int k;
      cin>>k;
      VI ziom;
      RE (j, k) {
        int x;
        cin>>x;
        mapuj[x];
        ziom.PB(x);
      }
      sets.PB({ziom, i});
    }
    int nxt = 1;
    for (auto& p : mapuj) {
      p.nd = nxt++;
    }
    for (auto& vn : sets) {
      for (auto& x : vn.st) {
        x = mapuj[x];
      }
    }
    sort(ALL(sets), [&](pair<VI, int>& A, pair<VI, int>& B) { return SZ(A.st) > SZ(B.st); });
    int B = 500;
    VI last_occ(nxt + 5, -1);
    VVI where(nxt + 5);
    REP (i, n) {
      auto& v = sets[i].st;
      for (auto x : v) {
        last_occ[x] = i;
      }
      if (SZ(v) >= B) {
        FOR (j, i + 1, n - 1) {
          int here = 0;
          for (auto x : sets[j].st) {
            if (last_occ[x] == i) {
              here++;
            }
          }
          if (here >= 2) {
            cout<<sets[i].nd<<" "<<sets[j].nd<<"\n";
            return;
          }
        }
      } else {
        for (auto x : v) {
          where[x].PB(i);
        }
      }
    }
    VPII dupa(nxt + 5, {-1, -1});
    RE (num, nxt) {
      for (auto x : where[num]) {
        for (auto oth : sets[x].st) {
          if (oth != num) {
            if (dupa[oth].st == num) {
              cout<<sets[dupa[oth].nd].nd<<" "<<sets[x].nd<<"\n";
              return;
            }
            dupa[oth] = {num, x};
          }
        }
      }
    }
    cout<<"-1\n";
    
    
    
  }
};

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int t;
  cin>>t;
  RE (i, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}