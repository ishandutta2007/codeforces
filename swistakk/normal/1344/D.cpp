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

int f(int j) {
  return 3 * j * j - 3 * j + 1;
}
const int N = 1e6 + 5;
int a[N];
int SafeSqrt(__int128_t heh) {
  __int128_t ziom = (int)floor(sqrt((LD)heh));
  while ((ziom + 1) * (ziom + 1) <= heh) {
    ziom++;
  }
  while (ziom * ziom > heh) {
    ziom--;
  }
  return (int)ziom;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, k;
  cin>>n>>k;
  RE (i, n) {
    cin>>a[i];
  }
  int kl = -4e18, kp = 4e18, faj = -4e18; // najwieksza wartosc taka, ze mam >=k
  
  function<int(int, int)> GetOne = [&](int i, int aktc) { // biore wszystkie o wartosci >= aktc
    if (a[i] - 1 < aktc) { return 0ll; }
    if (a[i] - f(a[i]) >= aktc) { return a[i]; }
    //assert(
    int ret = (3 + SafeSqrt(9 - (__int128_t)12 * (1 + aktc - a[i]))) / 6;
    debug(i, a[i], aktc, ret);
    return ret;
  };
  function<int(int)> GetAll = [&](int aktc) {
    int sum = 0;
    RE (i, n) {
      sum += GetOne(i, aktc);
    }
    return sum;
  };
  int at_faj = 0;
  while (kl <= kp) {
    int aktc = (kl + kp) / 2;
    int get = GetAll(aktc);
    debug(aktc, get, k);
    if (get >= k) {
      faj = aktc;
      at_faj = get;
      kl = aktc + 1;
    } else {
      kp = aktc - 1;
    }
  }
  int nadwyzka = at_faj - k;
  RE (i, n) {
    int get_here = GetOne(i, faj);
    if (nadwyzka && a[i] - f(get_here) == faj) {
      nadwyzka--;
      get_here--;
    }
    cout<<get_here<<" ";
  }
  cout<<endl;
  assert(nadwyzka == 0);
  
    
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}