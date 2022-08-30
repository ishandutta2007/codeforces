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

const int N = 2e5 + 5;
const int M = 1 << 18;
int drz[2 * M + 5];
int Read(int a, int b) {
  if (a > b) {
    return 0;
  }
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
void Upd(int a, int v) {
  a += M;
  drz[a] = v;
  a /= 2;
  while (a) {
    drz[a] = min(drz[2 * a], drz[2 * a + 1]);
    a /= 2;
  }
  return;
}

int a[N], b[N], c[N], pref[N];
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, C;
  cin>>n>>C;
  RE (i, n) {
    cin>>a[i];
    if (i != n) {
      cin>>b[i];
    }
    mini(a[i], C);
    mini(b[i], C);
  }
  int sum_so_far = 0;
  int finger = 1;
  int within = 0;
  RE (i, n) {
    within += a[i] + b[i - 1];
    while (within > C) {
      within -= a[finger];
      within -= b[finger];
      finger++;
    }
    int r = Read(finger - 1, i - 1);
    c[i] = a[i] + sum_so_far - r;
    debug(c[i]);
    if (finger > 1) {
      maxi(c[i], C - pref[i - 1] + pref[finger - 2]);
    }
    debug(i, finger, c[i], sum_so_far, r);
    pref[i] = pref[i - 1] + c[i];
    sum_so_far += b[i] + a[i] - c[i];
    Upd(i, sum_so_far);
  }
  int res = 0;
  RE (i, n) {
    res += c[i];
  }
  cout<<res<<endl;
  

  
  return 0;
}