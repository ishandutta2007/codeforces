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
const int M = 1 << 20;

int nxt_occ[N];
int p[N];
int nxt[N];
vector<int> slo[N];
int drz[2 * M + 5];
int Read(int a, int b) {
  a += M;
  b += M;
  int res = min(drz[a], drz[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      mini(res, drz[a + 1]);
    }
    if (b % 2 == 1) {
      mini(res, drz[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return res;
}

int n, m, q;
vector<int> stos;
void Dfs(int v) {
  if (SZ(stos) >= n - 1) {
    drz[v + M] = stos[SZ(stos) - n + 1]; 
  } else {
    drz[v + M] = m + 1;
  }
  debug(v, drz[v + M], stos);
  stos.PB(v);
  for (auto nei : slo[v]) {
    Dfs(nei);
  }
  stos.pop_back();
}
int arr[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n>>m>>q;
  if (n == 1) {
    cout<<string(q, '1')<<endl;
    return 0;
  }
  RE (i, n) {
    cin>>p[i];
  }
  p[n + 1] = p[1];
  RE (i, n) {
    nxt[p[i]] = p[i + 1];
  }
  RE (i, m) {
    cin>>arr[i];
  }
  
  RE (i, n) {
    nxt_occ[i] = m + 1;
  }
  FORD (i, m, 1) {
    slo[nxt_occ[nxt[arr[i]]]].PB(i);
    nxt_occ[arr[i]] = i;
  } 
  Dfs(m + 1);
  FORD (i, M - 1, 1) {
    drz[i] = min(drz[2 * i], drz[2 * i + 1]);
  }
    
  RE (i, q) {
    int l, r;
    cin>>l>>r;
    if (Read(l, r) <= r) {
      cout<<"1";
    } else {
      cout<<"0";
    }
  }
  cout<<endl;

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}