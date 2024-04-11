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

const int N = 2e5 + 5;
int Magic(int n) {
  return n - (n & (n - 1));
}
struct Drz {
  VI drz;
  Drz() {
    drz.resize(N);
  }
  void Add(int k, int x) {
    while (k < N) {
      drz[k] += x;
      k += Magic(k);
    }
  }
  int Read(int k) {
    int sum = 0;
    while (k) {
      sum += drz[k];
      k -= Magic(k);
    }
    return sum;
  }
};


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  VI per(n + 2);
  VI wh(n + 2);
  RE (i, n) {
    cin>>per[i];
    wh[per[i]] = i;
  }
  set<int> on_left, on_right;
  Drz dots, numbers;
  RE (i, n) {
    dots.Add(i, 1);
  }
  int res = 0;
  RE (i, n) {
    int pos = wh[i];
    int dupa = i - 1 - numbers.Read(pos);
    res += dupa;
    res -= min(numbers.Read(pos - 1), dupa);
    dots.Add(pos, -1);
    numbers.Add(pos, 1);
    if (i == 1) { goto End; }
    if (i == 2) {
      on_left.insert(min(wh[1], wh[2]));
      on_right.insert(max(wh[1], wh[2]));
      res += abs(wh[1] - wh[2]) - 1;
      goto End;
    }
    {
      debug(res);
      int bigL = *prev(on_left.end()), smallR = *on_right.begin();
      
      if (SZ(on_left) == SZ(on_right)) {
        if (pos > smallR) {
          res += dots.Read(pos) - dots.Read(smallR);
          on_right.insert(pos);
        } else {
          if (pos < bigL) {
            res += dots.Read(bigL) - dots.Read(pos);
          }
          on_left.insert(pos);
        }
      } else {
        if (pos < bigL) {
          on_right.insert(*prev(on_left.end()));
          on_left.erase(prev(on_left.end()));
          res += dots.Read(bigL) - dots.Read(pos);
          bigL = *prev(on_left.end()), smallR = *on_right.begin();
          on_left.insert(pos);
        } else {
          res += dots.Read(pos) - dots.Read(bigL);
          on_right.insert(pos);
        }
      }
      if (SZ(on_right) > SZ(on_left)) {
        on_left.insert(*on_right.begin());
        on_right.erase(on_right.begin());
      }
    }
    End:;
    cout<<res<<" ";
  }
  cout<<endl;
  
  
  return 0;
}