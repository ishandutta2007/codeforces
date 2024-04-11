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

struct Node {
  int suf_hill, pref_hill, best_in, fir_sig, last_sig, wid;
  bool Full() {
    return wid == suf_hill;
  }
};

Node Merge(Node l, Node r) {
  Node n;
  n.wid = l.wid + r.wid;
  n.fir_sig = l.fir_sig;
  n.last_sig = r.last_sig;
  n.best_in = max(l.best_in, r.best_in);
  bool can_join = false;
  if (l.last_sig != -1 || r.fir_sig != 1) {
    can_join = true;
  }
  if (can_join) {
    maxi(n.best_in, l.suf_hill + r.pref_hill);
  }
  if (r.Full() && can_join) {
    n.suf_hill = r.suf_hill + l.suf_hill;
  } else {
    n.suf_hill = r.suf_hill;
  }
  if (l.Full() && can_join) {
    n.pref_hill = l.pref_hill + r.pref_hill;
  } else {
    n.pref_hill = l.pref_hill;
  }
  return n;
}

int Sig(int x) {
  if (x > 0) { return 1; }
  if (x < 0) { return -1; }
  return 0;
}
const int M = 1 << 19;
Node drz[2 * M + 5];
int a[M];
int val[2 * M + 5];
void Upd(int v) {
  Node& n = drz[v];
  if (v >= M) {
    n.fir_sig = n.last_sig = Sig(val[v]);
    n.suf_hill = n.pref_hill = !!n.fir_sig;
  } else {
    drz[v] = Merge(drz[2 * v], drz[2 * v + 1]);
  }
}
void Set(int v, int diff) {
  v += M;
  val[v] += diff;
  while (v) {
    Upd(v);
    v /= 2;
  }
}
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>a[i];
  }
  FOR (i, 2, n) {
    val[i + M] = a[i] - a[i - 1];
    drz[i + M].wid = 1;
  }
  FORD (i, M, 1) {
    drz[i].wid = drz[2 * i].wid + drz[2 * i + 1].wid; 
  }
  FORD (i, 2 * M, 1) {
    Upd(i);
  }
  int m;
  cin>>m;
  RE (i, m) {
    int l, r, d;
    cin>>l>>r>>d;
    if (l >= 2) {
      Set(l, d);
    }
    if (r != n) {
      Set(r + 1, -d);
    }
    cout<<drz[1].best_in + 1<<"\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}