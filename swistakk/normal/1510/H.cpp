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
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<pair<int, int> > VPII;
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


const int N = 4e3 + 20;
int sz[N];
int last_ind[N];
int from[N][2];
int32_t dp[N][N][2][2]; // dp[i][j][l][r] - najlepszy wynik dla odcinka i jak z przyszloci mi przyjdzie j przedzialow oraz l na lewo i r na prawo
int32_t old[N][N][2][2];
VVI ch;
struct Seg {
  int l, r;
};
int nxt;
vector<Seg> seg;
int wh_v[N];
int bd[N];
void Dfs(int v) {
  sz[v] = 1;
  if (ch[v].empty()) {
    last_ind[v] = nxt;
    REP (l, 2) {
      REP (r, 2) {
        dp[nxt][0][l][r] = seg[v].r - seg[v].l;
      }
    }
    wh_v[nxt] = v;
    from[nxt][0] = -1;
    from[nxt][1] = v;
    nxt++;
    return;
  }
  sort(ALL(ch[v]), [&](int a, int b) { return seg[a].l < seg[b].l; });
  for (auto c : ch[v]) {
    Dfs(c);
  }
  VI rs;
  RE (i, SZ(ch[v]) - 1) {
    rs.PB(seg[ch[v][i]].l);
  }
  rs.PB(seg[v].r);
  
  int f = ch[v][0];
  int li = last_ind[f];
  from[nxt][0] = li;
  from[nxt][1] = -1;
  REP (l, 2) {
    REP (r, 2) {
      REP (s, 2 * sz[f] + 4) {
        dp[nxt][s][l][r] = dp[li][s][l][r] + l * (seg[f].l - seg[v].l) + r * (rs[0] - seg[f].r);
        if (nxt == 435 && s == 2 && l == 0 && r == 0 && dp[li][s][l][r] + l * (seg[f].l - seg[v].l) + r * (rs[0] - seg[f].r) == 723) {
          debug("heheheh");
          dp[435][2][0][0] == 723;
        }
      }
    }
  }
  sz[v] += sz[f];
//   REP (s, 2 * sz[f] + 4) {
//     REP (l, 2) {
//       maxi(dp[nxt][s + 1][l][0], dp[nxt][s][l][1]);
//     }
//     REP (r, 2) {
//       maxi(dp[nxt][s + 1][0][r], dp[nxt][s][1][r]);
//     }
//   }
  wh_v[nxt] = v;
  nxt++;
  RE (i, SZ(ch[v]) - 1) {
    auto c = ch[v][i];
    auto S = seg[c];
    
    from[nxt][0] = nxt - 1;
    li = last_ind[c];
    from[nxt][1] = li;
    bd[nxt] = rs[i];
    REP (fl, 2 * sz[v] + 4) {
      REP (fr, 2 * sz[c] + 4) {
        REP (ll, 2) {
          REP (rr, 2) {
            maxi(dp[nxt][fl + fr][ll][rr], (int32_t)(dp[nxt - 1][fl][ll][0] + dp[li][fr][0][rr] + rr * (rs[i] - S.r)));
            if (nxt == 435 && fl + fr == 2 && ll == 0 && rr == 0 && dp[nxt - 1][fl][ll][0] + dp[li][fr][0][rr] + rr * (rs[i] - S.r) == 723) {
              debug("dupa");
              debug(fl, fr, rs[i] - S.r, nxt - 1, li, dp[nxt - 1][fl][ll][0], dp[li][fr][0][rr] + rr * (rs[i] - S.r));
            }
            maxi(dp[nxt][fl + fr + 1][ll][rr], (int32_t)(dp[nxt - 1][fl][ll][1] + dp[li][fr][1][rr] + rr * (rs[i] - S.r)));
          }
        }
      }
    }
    sz[v] += sz[c];
    wh_v[nxt] = v;
    nxt++;
  }
  last_ind[v] = nxt - 1;
  nxt--;
  REP (f, 2 * sz[v] + 4) {
    REP (l, 2) {
      REP (r, 2) {
        old[nxt][f][l][r] = dp[nxt][f][l][r];
        dp[nxt][f][l][r] = -1;
      }
    }
  }
  REP (f, 2 * sz[v] + 4) {
//     if (f >= 2 * sz[v]) {
//       REP (l, 2) {
//         REP (r, 2) {
//           dp[nxt][f][l][r] = -1;
//         }
//       }
//       break;
//     }
    maxi(dp[nxt][f][0][0], old[nxt][f][1][0]);
    maxi(dp[nxt][f][0][0], old[nxt][f][0][1]);
    maxi(dp[nxt][f][1][0], old[nxt][f][1][1]);
    maxi(dp[nxt][f][0][1], old[nxt][f][1][1]);
    REP (l, 2) {
      REP (r, 2) {
        maxi(dp[nxt][f][l][r], old[nxt][f + 1][l][r]);
        maxi(dp[nxt][f][l][r], old[nxt][f][l][r]);
        if (dp[nxt][f][l][r] > seg[v].r - seg[v].l) {
          debug(nxt, f, l, r, v, seg[v].l, seg[v].r, dp[nxt][f][l][r]);
        }
        //assert(dp[nxt][f][l][r] <= seg[v].r - seg[v].l);
      }
    }
    
  }
  
  nxt++;
}

int L[N];
int R[N];
VPII intvs;
int tmm;
int cnt;
PII Restore(int wh, int f, int l, int r) {
  assert(wh >= 0);
  cnt++;
  assert(cnt <= 1e4);
  int v = wh_v[wh];
  if (from[wh][0] == -1) {
    //assert(ch[v].empty());
    intvs.PB({seg[v].l, seg[v].r});
    return {seg[v].l, seg[v].r};
  }
  
  int val = dp[wh][f][l][r];
  int putl = 0, putr = 0;
  int dupa = 0;
  if (wh == last_ind[v]) {
    Beg: ;
    if (l == 0 && dp[wh][f][0][r] == old[wh][f][1][r]) {
      val = old[wh][f][1][r];
      l = 1;
      putl = 1;
    } else if (r == 0 && dp[wh][f][l][0] == old[wh][f][l][1]) {
      val = old[wh][f][l][1];
      r = 1;
      putr = 1;
    } else {
      if (dp[wh][f][l][r] == old[wh][f + 1][l][r]) {
        //debug(from[wh][0], from[wh][1], wh, ch[v], v, f, l, r, dp[wh][f][l][r], old[wh][f + 1][1][1]);
        val = old[wh][f + 1][l][r];
        f++;
      } else {
        val = dp[wh][f][l][r];
        dupa++;
        if (dupa <= 5) {
          goto Beg;
        }
      }
    }
  }
  //debug(f, l, r, putl, putr);
  auto H = seg[v];
  if (from[wh][1] == -1) {
    assert(from[wh][0] < wh);
    PII heh = Restore(from[wh][0], f, l, r);
    if (putr) {
      intvs.PB({heh.nd, H.r});
    }
    if (putl) {
      intvs.PB({H.l, heh.st});
    }
    return heh;
  }
  
  int p1 = from[wh][0];
  int p2 = from[wh][1];
  assert(p1 < wh && p2 < wh);
  int c = wh_v[p2];
  sz[v] -= sz[c];
  auto S = seg[c];
  tmm += sz[v] * sz[c];
  assert(tmm < 1e7);
  
  REP (fl, 2 * sz[v] + 4) {
    FOR (fr, max(0ll, f - fl - 1), f - fl) {
      if (f == fl + fr + 1 && val == dp[p1][fl][l][1] + dp[p2][fr][1][r] + r * (bd[wh] - S.r)) {
        PII lewo = Restore(p1, fl, l, 1);
        PII prawo = Restore(p2, fr, 1, r);
        if (putr) {
          intvs.PB({prawo.nd, H.r});
        }
        if (putl) {
          intvs.PB({H.l, lewo.st});
        }
        intvs.PB({lewo.nd, prawo.st});
        return {lewo.st, prawo.nd};
      } else if (f == fl + fr && val ==  dp[p1][fl][l][0] + dp[p2][fr][0][r] + r * (bd[wh] - S.r)) {
        PII lewo = Restore(p1, fl, l, 0);
        PII prawo = Restore(p2, fr, 0, r);
        if (putr) {
          intvs.PB({prawo.nd, H.r});
        }
        if (putl) {
          intvs.PB({H.l, lewo.st});
        }
        return {lewo.st, prawo.nd};
      }
    }
  }
  //return {-1, -1};
  //debug(wh, v, f, l, r, dp[wh][f][l][r], ch[v]);
  //debug(sz[v], p1, p2);
  assert(false);
}
    
  

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    int l, r;
    cin>>l>>r;
    seg.PB({l, r});
  }
  ch.resize(n + 1);
  VI par(n + 1);
  REP (i, n) {
    int wh = n;
    int shortest_len = 0;
    REP (j, n) {
      if (i == j) { continue; }
      int len = seg[j].r - seg[j].l;
      if (seg[j].l <= seg[i].l && seg[i].r <= seg[j].r && (wh == n || shortest_len > len)) {
        wh = j;
        shortest_len = len;
      }
    }
    par[i] = wh;
    ch[wh].PB(i);
  }
  int res = 0;
  for (auto root : ch[n]) {
    Dfs(root);
    //if (seg[0].l != 650133152) {
      Restore(last_ind[root], 0, 0, 0);
    //}
    //debug(dp[last_ind[root]][0][0][0]);
    res += dp[last_ind[root]][0][0][0];
  }
  cout<<res<<endl;
  
  //debug(intvs);
  assert(SZ(intvs) <= n);
  int sum_len = 0;
  for (auto intv : intvs) {
    sum_len += intv.nd - intv.st;
    int wh = n;
    int shortest_len = 0;
    REP (i, n) {
      int len = seg[i].r - seg[i].l;
      if (R[i]) { continue; }
      if (seg[i].l <= intv.st && intv.nd <= seg[i].r && (wh == n || shortest_len > len)) {
        wh = i;
        shortest_len = len;
      }
    }
    L[wh] = intv.st;
    R[wh] = intv.nd;
    //assert(wh != n);
  }
  assert(sum_len == res);
  VI ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int a, int b) {
    return seg[a].r - seg[a].l > seg[b].r - seg[b].l;
  });
  for (auto x : ord) {
    if (R[x]) { continue; }
    REP (i, n) {
      if (L[i] < seg[x].l && R[i] >= seg[x].l + 1) {
        L[x] = seg[x].l;
        R[x] = R[i];
        R[i] = L[x];
        break;
      }
    }
  }
  REP (i, n) {
    cout<<L[i]<<" "<<R[i]<<"\n";
  }
//   debug(last_ind[3]);
//   debug(dp[last_ind[3]][0][0][0]);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}