#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define PII pair<int,int>
#define VI vector<int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C&a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int cnt_bits[33];

const int N = 1e6 + 5;
int a[N], b[N], c[N];
void Exit() {
  cout<<"-1\n";
  exit(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  
  int n;
  cin>>n;
  int S = 0;
  RE (i, n) {
    cin>>b[i];
    S += b[i];
  }
  RE (i, n) {
    cin>>c[i];
    S += c[i];
  }
  S /= (2 * n);
  RE (i, n) {
    a[i] = (b[i] + c[i] - S) / n;
    if (a[i] < 0) { Exit(); }
    if (a[i] > 1e9) { Exit(); }
    debug(i, a[i]);
    REP (bit, 31) {
      if (a[i] & (1 << bit)) {
        cnt_bits[bit]++;
      }
    }
  }
  REP (bit, 4) {
    debug(bit, cnt_bits[bit]);
  }
  
  RE (i, n) {
    int sb = 0, sc = 0;
    REP (bit, 31) {
      int B = (1 << bit);
      if (a[i] & B) {
        debug(cnt_bits[bit], B, B * cnt_bits[bit]);
        sb += B * cnt_bits[bit];
        sc += B * n;
      } else {
        sc += B * cnt_bits[bit];
      }
    }
    debug(sb, sc);
    if (sb != b[i] || sc != c[i]) {
      Exit();
    } 
  }
  RE (i, n) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  
  
  
  
  

}