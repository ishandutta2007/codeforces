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


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, k;
  cin>>n>>k;
  if (n % 2 && k % 2 == 0) {
    cout<<"-1"<<endl;
    return 0;
  }
  if (n % k == 0) {
    int heh = 0;
    RE (i, n / k) {
      int b = (i - 1) * k + 1;
      cout<<"? ";
      FOR (j, b, b + k - 1) {
        cout<<j<<" ";
      }
      cout<<endl;
      int r;
      cin>>r;
      heh ^= r;
    }
    cout<<"! "<<heh<<endl;
    return 0;
  }
  FOR (d, 3, 500) {
    if (d * k % 2 != n % 2) { continue; }
    if (d * k < n) { continue; }
    if (d % 2 == 0 && (d - 1) * n < d * k) { continue; }
    int to_go = d * k;
    VI muls(n + 2);
    RE (i, n) {
      muls[i] = 1;
    }
    to_go -= n;
    RE (i, n) {
      while (to_go && muls[i] + 2 <= d) {
        muls[i] += 2;
        to_go -= 2;
      }
    }
    VPII dupa;
    RE (i, n) {
      dupa.PB({muls[i], i});
    }
    int heh = 0;
    RE (i, d) {
      sort(ALL(dupa));
      reverse(ALL(dupa));
      cout<<"? ";
      REP (j, k) {
        cout<<dupa[j].nd<<" ";
        dupa[j].st--;
      }
      cout<<endl;
      int r;
      cin>>r;
      heh ^= r;
    }
    cout<<"! "<<heh<<endl;
    return 0;
  }
      
    
    
//     int overflow = (d * k - n) / 2;
//     debug(overflow);
//     int nxt = overflow + 1;
//     int heh = 0;
//     VI to_
//     RE (i, d) {
//       cout<<"? ";
//       int how_many = k;
//       if (i <= 3) {
//         RE (j, overflow) {
//           cout<<j<<" ";
//         }
//         how_many -= overflow;
//       }
//       RE (j, how_many) {
//         cout<<nxt<<" ";
//         nxt++;
//       }
//       cout<<endl;
//       int r;
//       cin>>r;
//       heh ^= r;
//     }
//     cout<<"! "<<heh<<endl;
//     
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}