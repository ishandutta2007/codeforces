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

const int NN = 4e3 + 5;
typedef bitset<NN> B;
/* Bierze macierz N x M z N rownaniami i M zmiennymi, wektor na N wartosci, zwraca
 * jakikolwiek wektor M rozwiazan (lub wektor pusty, gdy uklad sprzeczny) */
const LD kEps = 1E-10;
vector<B> solveSystem(vector<B> coefs, vector<int> values, int M) {
  int N = SZ(coefs);
  vector<bool> vis(N);
  VI wrow(M, -1);
  
  REP (col, M) {
    int which = -1;
    REP (row, N) {
      if (!vis[row] && coefs[row][col]) {
        which = row;
      }
    }
    
    if (which == -1) { continue; }
    vis[which] = true;
    wrow[col] = which;
    
    REP (row, N) {
      if (row == which) { continue; }
      if (coefs[row][col] == 0) { continue; }
      coefs[row] ^= coefs[which];
//       REP (c, M) {
//         coefs[row][c] ^= coefs[which][c];
//       }
      values[row] ^= values[which];
    }
  }
  
  REP (row, N) {
    if (!vis[row] && values[row]) { return {}; }
  }
  
  B result;
  REP (col, M) {
    if (wrow[col] != -1) {
      assert(coefs[wrow[col]][col]);
      result[col] = values[wrow[col]];
    }
  }
  return {result};
}

int r[NN], y[NN], b[NN], e[NN];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, k;
  cin>>n>>k;
  vector<B> eqs;
  vector<int> vals;
  RE (i, n) {
    r[i] = 4 * i - 4;
    y[i] = 4 * i - 3;
    b[i] = 4 * i - 2;
    e[i] = 4 * i - 1;
    B ziom;
    ziom[r[i]] = 1;
    ziom[y[i]] = 1;
    ziom[b[i]] = 1;
    ziom[e[i]] = 1;
    eqs.PB(ziom);
    vals.PB(1);
  }
  RE (i, k) {
    string typ;
    cin>>typ;
    vector<int> inds;
    int c;
    cin>>c;
    RE (j, c) {
      int a;
      cin>>a;
      inds.PB(a);
    }
    if (typ == "YB") {
      for (auto ind : inds) {
        swap(y[ind], b[ind]);
      }
    } else if (typ == "RB") {
      for (auto ind : inds) {
        swap(r[ind], b[ind]);
      }
    } else if (typ == "RY") {
      for (auto ind : inds) {
        swap(r[ind], y[ind]);
      }
    } else {
      assert(typ == "mix");
      char res;
      cin>>res;
      B yb, rb;//, ry;
      for (auto ind : inds) {
        yb[b[ind]] = 1;
        yb[y[ind]] = 1;
        rb[b[ind]] = 1;
        rb[r[ind]] = 1;
        //ry[r[ind]] = 1;
        //ry[y[ind]] = 1;
      }
      eqs.PB(yb);
      vals.PB(res == 'Y' || res == 'B');
      eqs.PB(rb);
      vals.PB(res == 'R' || res == 'B');
      //eqs.PB(ry);
      //vals.PB(
    }
  }
  vector<B> solv = solveSystem(eqs, vals, 4 * n);
  if (solv.empty()) {
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  B sol = solv[0];
  REP (i, n) {
    REP (j, 4) {
      cerr<<sol[4 * i + j];
    }
    cerr<<endl;
  }
  RE (i, n) {
    int sum = 0;
    FOR (j, 4 * i - 4, 4 * i - 1) {
      sum += sol[j];
    }
    assert(sum == 1 || sum == 3);
    if (sum == 3) {
      FOR (j, 4 * i - 4, 4 * i - 1) {
        sol[j].flip();
      }
    }
    if (sol[4 * i - 4]) {
      cout<<"R";
    } else if (sol[4 * i - 3]) {
      cout<<"Y";
    } else if (sol[4 * i - 2]) {
      cout<<"B";
    } else {
      assert(sol[4 * i - 1]);
      cout<<".";
    }
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}