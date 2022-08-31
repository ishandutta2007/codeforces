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

const int N = 55;
const int kInf = 1e9;
int dp[N][N]; // dp[v][z] - czas potrzebny policjantowi, jezeli jest w v i zostalo z zlodziei
int deg[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  REP (i, N) {
    REP (j, N) {
      dp[i][j] = kInf;
    }
    dp[i][0] = 0;
  }
  int n;
  cin>>n;
  VVI dis(n + 2, VI(n + 2, kInf));
  RE (i, n) {
    dis[i][i] = 0;
  }
  VPII edges;
  RE (i, n - 1) {
    int a, b, w;
    cin>>a>>b>>w;
    edges.PB({a, b});
    deg[a]++;
    deg[b]++;
    dis[a][b] = w;
    dis[b][a] = w;
  }
  RE (k, n) {
    RE (i, n) {
      RE (j, n) {
        mini(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  int s;
  cin>>s;
  int m;
  cin>>m;
  VI pos;
  RE (i, m) {
    int a;
    cin>>a;
    pos.PB(a);
  }
  VI leaves;
  RE (i, n) {
    if (deg[i] == 1) {
      leaves.PB(i);
    }
  }
  debug(leaves);
  RE (cnt, m) {
    for (auto v : leaves) {
      int kl1 = 0, kp1 = kInf, faj1 = 0;
      while (kl1 <= kp1) {
        int aktc1 = (kl1 + kp1) / 2;
        int cur = 0;
        for (auto l : leaves) {
          int kl2 = 0, kp2 = cnt, faj2 = 0;
          while (kl2 <= kp2) { // faj2 to najwiecej ile mozemy umiescic w l tak aby to nie bylo dobre dla policjanta
            int aktc2 = (kl2 + kp2) / 2;
            if (dp[l][cnt - aktc2] + dis[v][l] >= aktc1) {
              faj2 = aktc2;
              kl2 = aktc2 + 1;
            } else {
              kp2 = aktc2 - 1;
            }
          }
          cur += faj2;
        }
        if (cur >= cnt) { // da sie policjanta zmusic do czasu aktc1
          kl1 = aktc1 + 1;
          faj1 = aktc1;
        } else {
          kp1 = aktc1 - 1;
        }
      }
      dp[v][cnt] = faj1;
      debug(v, cnt, faj1);
    }
  }
  
  
  VI neis;
  for (auto e : edges) {
    if (e.st == s || e.nd == s) {
      neis.PB(e.st + e.nd - s);
    }
  }
  int best = kInf;
  for (auto sub : neis) {
    int cnt_in_sub = 0;
    VI leaves_in_sub;
    for (auto l : leaves) {
      if (dis[s][sub] + dis[sub][l] == dis[s][l]) {
        leaves_in_sub.PB(l);
      }
    }
    for (auto cr : pos) {
      if (dis[s][sub] + dis[sub][cr] == dis[s][cr]) {
        cnt_in_sub++;
      }
    }
    int kl1 = 0, kp1 = kInf, faj1 = 0;
    while (kl1 <= kp1) {
      int aktc1 = (kl1 + kp1) / 2;
      int cur = 0;
      for (auto l : leaves_in_sub) {
        int kl2 = 0, kp2 = cnt_in_sub, faj2 = 0;
        while (kl2 <= kp2) { // faj2 to najwiecej ile mozemy umiescic w l tak aby to nie bylo dobre dla policjanta
          int aktc2 = (kl2 + kp2) / 2;
          if (dp[l][m - aktc2] + dis[s][l] >= aktc1) {
            faj2 = aktc2;
            kl2 = aktc2 + 1;
          } else {
            kp2 = aktc2 - 1;
          }
        }
        cur += faj2;
      }
      if (cur >= cnt_in_sub) { // da sie policjanta zmusic do czasu aktc1
        kl1 = aktc1 + 1;
        faj1 = aktc1;
      } else {
        kp1 = aktc1 - 1;
      }
    }
    mini(best, faj1);
  }
  cout<<best<<endl;
      
    

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}