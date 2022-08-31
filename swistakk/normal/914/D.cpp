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

const int M = 1 << 19;
int drz[2 * M + 5];
void Upd(int pos, int x) {
  pos += M - 1;
  drz[pos] = x;
  pos /= 2;
  while (pos) {
    drz[pos] = __gcd(drz[2 * pos], drz[2 * pos + 1]);
    pos /= 2;
  }
}
int Fir(int l, int x, int bl, int br, int ind) {
  if (br < l) { return M; }
  if (drz[ind] % x == 0) { return M; }
  if (ind >= M) {
    return ind - M + 1;
  }
  int m = (bl + br) / 2;
  int left = Fir(l, x, bl, m, 2 * ind);
  if (left != M) { return left; }
  return Fir(l, x, m + 1, br, 2 * ind + 1);
//   l += M - 1;
//   if (drz[l] % x) { return l; }
//   while (l) {
//     if (l % 2 == 0 && drz[
  
  
}
int Last(int r, int x, int bl, int br, int ind) {
  if (bl > r) { return -1; }
  if (drz[ind] % x == 0) { return -1; }
  if (ind >= M) {
    return ind - M + 1;
  }
  int m = (bl + br) / 2;
  int right = Last(r, x, m + 1, br, 2 * ind + 1);
  if (right != -1) { return right; }
  return Last(r, x, bl, m, 2 * ind);
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
    cin>>drz[i + M - 1];
  }
  FORD (i, M - 1, 1) {
    drz[i] = __gcd(drz[2 * i], drz[2 * i + 1]);
  }
  int q;
  cin>>q;
  RE (i, q) {
    int typ;
    cin>>typ;
    if (typ == 1) {
      int l, r, x;
      cin>>l>>r>>x;
      int fir = Fir(l, x, 1, M, 1);
      int last = Last(r, x, 1, M, 1);
      if (fir >= last) {
        cout<<"YES\n";
      } else {
        cout<<"NO\n";
      }
    } else {
      int p, x;
      cin>>p>>x;
      Upd(p, x);
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}