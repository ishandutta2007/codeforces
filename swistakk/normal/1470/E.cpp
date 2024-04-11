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
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<endl; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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

struct Sol {
  void Test() {
    int n, c, q;
    cin>>n>>c>>q;
    VI p(n + 2);
    RE (i, n) {
      cin>>p[i];
    }
    VVI dp(n + 2, VI(c + 2));
    vector<VVI> jumps(n + 2, VVI(c + 2, VI(20, 2e18)));
    dp[0] = VI(c + 2, 1);
    RE (i, n) {
      REP (j, c + 1) {
        REP (sub_c, j + 1) {
          if (i - 1 - sub_c < 0) { continue; }
          dp[i][j] += dp[i - 1 - sub_c][j - sub_c];
        }
      }
    }
    debug(dp[n]);
    
    RE (i, n) {
      FOR (j, 0, c) {
        int omit = 0;
        RE (steps, j) {
          if (i + steps > n) { continue; }
          if (p[i + steps] < p[i]) {
            omit += dp[n - i - steps][j - steps];
          }
        }
        jumps[i][j][0] = omit;
        //debug(i, j, jumps[i][j][0]);
      }
    }
    cerr<<endl;
    
    RE (layer, 20) {
      RE (i, n) {
        int dist = 1 << (layer - 1);
        if (i + dist > n) { continue; }
        FOR (j, 0, c) {
          jumps[i][j][layer] = jumps[i][j][layer - 1] + jumps[i + dist][j][layer - 1];
          if (jumps[i][j][layer] > 1e18) {
            jumps[i][j][layer] = 1e18;
          }
        }
      }
    }
    
    RE (i, q) {
      int pos, to_omit;
      cin>>pos>>to_omit;
      to_omit--;
      if (to_omit >= dp[n][c]) {
        cout<<"-1\n";
        continue;
      }
      int cur_i = 1;
      int cur_c = c;
      int huh = 0;
      while (1) {
        int layer = 18;
        while (layer >= 0) {
          int nxt = cur_i + (1 << layer);
          if (nxt > n) {
            layer--;
            continue;
          }
          //debug(cur_i, cur_c, layer, jumps[cur_i][cur_c][layer]);
          if (jumps[cur_i][cur_c][layer] <= to_omit && dp[n + 1 - nxt][cur_c] > to_omit - jumps[cur_i][cur_c][layer]) {
            to_omit -= jumps[cur_i][cur_c][layer];
            cur_i = nxt;
            //debug("go", layer);
          }
          layer--;
        }
        if (cur_i > pos) {
          cout<<p[pos]<<"\n";
          goto End;
        }
        // aktualnie mam dp[n + 1 - cur_i][cur_c] mozliwosci
        VPII branches;
        int control = 0;
        FOR (steps, 0, cur_c) {
          if (cur_i + steps > n) { continue; }
          branches.PB({cur_i + steps, dp[n - cur_i - steps][cur_c - steps]});
          control += branches.back().nd;
        }
        //assert(control == dp[n + 1 - cur_i][cur_c]);
        sort(ALL(branches), [&](PII A, PII B) { return p[A.st] < p[B.st]; });
        //debug(to_omit);
        //debug(branches);
        huh++;
        assert(huh <= 6);
        for (auto branch : branches) {
          if (branch.nd <= to_omit) {
            to_omit -= branch.nd;
            continue;
          }
          if (pos <= branch.st) {
            int from_end = pos - cur_i;
            debug(n, from_end, branch.st);
            cout<<p[branch.st - from_end]<<"\n";
            goto End;
          }
          assert(branch.st != cur_i);
          cur_c -= branch.st - cur_i;
          cur_i = branch.st + 1;
          debug("manual", cur_i, cur_c);
          break;
        }
      }
      End: ;
    }
    
    
    
    
    
    
    
  }
};

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int t;
  cin>>t;
  RE (i, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}