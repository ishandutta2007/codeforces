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

const int N = 111;
int d_tr[N], d_str[N];
int sure[N];
int init[N];
int fin[N];
int n;
int val[N];
int cur[N];
int GetTr() {
#ifdef LOCAL
  int res = 0;
  RE (i, n) {
    res += (cur[i] * (cur[i] - 1) * (cur[i] - 2)) / 6;
  }
  return res;
#else
  int res;
  cin>>res;
  return res;
#endif
}
int GetStr() {
  int res = 0;
#ifdef LOCAL
  RE (i, n - 2) {
    res += cur[i] * (cur[i + 1] * cur[i + 2]);
  }
#else
  cin>>res;
#endif
  return res;
}
int tr, str;
int pref[N][N];
VI asks;
bool Bt(int pos) {
  
  if (pos == n + 1) {
    RE (i, n) {
      fin[i] = init[i];
    }
    REP (i, n) {
      fin[asks[i]]++;
    }
    int res = 0;
    RE (i, n) {
      res += (fin[i] * (fin[i] - 1) * (fin[i] - 2)) / 6;
    }
    if (res != tr) { return false; }
    res = 0;
    RE (i, n - 2) {
      res += fin[i] * fin[i + 1] * fin[i + 2];
    }
    if (res != str) { return false; }
    return true;
  }
  VI poss;
  if (pref[pos][n - 1] == 0) {
    REP (i, n + 1) {
      poss.PB(i);
    }
  } else if (sure[pos]) {
    poss.PB(sure[pos]);
    REP (i, n) {
      if (asks[i] == pos) {
        poss.back()--;
      }
    }
  } else {
    poss.PB(0);
    poss.PB(1);
  }
  //bool any = false;
  for (auto cand : poss) {
    init[pos] = cand;
    int fail = 0;
    REP (i, n) {
      int a = asks[i];
      if (a <= pos - 2 || pos == n) { // wszystko co potrzebne to juz mam ustalone
        int need = 0;
        if (a >= 3) {
          need += (init[a - 2] + pref[a - 2][i]) * (init[a - 1] + pref[a - 1][i]);
        }
        if (a >= 2) {
          need += (init[a - 1] + pref[a - 1][i]) * (init[a + 1] + pref[a + 1][i]);
        }
        need += (init[a + 1] + pref[a + 1][i]) * (init[a + 2] + pref[a + 2][i]);
        if (need != d_str[i + 1]) { fail = true; }
      }
    }   
//     debug(pos);
//     RE (i, pos) {
//       cerr<<fin[i]<<" ";
//     }
//     cerr<<endl;
//     bool fail = false;
//     if (pos >= 3) {
//       int need = (fin[pos] - 1) * (fin[pos - 1] - 1) /** fin[pos - 2]*/;
//       if (pos >= 4) {
//         need += (fin[pos - 1] - 1) /** fin[pos - 2]*/ * fin[pos - 3];
//       }
//       if (pos >= 5) {
//         need += /*fin[pos - 2] **/ fin[pos - 3] * fin[pos - 4];
//       }
//       debug(pos, need, d_str[pos - 2]);
//       if (need != d_str[pos - 2]) {
//         fail = true;
//       }
//     }
//     if (pos == n) {
//       if (d_str[n] != fin[n - 4] * fin[n - 3] + fin[n - 3] * fin[n - 1] + fin[n - 1] * fin[n]) { fail = true;}
//       if (d_str[n - 1] != (fin[pos] - 1) * fin[pos - 2] + fin[pos - 2] * fin[pos - 3]) { fail = true; }
//     }
    if (fail) { continue; }
    if (Bt(pos + 1)) {
      return true;
    }
  }
  return false;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
#ifdef LOCAL
  RE (i, n) {
    cin>>cur[i];
    cerr<<cur[i]<<" ";
  }
  cerr<<endl;
#endif
  //int tr, str;
  tr = GetTr();
  str = GetStr();
  
  asks.PB(n);
  FOR (i, 2, n) {
    asks.PB(i);
  }
  if (n == 4) {
    asks = {4, 2, 3, 4};
  }
  pref[asks[0]][0] = 1;
  RE (i, n - 1) {
    RE (j, n) {
      pref[j][i] = pref[j][i - 1];
    }
    pref[asks[i]][i]++;
  }
  RE (i, n) {
    debug(i, pref[i][n - 1]);
  }
  
  RE (i, n) {
//     int ziom = i;
//     if (ziom == n) {
//       ziom = n - 2;
//     } /*else if (ziom == n - 1) {
//       ziom = n;
//     }*/
    cout<<"+ "<<asks[i - 1]<<endl;
    cur[asks[i - 1]]++;
    int ntr, nstr;
    ntr = GetTr();
    nstr = GetStr();
    d_tr[i] = ntr - tr;
    d_str[i] = nstr - str;
    if (d_tr[i] > 0) {
      debug(d_tr[i]);
      RE (j, n + 5) {
        if ((j - 1) * (j - 2) == 2 * d_tr[i]) {
          sure[asks[i - 1]] = j;
          //init[i] = j - 1;
          break;
        }
      }
      assert(sure[asks[i - 1]]);
    }
    tr = ntr;
    str = nstr;
  }
  RE (i, n) {
    debug(i, sure[i]);
  }
  Bt(1);
  cout<<"! ";
  RE (i, n) {
    cout<<init[i]<<" ";
  }
  cout<<endl;
#ifdef LOCAL
  RE (i, n) {
    assert(init[i] + pref[i][n - 1] == cur[i]);
  }
#endif
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}