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

int biggest_q;
int cnt_q;
int goal;
bool Can(int x) {
#ifdef LOCAL
  cnt_q++;
  return x <= goal;
#else
  cout<<"? "<<x<<endl;
  string s;
  cin>>s;
  if (s[0] == 'L') {
    return true;
  } else {
    return false;
  }
#endif
}

void Go(int budget, int max_safe, int min_bust) {
  if (max_safe + 1 == min_bust) {
    cout<<"! "<<min_bust - 1<<endl;
#ifdef LOCAL
    assert(min_bust - 1 == goal);
    //debug(cnt_q);
    maxi(biggest_q, cnt_q);
    cnt_q = 0;
#endif
    return;
  }
//   if (budget < 2 * max_safe) {
//     assert(Can(max_safe));
//     return Go(budget + max_safe, max_safe, min_bust);
//   }
  int nxt_ask;
  if (min_bust > 2 * max_safe) {
    nxt_ask = budget;
  } else {
    LD S, B;
    if (budget > 7 * max_safe) {
      S = 1.1;
      B = 1;
    } else if (budget > 5 * max_safe) {
      S = 1.3;
      B = 1;
    } else if (budget > 3 * max_safe) {
      S = 1.618;
      B = 1;
    } else {
      S = 2.2;
      B = 1;
    }
    nxt_ask = (max_safe * S + min_bust * B) / (S + B);
    maxi(nxt_ask, max_safe + 1);
    mini(nxt_ask, min_bust - 1);
  }
  if (budget < nxt_ask || budget <= max_safe) {
    assert(Can(max_safe));
    return Go(budget + max_safe, max_safe, min_bust);
  }
  if (Can(nxt_ask)) {
    Go(budget + nxt_ask, nxt_ask, min_bust);
  } else {
    Go(budget - nxt_ask, max_safe, nxt_ask);
  }
}


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  srand(clock());
  int M = 1e9;
  int C = 1e5;
  int t;
#ifdef LOCAL
  t = 1000000;
  //t = 1;
  //goal = C * (rand() % M) + rand() % C;
#else
  cin>>t;
#endif
  RE (i, t) {
    int ziom = 1e14;
#ifdef LOCAL
    //goal = 35184372088842ll;
    //goal = 35184372088849ll;
    goal = C * (rand() % M) + rand() % C;
#endif
    if (Can(1)) {
      Go(2, 1, ziom + 1);
    } else {
      cout<<"! 0"<<endl;
    }
    //Go(1, 0, ziom + 1);
  }
  debug(biggest_q);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}