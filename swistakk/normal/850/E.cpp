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

const int MOD = 1e9 + 7;
const int INV2 = (MOD + 1) / 2;
const int N = 1 << 20;
int a[N];
// Transforms the interval [x, y) in a.
    void transform(int x, int y)
    {
        if ( x == y - 1) {
            return;
        }
        int l2 = ( y - x ) / 2;
        int z = x + l2;
        transform(x, z);
        transform(z, y);
        for (int i=x; i<z; i++) {
            int x1 = a[i];
            int x2 = a[i+l2];
            a[i] = (x1 - x2 + MOD) % MOD;
            a[i+l2] = (x1 + x2) % MOD;
        }
    }
    // Reverses the transform in
    // the interval [x, y) in a.
    void untransform(int x, int y)
    {
        if ( x == y - 1) {
            return;
        }
        int l2 = ( y - x ) / 2;
        int z = x + l2;
        for (int i=x; i<z; i++) {
            long long y1 = a[i];
            long long y2 = a[i+l2];
            // x1 - x2 = y1
            // x1 + x2 = y2
            // 2 * x1  = y1 + y2
            // 2 * x2  = y2 - y1
            
            // In order to solve those equations, we need to divide by 2
            // But we are performing operations modulo 1000000007
            // that needs us to find the modular multiplicative inverse of 2.
            // That is saved in the INV2 variable.
            
            a[i] = (int)( ((y1 + y2)*INV2) % MOD );
            a[i+l2] = (int)( ((y2 - y1 + MOD)*INV2) % MOD );
        }
        untransform(x, z);
        untransform(z, y);
    }

    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  REP (i, 1 << n) {
    char c;
    cin>>c;
    a[i] = (c == '1');
  }
  transform(0, 1 << n);
  REP (i, 1 << n) {
    a[i] = a[i] * a[i] % MOD;
  }
  untransform(0, 1 << n);
  int res = 0;
  REP (i, 1 << n) {
    cerr<<a[i]<<" ";
    res += (1ll * a[i]) << (n - __builtin_popcount(i));
  }
  cerr<<endl;
  cout<<3 * res % MOD<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}