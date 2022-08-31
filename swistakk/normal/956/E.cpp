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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 1e4 + 5;
int h[N];
int b[N];
int check[N][2];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, l, r;
  cin>>n>>l>>r;
  int sum = 0;
  RE (i, n) {
    cin>>h[i];
    sum += h[i];
  }
  r = sum - r;
  l = sum - l;
  swap(l, r);
  int cnt_imp = 0;
  VPII boxes;
  RE (i, n) {
    cin>>b[i];
    cnt_imp += b[i];
    boxes.PB({b[i] ^ 1, h[i]});
  }
  sort(ALL(boxes));
  reverse(ALL(boxes));
  VI pref_imp(sum + 2);
  int tmp = 0;
  FORD (ii, n - 1, 0) {
    if (boxes[ii].st == 1) { continue; }
    tmp += boxes[ii].nd;
    pref_imp[tmp] = n - ii;
  }
  RE (i, sum) {
    maxi(pref_imp[i], pref_imp[i - 1]);
  }
  int res = 0;
  bitset<N> reach;
  reach[0] = 1;
  REP (ii, SZ(boxes)) {
    auto box = boxes[ii];
    REP (i, sum) {
      if (reach[i] && !check[i + box.nd][box.st] && i + box.nd >= l && i + box.nd <= r) {
        check[i + box.nd][box.st] = 1;
        maxi(res, min(1 - box.st + pref_imp[r - (i + box.nd)], n - ii));
      }
    }
    reach |= (reach << box.nd);
  }
  cout<<res<<endl;
//   int kl = 0, kp = cnt_imp, faj = 0;
//   while (kl <= kp) {
//     int aktc = (kl + kp) / 2;
//     int max_up = r;
//     RE (i, aktc - 1) {
//       max_up -= boxes[i].nd;
//     }
//     int succ = 0;
//     if (max_up < l) {
//       succ = 0;
//     } else {
//       bitset<N> reach;
//       reach[0] = 1;
//       FOR (i, aktc, n - 1) {
//         reach = reach | (reach << boxes[i].nd);
//       }
//       FOR (i, l, max_up) {
//         if (reach[i]) {
//           succ = 1;
//         }
//       }
//     }
//     if (succ) {
//       faj = kl;
//       kl = aktc + 1;
//     } else {
//       kp = aktc - 1;
//     }
//   }
//   cout<<faj<<endl;
//           
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}