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

const int N = 2e5 + 5;
int last7[N];
int pref6[N];
const int M = 1 << 18;
string s;
map<char, int> mapuj;
const int B = 4;
struct Dp {
  int dp[B][B];
  Dp() {
    REP (i, B) {
      REP (j, B) {
        dp[i][j] = N;
      }
      dp[i][i] = 0;
    }
  }
  void Cerr() {
    REP (i, B) {
      REP (j, B) {
        cerr<<dp[i][j]<<" ";
      }
      cerr<<endl;
    }
    cerr<<endl;
  }
};

Dp drz[2 * M + 5];
Dp Merge(Dp a, Dp b) {
  debug("Mergeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
  a.Cerr();
  b.Cerr();
  Dp res;
  REP (i, B) {
    res.dp[i][i] = N;
    FOR (j, i, B - 1) {
      FOR (k, i, j) {
        mini(res.dp[i][j], a.dp[i][k] + b.dp[k][j]);
      }
    }
  }
  res.Cerr();
  return res;
}

Dp GetDp(int a, int b) {
  debug(a, b);
  a += M;
  b += M;
  if (a == b) {
    return drz[a];
  }
  Dp l = drz[a];
  l.Cerr();
  Dp r = drz[b];
  r.Cerr();
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      debug("prawo", a + 1);
      l = Merge(l, drz[a + 1]);
    }
    if (b % 2 == 1) {
      debug("lewo", b - 1);
      r = Merge(drz[b - 1], r);
    }
    a /= 2;
    b /= 2;
  }
  return Merge(l, r);
}
    

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  mapuj['2'] = 1;
  mapuj['0'] = 2;
  mapuj['1'] = 3;
  mapuj['6'] = 4;
  
  int n, q;
  cin>>n>>q;
  cin>>s;
  s = ' ' + s;
  RE (i, n) {
    pref6[i] = pref6[i - 1] + (s[i] == '6');
    last7[i] = last7[i - 1];
    if (s[i] == '7') {
      last7[i] = i;
    }
    int pos = mapuj[s[i]];
    if (pos == 0) { continue; }
    pos--;
    debug(pos);
    drz[i + M].dp[pos][pos] = 1;
    if (pos + 1 < B) {
      drz[i + M].dp[pos][pos + 1] = 0;
    }
  }
  FORD (i, M - 1, 1) {
    drz[i] = Merge(drz[2 * i], drz[2 * i + 1]);
    
  }
  FOR (i, 1, M - 1) {
    debug(i);
    drz[i].Cerr();
  }
  
  //vector<pkt> zap;
  RE (i, q) {
    int l, r;
    cin>>l>>r;
    int l7 = last7[r];
    if (l7 < l) {
      cout<<"-1\n";
      //invalid[i] = 1;
    } else {
      auto Dp = GetDp(l, l7);
      Dp.Cerr();
      if (Dp.dp[0][3] != N) {
        cout<<Dp.dp[0][3] + pref6[r] - pref6[l7]<<"\n";
      } else {
        cout<<"-1\n";
      }
    }
  }
  

  
  return 0;
}