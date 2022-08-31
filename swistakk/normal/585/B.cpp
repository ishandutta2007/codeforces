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

struct Sol {
  VVI board;
  VVI can;
  int n;
  bool BadField(int r, int c) {
    return c <= n && !board[r][c];
  }
  bool Good(int r, int c, int len) {
    vector<PII> cands{{r, 3 * c - 4}};
    if (len) {
      cands.PB({r, 3 * c - 3});
      cands.PB({r, 3 * c - 2});
    }
    for (auto f : cands) {
      if (BadField(f.st, f.nd)) {
        return false;
      }
    }
    return true;
  }
        
  void Test() {
    cin>>n;
    make(int, k);
    ResizeVec(board, {4, n + 2});
    ResizeVec(can, {4, n + 2});
    RE (r, 3) {
      RE (c, n) {
        make(char, cc);
        if (cc == '.' || cc == 's') {
          board[r][c] = 1;
        }
        if (cc == 's') {
          can[r][c] = 1;
        }
      }
    }
    RE (r, 3) {
      RE (c, n) {
        cerr<<board[r][c];
      }
      cerr<<endl;
    }
    RE (c, n - 1) {
      RE (r, 3) {
        if (can[r][c]) {
          FOR (delta, -1, 1) {
            int nr = r + delta;
            if (nr >= 1 && nr <= 3 && Good(r, c + 1, 0) && Good(nr, c + 1, 1)) {
              can[nr][c + 1] = 1;
            }
          }
        }
      }
    }
    RE (r, 3) {
      RE (c, n) {
        cerr<<can[r][c];
      }
      cerr<<endl;
    }
    RE (r, 3) {
      if (can[r][n]) {
        cout<<"YES\n";
        return;
      }
    }
    cout<<"NO\n";
  }
};
    
      

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int t;
  cin>>t;
  RE (tt, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}