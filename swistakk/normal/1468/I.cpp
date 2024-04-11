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

PII Add(PII A, PII B) {
  return {A.st + B.st, A.nd + B.nd};
}
PII Sub(PII A, PII B) {
  return {A.st - B.st, A.nd - B.nd};
}
int Cross(PII A, PII B) {
  return A.st * B.nd - A.nd * B.st;
}
int Sq(int x) {
  return x * x;
}
int Norm(PII A) {
  return Sq(A.st) + Sq(A.nd);
}
int G(PII A) {
  return abs(__gcd(A.st, A.nd));
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, dx1, dy1, dx2, dy2;
  cin>>n>>dx1>>dy1>>dx2>>dy2;
  PII L = {dx1, dy1};
  PII R = {dx2, dy2};
  if (Cross(L, R) == 0) { 
    cout<<"NO\n";
    return 0;
  }
  int m1 = 1, m2 = 1;
  if (abs(Cross(L, R)) != n) {
    cout<<"NO\n";
    return 0;
  }
  int gx = abs(__gcd(dx1, dx2));
  cout<<"YES\n";
  REP (i, gx) {
    REP (j, n / gx) {
      cout<<i<<" "<<j<<"\n";
    }
  }
//   int xm = 1, ym = 1;
//   while (abs(Cross(L, R)) > 1) {
//     int gx = abs(__gcd(L.st, R.st));
//     int gy = abs(__gcd(L.nd, R.nd));
//     if (gx > 1){
//       L.st /= gx;
//       R.st /= gx;
//       xm *= gx;
//       continue;
//     }
//     if (gy > 1) {
//       L.nd /= gy;
//       R.nd /= gy;
//       ym *= gy;
//       continue;
//     }
//     //if (Norm(L) < Norm(R)) { swap(L, R); swap(m1, m2); }
//     PII adduj1 = L, subuj1 = L;
//     PII adduj2 = R, subuj2 = R;
//     
//     while (1) {
//       int g11 = G(adduj1);
//       int g12 = G(subuj1);
//       int g21 = G(adduj2);
//       int g22 = G(subuj2);
//       
//       if (g11 > 1) {
//         adduj1.st /= g11;
//         adduj1.nd /= g11;
//         m1 *= g11;
//         L = adduj1;
//         break;
//       }
//       if (g21 > 1) {
//         adduj2.st /= g21;
//         adduj2.nd /= g21;
//         m2 *= g21;
//         R = adduj2;
//         break;
//       }
//       if (g12 > 1) {
//         subuj1.st /= g12;
//         subuj1.nd /= g12;
//         m1 *= g12;
//         L = subuj1;
//         break;
//       }
//       if (g22 > 1) {
//         subuj2.st /= g22;
//         subuj2.nd /= g22;
//         m2 *= g22;
//         R = subuj2;
//         break;
//       }
//       adduj1 = Add(adduj1, R);
//       subuj1 = Sub(subuj1, R);
//       adduj2 = Add(adduj2, L);
//       subuj2 = Sub(subuj2, L);
//       
//     }
//   }
//   cout<<"YES\n";
//   assert(m1 * m2 * xm * ym == n);
//   //cout<<m1 * m2<<endl;
//   REP (i, m1) {
//     REP (j, m2) {
//       REP (a, xm) {
//         REP (b, ym) {
//           int e = (i * L.st + j * R.st) * xm + a;
//           int f = (i * L.nd + j * R.nd) * ym + b;
//           //assert(abs(e) <= 1e9 && abs(f <= 1e9));
//           cout<<e<<" "<<f<<"\n";
//         }
//       }
//     }
//   }
    
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}