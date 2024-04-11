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

int spow(int a, int b, int m) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % m;
    }
    b /= 2;
    a = a * a % m;
  }
  return r;
}

int Inv(int b, int m) {
  return spow(b, m - 2, m);
}
const int N = 1e5 + 5;
int a[N];
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int m, n;
  cin>>m>>n;
  if (m == n) {
    cout<<"0 1\n";
    return 0;
  }
  int S = 0;
  RE (i, n) {
    cin>>a[i];
    S += a[i];
  }
  if (n == 1) {
    cout<<a[1]<<" 0\n";
    return 0;
  }
  int mid = S % m * Inv(n, m) % m;
  debug(S % m, mid);
  set<int> vals;
  bool big = n > (m / 2);
  if (big) {
    REP (i, m) {
      vals.insert(i);
    }
  }
  RE (i, n) {
    a[i] = (a[i] + m - mid) % m;
    debug(i, a[i]);
    if (!big) {
      vals.insert(a[i]);
    } else {
      vals.erase(a[i]);
    }
  }
  int new_n = SZ(vals);
  #define n dupa
if(SZ(vals)==1){cout<<(mid+1)%m<<" 1\n"; return 0;}
  for (auto v : vals) {
    if (v == 0) { continue; }
    int cand = 2 * v * Inv(new_n - 1, m) % m;
    debug(v, cand);
    int cur = v;
    bool fail = false;
    RE (j, new_n - 1) {
      cur = (cur - cand + m) % m;
      if (vals.count(cur) == 0) {
        fail = true;
        break;
        return 0;
      }
    }
    if (fail) { continue; }
    if (!big) {
      cout<<(cur + mid) % m<<" "<<cand<<endl;
    } else {
      cout<<(cur + mid + new_n * cand) % m<<" "<<cand<<endl;
    }
    return 0;
  }
  cout<<"-1\n";
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}