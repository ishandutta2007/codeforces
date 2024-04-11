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

// tree[used][flow] - ile jest drzew z used wierzcholkow, ktore maja flowa == flow
// forest[used][flow] - ile jest lasow z used wierzcholkow, ktore maja flowa == flow
// forest_suf[used][flow] - flow >= flow
// tree[1][x] = (x <= 1)
// jak mamy k obiektow o takich samych wlasnosciach i trzeba z nich wybrac l
// to to jest l nierozroznialnych kulek w k kubkach => (l + k - 1 po l)
// dp[v][f] = 
// forest[used][flow] sklada sie z tree[v <= used][f <= flow]
// tree[used][flow] sklada sie z dwoch forestow[v < used][f == flow - 1]
// tree[used][flow] = sum forest[x][flow - 1] * forest[used - 1 - x][flow - 1]

const int N = 55;
int tree[N][N];
int forest[N][N];
int forest_suf[N][N];
const int P = 1e9 + 7;
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int Inv(int a) {
  return spow(a, P - 2);
}
int inv[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  RE (i, N - 1) {
    inv[i] = Inv(i);
  }
  
  int n, m;
  cin>>n>>m;
  
  tree[0][0] = 1;
  tree[1][1] = 1;
  forest[0][0] = 1;
  forest_suf[0][0] = 1;
  FOR (used, 1, n) {
    if (used > 1) {
      FOR (flow, 1, n) {
        FOR (x, 0, used - 1) {
          tree[used][flow] = (tree[used][flow] + forest_suf[x][flow - 1] * forest_suf[used - 1 - x][flow - 1]) % P;
        }
      }
      FOR (flow, 1, n) {
        tree[used][flow] = (tree[used][flow] - tree[used][flow + 1] + P) % P;
      }
    }
    FOR (flow, 0, n) {
      FORD (pr_used, n - used, 0) {
        FORD (pr_flow, n - flow, 0) {
          int acc = 1;
          FOR (l, 1, (n - pr_used) / used) {
            if (pr_flow + flow * l > N - 1) { break; }
            acc *= (tree[used][flow] + l - 1);
            acc %= P;
            acc *= inv[l];
            acc %= P;
            forest[pr_used + used * l][pr_flow + flow * l] =
                (forest[pr_used + used * l][pr_flow + flow * l] + acc * forest[pr_used][pr_flow]) % P;
          }
        }
      }
    }
    FOR (for_used, 1, n) {
      FORD (for_flow, n + 1, 0) {
        forest_suf[for_used][for_flow] = (forest_suf[for_used][for_flow + 1] + forest[for_used][for_flow]) % P;
      }
    }
  }
  RE (v, 7) {
    FOR (f, 0, 3) {
      cerr<<tree[v][f]<<" ";
    }
    cerr<<endl;
  }
  cerr<<endl;
  RE (v, 7) {
    FOR (f, 0, 3) {
      cerr<<forest[v][f]<<" ";
    }
    cerr<<endl;
  }
  cerr<<endl;
  RE (v, 7) {
    FOR (f, 0, 3) {
      cerr<<forest_suf[v][f]<<" ";
    }
    cerr<<endl;
  }
  cerr<<endl;
  
  cout<<forest[n][m - 1] % P<<endl;
  //cout<<(Go(n, m) - Go(n, m + 1) + P) % P<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}