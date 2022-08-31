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

const int K = 12;
const int L = 66;
int with0[K][L][K]; // baza, dlugosc, npar
int without0[K][L][K];
int newt[K][K];
int Go(int b, int r) {
  if (r < b) { return 0; }
  VI digs;
  int cpr = r;
  while (r) {
    digs.PB(r % b);
    r /= b;
  }
  reverse(ALL(digs));
  debug(digs);
  int res = 0;
  for (int len = 2; len < SZ(digs); len++) {
    res += without0[b][len][0];
  }
  debug(res);
  if (SZ(digs) % 2 == 0) {
    VI par(b);
    int cnt_npar = 0;
    FOR (match, 0, SZ(digs)) {
      if (match == SZ(digs)) {
        res += (par == VI(b, 0));
        continue;
      }
      REP (dig, digs[match]) {
        if (match == 0 && dig == 0) { continue; }
        int cp = cnt_npar;
        if (par[dig]) {
          cnt_npar--;
        } else {
          cnt_npar++;
        }
        res += with0[b][SZ(digs) - match - 1][cnt_npar] / newt[b][cnt_npar];
        cnt_npar = cp;
      }
      if (par[digs[match]]) {
        cnt_npar--;
      } else {
        cnt_npar++;
      }
      par[digs[match]] ^= 1;
    }
  }
  debug(b, cpr, res);
  return res;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  FOR (B, 2, 10) {
    with0[B][0][0] = 1;
    REP (l, L - 1) {
      FOR (npar, 0, B) {
        if (npar) {
          with0[B][l + 1][npar - 1] += with0[B][l][npar] * npar;
        }
        with0[B][l + 1][npar + 1] += with0[B][l][npar] * (B - npar);
      }
    }
  }
  FOR (B, 2, 10) {
    without0[B][0][0] = 1;
    without0[B][1][1] = B - 1;
    FOR (l, 1, L - 2) {
      FOR (npar, 0, B) {
        if (npar) {
          without0[B][l + 1][npar - 1] += without0[B][l][npar] * npar;
        }
        without0[B][l + 1][npar + 1] += without0[B][l][npar] * (B - npar);
      }
    }
  }
  debug(with0[2][2][0], with0[2][2][1], with0[2][2][2]);
  REP (i, K) {
    newt[i][0] = newt[i][i] = 1;
  }
  RE (i, K - 1) {
    RE (j, i - 1) {
      newt[i][j] = newt[i - 1][j] + newt[i - 1][j - 1];
    }
  }
  int q;
  cin>>q;
  REP (_, q) {
    int b, l, r;
    cin>>b>>l>>r;
    cout<<Go(b, r) - Go(b, l - 1)<<"\n";
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}