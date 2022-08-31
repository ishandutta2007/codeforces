#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 2e3 + 5;
const int kInf = 1e9;
int dis[N][720][10];
int mapuj[10][10][10][10];
typedef array<int, 4> A;
A who[(int)1e5];
struct State {
  int guys, state, fl;
};
int a[N], b[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>a[i]>>b[i];
  }
  int nxt = 0;
  REP (i, 10) {
    REP (j, i + 1) {
      REP (k, j + 1) {
        REP (l, k + 1) {
          mapuj[i][j][k][l] = nxt;
          who[nxt] = {i, j, k, l};
          nxt++;
        }
      }
    }
  }
  debug(nxt);
  assert(nxt < 720);
  vector<State> que;
  que.PB({0, mapuj[0][0][0][0], 1});
  REP (i, N) {
    REP (j, 720) {
      REP (k, 10) {
        dis[i][j][k] = kInf;
      }
    }
  }
  dis[0][mapuj[0][0][0][0]][1] = 0;
  for (int i = 0; i < SZ(que); i++) {
    auto cur = que[i];
    if (cur.guys == n && cur.state == 0) {
      cout<<dis[cur.guys][cur.state][cur.fl]<<endl;
      return 0;
    }
    A s = who[cur.state];
    debug(cur.guys, s[0], s[1], s[2], s[3], cur.fl);
    int got = 0;
    int is_free = 0;
    for (auto& x : s) {
      if (x == cur.fl) {
        x = 0;
        got = 1;
        break;
      } else if (x == 0) {
        is_free = 1;
      }
    }
    if (got) {
      sort(ALL(s), greater<int>());
      int state_ind = mapuj[s[0]][s[1]][s[2]][s[3]];
      if (dis[cur.guys][state_ind][cur.fl] == kInf) {
        dis[cur.guys][state_ind][cur.fl] = dis[cur.guys][cur.state][cur.fl] + 1;
        que.PB({cur.guys, state_ind, cur.fl});
      }
    } else {
      if (is_free && cur.fl == a[cur.guys + 1]) {
        for (auto& x : s) {
          if (x == 0) {
            x = b[cur.guys + 1];
            break;
          }
        }
        sort(ALL(s), greater<int>());
        int state_ind = mapuj[s[0]][s[1]][s[2]][s[3]];
        if (dis[cur.guys + 1][state_ind][cur.fl] == kInf) {
          dis[cur.guys + 1][state_ind][cur.fl] = dis[cur.guys][cur.state][cur.fl] + 1;
          que.PB({cur.guys + 1, state_ind, cur.fl});
        }
      } else {
        FOR (dfl, -1, 1) {
          if (dfl == 0) { continue; }
          int nfl = cur.fl + dfl;
          if (nfl == 0 || nfl == 10) { continue; }
          if (dis[cur.guys][cur.state][nfl] == kInf) {
            dis[cur.guys][cur.state][nfl] = dis[cur.guys][cur.state][cur.fl] + 1;
            que.PB({cur.guys, cur.state, nfl});
          }
        }
      }
    }
  }

  
  return 0;
}