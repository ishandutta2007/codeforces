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

const int N = 1e5 + 5;
const int M = 1 << 17;
PII drz[2 * M + 5];
int can[N], to[N], x[N];
int GetFirBigger(int l, int r, int bd, int v) {
  int m = (l + r) / 2;
  if (l == r) {
    return l;
  }
  if (drz[2 * v].nd > bd) {
    return GetFirBigger(l, m, bd, 2 * v);
  }
  return GetFirBigger(m + 1, r, bd, 2 * v + 1);
}
int GetFirSmaller(int l, int r, int bd, int v) {
  int m = (l + r) / 2;
  if (l == r) {
    return l;
  }
  if (drz[2 * v].st < bd) {
    return GetFirSmaller(l, m, bd, 2 * v);
  }
  return GetFirSmaller(m + 1, r, bd, 2 * v + 1);
}
void Upd(int a, PII p) {
  a += M - 1;
  drz[a] = p;
  a /= 2;
  while (a) {
    drz[a] = {min(drz[2 * a].st, drz[2 * a + 1].st), max(drz[2 * a].nd, drz[2 * a + 1].nd)};
    a /= 2;
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, s1, s2;
  cin>>n>>s1>>s2;
  RE (i, n) {
    cin>>x[i];
  }
  int kl = abs(s1 - s2), kp = 1e9, faj = kp;
  while (kl <= kp) {
    int aktc = (kl + kp) / 2;
    int c = aktc;
    REP (i, 2 * M + 5) {
      drz[i] = PII{3e9, -3e9};
    }
    Upd(n + 1, {-3e9, 3e9});
    Upd(n, {x[n], x[n]});
    FORD (i, n - 1, 1) {
      if (abs(x[i] - x[i + 1]) <= aktc) {
        can[i] = 1;
        to[i] = min(GetFirSmaller(1, M, x[i] - c, 1), GetFirBigger(1, M, x[i] + c, 1)) - 1;
      } else {
        can[i] = 0;
      }
      Upd(i, {x[i], x[i]});
    }
    int stay1 = min(GetFirSmaller(1, M, s1 - c, 1), GetFirBigger(1, M, s1 + c, 1)) - 1;
    int stay2 = min(GetFirSmaller(1, M, s2 - c, 1), GetFirBigger(1, M, s2 + c, 1)) - 1;
    int hehs = max(stay1, stay2);
    int fail = false;
    RE (i, n) {
      if (hehs < i) { fail = true; break; }
      if (can[i]) {
        maxi(hehs, to[i]);
      }
    }
    if (fail) {
      kl = aktc + 1;
    } else {
      faj = aktc;
      kp = aktc - 1;
    }
  }
  cout<<faj<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}