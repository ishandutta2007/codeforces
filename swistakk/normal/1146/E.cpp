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

struct Node {
  int flip, set_min, set_plus;
  Node() {
    flip = set_min = set_plus = 0;
  }
};

const int M = 1 << 18;
Node drz[2 * M + 5];
void Touch(int v) {
  assert(v < M);
  FOR (son, 2 * v, 2 * v + 1) {
    if (drz[v].flip) {
      if (drz[son].set_min || drz[son].set_plus) {
        swap(drz[son].set_min, drz[son].set_plus);
      } else {
        drz[son].flip ^= 1;
      }
    } else if (drz[v].set_min || drz[v].set_plus) {
      drz[son].flip = 0;
      drz[son].set_min = drz[v].set_min;
      drz[son].set_plus = drz[v].set_plus;
    }
  }
  drz[v].flip = 0;
  drz[v].set_min = 0;
  drz[v].set_plus = 0;
}


void Rec(int bl, int br, int l, int r, int v, int typ) {
  // 2 - flip
  //0 - set_min
  //1 - set_plus
  if (br < l || r < bl) { return; }
  if (l <= bl && br <= r) {
    if (typ == 0 || typ == 1) {
      drz[v].flip = 0;
      drz[v].set_min = 0;
      drz[v].set_plus = 0;
      if (typ == 0) {
        drz[v].set_min = 1;
      } else {
        drz[v].set_plus = 1;
      }
    } else {
      if (drz[v].set_min || drz[v].set_plus) {
        swap(drz[v].set_min, drz[v].set_plus);
      } else {
        drz[v].flip ^= 1;
      }
    }
    return;
  }
  Touch(v);
  int m = (bl + br + 4 * M) / 2 - 2 * M;
  Rec(bl, m, l, r, 2 * v, typ);
  Rec(m + 1, br, l, r, 2 * v + 1, typ);
}

int arr[M];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, q;
  cin>>n>>q;
  RE (i, n) {
    cin>>arr[i];
  }
  int shift = -M / 2;
  RE (i, q) {
    char c;
    int x;
    cin>>c>>x;
    if (c == '<') {
      x--;
    } else {
      x++;
    }
    int ab = abs(x);
    if (x == 0) {
      if (c == '<') {
        Rec(shift, shift + M - 1, shift, shift + M - 1, 1, 1);
      } else {
        Rec(shift, shift + M - 1, shift, shift + M - 1, 1, 0);
      }
    } else if ((c == '<') == (x > 0)) {
      Rec(shift, shift + M - 1, -ab, ab, 1, 2);
      Rec(shift, shift + M - 1, shift, -ab - 1, 1, x > 0);
      Rec(shift, shift + M - 1, ab + 1, shift + M - 1, 1, x > 0);
    } else {
      // UWAGA NA 0
#warning uwaga na 0
      //assert(ab >= 1);
      //Rec(shift, shift + M - 1, -(ab-1), ab - 1, 1, 
      Rec(shift, shift + M - 1, shift, -ab, 1, x < 0);
      Rec(shift, shift + M - 1, ab, shift + M - 1, 1, x < 0);
    }
  }
  RE (i, M - 1) {
    Touch(i);
  }
  RE (i, n) {
    int ind = arr[i] - shift + M;
    if (drz[ind].set_min) {
      cout<<-abs(arr[i])<<" ";
    } else if (drz[ind].set_plus) {
      cout<<abs(arr[i])<<" ";
    } else if (drz[ind].flip) {
      cout<<-arr[i]<<" ";
    } else {
      cout<<arr[i]<<" ";
    }
  }
  cout<<endl;
  
  
  
  return 0;
}