#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
const int N = 3e3 + 5;

struct Guy {
  int st, nd, ind;
};

Guy g[N];

bool Cmp(Guy a, Guy b) {
  return a.st - a.nd > b.st - b.nd;
}
int dp[N][N];
int a[N], b[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  int n, p, s;
  cin>>n>>p>>s;
  RE (i, n) {
    cin>>a[i];
  }
  RE (i, n) {
    cin>>b[i];
    g[i] = {a[i], b[i], i};
  }
  
  sort(g + 1, g + 1 + n, Cmp);
  VI best_p, best_s;
  int best = 0;
  FOR (i, p, n - s) {
    vector<PII> ps, ss;
    RE (j, i) {
      ps.PB({g[j].st, g[j].ind});
    }
    FOR (j, i + 1, n) {
      ss.PB({g[j].nd, g[j].ind});
    }
    sort(ALL(ps), greater<PII>());
    sort(ALL(ss), greater<PII>());
    int res = 0;
    REP (j, p) {
      res += ps[j].st;
    }
    REP (j, s) {
      res += ss[j].st;
    }
    if (res > best) {
      best = res;
      best_p.clear();
      best_s.clear();
      REP (j, p) {
        best_p.PB(ps[j].nd);
      }
      REP (j, s) {
        best_s.PB(ss[j].nd);
      }
    }
  }
    
    
    
//   REP (i, N) {
//     REP (j, N) {
//       dp[i][j] = -N * N;
//     }
//   }
// #define FORD(i,a,b) for(int i = (a); i >= (b); i--)
//   dp[0][0] = 0;
//   RE (i, n) {
//     FORD (prev_s, s - 1, 0) {
//       maxi(dp[p][prev_s + 1], dp[p][prev_s] + g[i].nd);
//     }
//     FORD (prev_p, p - 1, 0) {
//       maxi(dp[prev_p + 1][0], dp[prev_p][0] + g[i].st);
//     }
//   }
//   cout<<dp[p][s]<<endl;
//   FOR (i, 0, p) {
//     FOR (j, 0, s) {
//       cerr<<dp[i][j]<<" ";
//     }
//     cerr<<endl;
//   }
//   VI pp, ss;
//   int cp = p, cs = s;
//   FORD (i, n, 1) {
//     debug(i, cp, cs, g[i].st, g[i].nd);
//     if (cs) {
//       if (dp[cp][cs] == dp[cp][cs - 1] + g[i].nd) {
//         ss.PB(g[i].ind);
//         cs--;
//       }
//     } else {
//       if (dp[cp][cs] == dp[cp - 1][cs] + g[i].st) {
//         pp.PB(g[i].ind);
//         cp--;
//       }
//     }
//   }
//   assert(cp == 0 && cs == 0);
  cout<<best<<endl;
  for (auto x : best_p) {
    cout<<x<<" ";
  }
  cout<<endl;
  for (auto x : best_s) {
    cout<<x<<" ";
  }
  cout<<endl;
  
    
  
  
    

}