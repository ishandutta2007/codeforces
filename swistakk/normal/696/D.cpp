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

const int N = 212;
PII state_to_pair[N];
const int kInf = 4e18;
string s[N];

VVI Mult(VVI& a, VVI& b) {
  VVI c(N, VI(N, -kInf));
  REP (i, N) {
    REP (j, N) {
      REP (k, N) {
        maxi(c[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return c;
}
int xx[N];
int val[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, l;
  cin>>n>>l;
  int state_id = 1;
  state_to_pair[1] = {0, 0};
  RE (i, n) {
    cin>>xx[i];
  }
  RE (i, n) {
    cin>>s[i];
    RE (j, SZ(s[i])) {
      state_id++;
      PII p = {i, j};
      state_to_pair[state_id] = p;
    }
  }
  RE (st, state_id) {
    PII p = state_to_pair[st];
    string S = s[p.st].substr(0, p.nd);
    RE (i, n) {
      if (SZ(s[i]) <= SZ(S) && S.substr(SZ(S) - SZ(s[i])) == s[i]) {
        val[st] += xx[i];
      }
    }
    debug(st, S, val[st]);
  }
    
    
  VVI r(N, VI(N, -kInf));
  RE (st, state_id) {
    PII p = state_to_pair[st];
    string pref_out = s[p.st].substr(0, p.nd);
    FOR (c, 'a', 'z') {
      string pref_with = pref_out + char(c);
      int best_state = 1;
      int best_len = 0;
      FOR (i, 2, state_id) {
        PII p2 = state_to_pair[i];
        int len = p2.nd;
        int wh = p2.st;
        if (SZ(pref_with) >= len && pref_with.substr(SZ(pref_with) - len) == s[wh].substr(0, len)) {
          if (len > best_len) {
            best_len = len;
            best_state = i;
          }
        }
      }
      r[st][best_state] = val[best_state];
      debug(st, best_state);
    }
  }
  auto a = r;
  RE (i, state_id) {
    RE (j, state_id) {
      cerr<<r[i][j]<<" ";
    }
    cerr<<endl;
  }
  
  l--;
  while (l) {
    if (l % 2) {
      r = Mult(r, a);
    }
    a = Mult(a, a);
    l /= 2;
  }
  int best_ans = 0;
  REP (i, N) {
    maxi(best_ans, r[1][i]);
  }
  cout<<best_ans<<endl;
  RE (i, state_id) {
    RE (j, state_id) {
      cerr<<r[i][j]<<" ";
    }
    cerr<<endl;
  }
      
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}