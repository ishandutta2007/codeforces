#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
//#define int long long
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
// #define next ____next
// #define prev ____prev
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

#define LL long long

const int N = 60;
LL newt[N][N];

// int Unfairness(int R, int C, string s) {
//   int len = 2 * (R + C);
//   int loseA = 0, loseB = 0;
//   int cntA = 0, cntB = 0;
//   REP (i, len) {
//     int x = len - i - 1;
//     if (s[i] == 'A') {
//       REP (down, R) {
//         loseA += newt[cntA][R - 1] * newt[cntB][down] * newt[x][R - down];
//       }
//       cntA++;
//     } else {
//       REP (down, R) {
//         loseB += newt[cntB][R - 1] * newt[cntA][down] * newt[x][R - down];
//       }
//       cntB++;
//     }
//   }
//   debug(loseA, loseB, newt[2 * (R + C)][2 * R]);
//   return abs(loseA - loseB);
// }
// 
// int Unfairness2(int R, int C, string s) {
//   VI pr(R + C + 1);
//   RE (i, R + C) {
//     pr[i] = newt[i][R] - newt[i - 1][R];
//   }
//   VI whA, whB;
//   REP (i, SZ(s)) {
//     if (s[i] == 'A') {
//       whA.PB(i);
//     } else {
//       whB.PB(i);
//     }
//   }
//   int loseA = 0, loseB = 0;
//   RE (i, R + C) {
//     RE (j, R + C) {
//       if (whA[i - 1] < whB[j - 1]) {
//         loseA += pr[i] * pr[j];
//       } else {
//         loseB += pr[i] * pr[j];
//       }
//     }
//   }
//   debug(loseA, loseB);
//   return abs(loseA - loseB);
// }
//   
  

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  REP (i, N) {
    newt[i][i] = newt[i][0] = 1;
  }
  RE (i, N - 1) {
    RE (j, i - 1) {
      newt[i][j] = newt[i - 1][j] + newt[i - 1][j - 1];
    }
  }
  
//   int R = 2, C = 4;
//   
//   string s = "BBAAABABABBA";
//   debug(Unfairness(R, C, s));
//   int sum = 0;
//   RE (i, R + C) {
//     int x = newt[i][R] - newt[i - 1][R]; 
//     cerr<<x<<" ";
//     sum += x;
//   }
//   cerr<<endl;
//   debug(sum, newt[R + C][R]);
//   debug(Unfairness2(R, C, s));
  
  int R, C;
  cin>>R>>C;
  string s;
  cin>>s;
  if (s == "a") {
    s = string(2 * (R + C), '?');
  }
  s = ' ' + s;
  int L = R + C;
  VI cA(2 * L + 1), cB(2 * L + 1);
  RE (i, SZ(s) - 1) {
    cA[i] = cA[i - 1] + (s[i] == 'A');
    cB[i] = cB[i - 1] + (s[i] == 'B');
  }
  debug(cA, cB);
  vector<vector<LL>> board(L + 1, vector<LL>(L + 1));
  vector<LL> pr(L);
  RE (i, L) {
    pr[i] = newt[i][R] - newt[i - 1][R];
  }
  RE (i, L) {
    RE (j, L) {
      board[i][j] = pr[i] * pr[j];
    }
  }
  vector<vector<LL>> pref_row = board;
  vector<vector<LL>> pref_col = board;
  vector<vector<LL>> pref_rec = board;
  RE (i, L) {
    RE (j, L) {
      pref_row[i][j] += pref_row[i][j - 1];
      pref_col[i][j] += pref_col[i - 1][j];
      pref_rec[i][j] += pref_rec[i - 1][j] + pref_rec[i][j - 1] - pref_rec[i - 1][j - 1];
    }
  }
  LL best_found = 0;
  FORD (i, L, 1) {
    debug(board[i][i]);
    if (best_found <= 0) {
      best_found += board[i][i];
    } else {
      best_found -= board[i][i];
    }
  }
  //debug(cand);
  debug(best_found);
  best_found = abs(best_found);
  best_found = 5e18;
  int branch_len = min(L, 20);
  vector<vector<vector<map<LL, int>>>> preproc(2, vector<vector<map<LL, int>>>(L + 1, vector<map<LL, int>>(L + 1)));
  
  REP (need_match, 2) {
    function<void(int, int, int)> Gen = [&](int i, int j, int cur_bil) {
      if (i + j == branch_len) {
        preproc[need_match][i][j][cur_bil]++;
        return;
      }
      if (!need_match || s[i + j + 1] != 'A') {
        Gen(i, j + 1, cur_bil + pref_col[i][j + 1]);
      }
      if (!need_match || s[i + j + 1] != 'B') {
        Gen(i + 1, j, cur_bil - pref_row[i + 1][j]);
      }
    };
    Gen(0, 0, 0);
  };
//     REP (mask, 1 << branch_len) {
//       int i = 0, j = 0;
//       int cur_bil = 0;
//       bool fail = false;
//       REP (bit, branch_len) {
//         if (mask & (1 << bit)) { // B, idz w prawo
//           cur_bil += pref_col[i][j + 1];
//           if (need_match && s[i + j + 1] == 'A') {
//             fail = true;
//             break;
//           }
//           j++;
//         } else {
//           cur_bil -= pref_row[i + 1][j];
//           if (need_match && s[i + j + 1] == 'B') {
//             fail = true;
//             break;
//           }
//           i++;
//         }
//       }
//       if (!fail) {
//         preproc[need_match][i][j][cur_bil]++;
//       }
//     }
//   }
  debug("preproc", 1. * clock() / CLOCKS_PER_SEC);
  LL res = 0;
  int need_match = 0;
  function<void(int, int, LL)> Bt = [&](int i, int j, LL cur_bil) {
    if (i < R || j < R) {
      mini(best_found, abs(cur_bil));
      if (need_match) {
        if (abs(cur_bil) == best_found) {
          int remA = i - cA[i + j],
              remB = j - cB[i + j];
          if (remA >= 0 && remB >= 0) {
            debug(remA, remB);
            res += newt[remA + remB][remA];
          }
        }
      }
      return;
    }
    if (i + j == branch_len) {
      if (need_match == 0) {
        auto& M = preproc[0][i][j];
        auto it = M.lower_bound(-cur_bil);
        if (it != M.end()) {
          mini(best_found, cur_bil + it->st);
        }
        if (it != M.begin()) {
          mini(best_found, abs(cur_bil + prev(it)->st));
        }
      } else {
        res += preproc[1][i][j][best_found - cur_bil];
        if (best_found) {
          res += preproc[1][i][j][-best_found - cur_bil];
        }
      }
      return;
    }
    if (i + j == 0) {
      mini(best_found, abs(cur_bil));
    }
    if (cur_bil - pref_rec[i][j] > best_found || cur_bil + pref_rec[i][j] < -best_found) { return; }
    if (cur_bil > 0) {
      if (i > 0 && (!need_match || s[i + j] != 'B')) {
        Bt(i - 1, j, cur_bil - pref_row[i][j]);
      }
      if (j > 0 && (!need_match || s[i + j] != 'A')) {
        Bt(i, j - 1, cur_bil + pref_col[i][j]);
      }
    } else {
      if (j > 0 && (!need_match || s[i + j] != 'A')) {
        Bt(i, j - 1, cur_bil + pref_col[i][j]);
      }
      if (i > 0 && (!need_match || s[i + j] != 'B')) {
        Bt(i - 1, j, cur_bil - pref_row[i][j]);
      }
    }
  };
  Bt(L, L, 0);
  need_match = 1;
  debug(best_found);
  Bt(L, L, 0);
  cout<<res<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}