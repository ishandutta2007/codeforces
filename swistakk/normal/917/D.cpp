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

const int P = 1e9 + 7;
const int N = 111;
int sz[N];
int tmp[N][N];
int dp[N][N][N]; // dp[v][del][sz] w wierzcholku v, wyrzucilem del, wielkosc sz
// (a, b) (c, d) -> (a + c, b + d) 
vector<int> slo[N];
int vis[N];
void Merge(int L, int R, int sL, int sR) {
  REP (i, sL + sR + 1) {
    REP (j, sL + sR + 1) {
      tmp[i][j] = 0;
    }
  }
  FOR (delL, 0, sL - 1) {
    FOR (delR, 0, sR - 1) {
      RE (rL, sL) {
        RE (rR, sR) {
          int& D = tmp[delL + delR][rL + rR];
          D = (D + dp[L][delL][rL] * dp[R][delR][rR]) % P;
          int& E = tmp[delL + delR + 1][rL];
          E = (E + dp[L][delL][rL] * dp[R][delR][rR] % P * rR) % P;
        }
      }
    }
  }
  REP (i, sL + sR + 1) {
    REP (j, sL + sR + 1) {
      dp[L][i][j] = tmp[i][j];
    }
  }
}
void Dfs(int v) {
  vis[v] = 1;
  sz[v] = 1;
  dp[v][0][1] = 1;
  for (auto nei : slo[v]) {
    if (vis[nei]) { continue; }
    Dfs(nei);
    Merge(v, nei, sz[v], sz[nei]);
    sz[v] += sz[nei];
  }
}

int S[N];
int newt[N][N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  Dfs(1);
  
  RE (szr, n) {
    REP (del, n) {
      S[del] = (S[del] + dp[1][del][szr] * szr) % P;
    }
  }
  int npow = 1;
  REP (del, n) {
    S[del] = (S[del] * npow) % P;
    if (del == 0) {
      S[del] = 1;
    }
    if (del >= 1) {
      npow = npow * n % P;
    }
    debug(del, S[del]);
  }
  REP (i, N) {
    newt[i][i] = newt[i][0] = 1;
  }
  REP (i, N) {
    RE (j, i - 1) {
      newt[i][j] = (newt[i - 1][j] + newt[i - 1][j - 1]) % P;
    }
  }
  REP (del, n) {
    REP (bef, del) {
      S[del] = (S[del] - S[bef] * newt[n - 1 - bef][del - bef] % P + P) % P;
    }
  }
  FORD (del, n - 1, 0) {
    cout<<S[del]<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}