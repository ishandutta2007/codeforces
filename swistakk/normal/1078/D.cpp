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
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
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

int M;
int n;
vector<int> Buduj(vector<int>& V, int typ) {
  M = 1;
  while (M <= SZ(V) + 2) {
    M *= 2;
  }
  vector<int> res(2 * M);
  RE (i, 3 * n) {
    res[i + M - 1] = V[i];
  }
  debug(res, V);
  FORD (i, M - 1, 1) {
    if (typ) {
      res[i] = max(res[2 * i], res[2 * i + 1]);
    } else {
      res[i] = min(res[2 * i], res[2 * i + 1]);
    }
  }
  debug(res);
  return res;
}
int Read(vector<int>& drz, int l, int r, int typ) {
  l += M - 1;
  r += M - 1;
  int res = min(drz[l], drz[r]);
  if (typ) {
    res = max(drz[l], drz[r]);
  }
  while (l / 2 != r / 2) {
    if (l % 2 == 0) {
      if (typ) {
        maxi(res, drz[l + 1]);
      } else {
        mini(res, drz[l + 1]);
      }
    }
    if (r % 2 == 1) {
      if (typ) {
        maxi(res, drz[r - 1]);
      } else {
        mini(res, drz[r - 1]);
      }
    }
    l /= 2;
    r /= 2;
  }
  return res;
}
      
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  if (n == 1) {
    cout<<"0\n";
    return 0;
  }
  vector<int> resp(3 * n + 2);
  int N = 3 * n + 2;
  RE (i, n) {
    cin>>resp[i];
    resp[i + n] = resp[i];
    resp[i + 2 * n] = resp[i];
  }
//   vector<int> kl(n + 2, 1);
//   vector<int> kp(n + 2, n);
//   vector<int> faj(n + 2, n);
//   vector<int> aktc(n + 2);
//   vector<int> left(n + 2);
//   vector<int> right(n + 2);

  vector<VI> left(20, vector<int>(N));
  vector<VI> right(20, vector<int>(N));
  vector<VI> drzL(20);
  vector<VI> drzR(20);
  RE (i, 3 * n) {
    left[0][i] = max(1, i - resp[i]);
    right[0][i] = min(3 * n, i + resp[i]);
  }
  drzL[0] = Buduj(left[0], 0);
  drzR[0] = Buduj(right[0], 1);
  RE (L, 19) {
    RE (i, 3 * n) {
      debug(i, left[L - 1][i], right[L - 1][i]);
      left[L][i] = Read(drzL[L - 1], left[L - 1][i], right[L - 1][i], 0);
      right[L][i] = Read(drzR[L - 1], left[L - 1][i], right[L - 1][i], 1);
    }
    drzL[L] = Buduj(left[L], 0);
    drzR[L] = Buduj(right[L], 1);
  }
  debug(left[0]);
  debug(left[1]);
  debug(left[2]);
  debug(right[0]);
  debug(right[1]);
  debug(right[2]);
  
  FOR (i, n + 1, 2 * n) {
    int L = i, R = i;
    int cur_log = 17;
    int res = 0;
    while (cur_log >= 0) {
      int nL = Read(drzL[cur_log], L, R, 0);
      int nR = Read(drzR[cur_log], L, R, 1);
      if (i == 14) {
        debug(cur_log, res, L, R, nL, nR);
      }
      if (nR - nL >= n - 1) {
      } else {
        L = nL;
        R = nR;
        res += (1 << cur_log);
      }
      cur_log--;
    }
    cout<<res + 1<<" ";
  }
  cout<<endl;
  

  /*REP (tr, 20) {
    RE (i, n) {
      aktc[i] = (kl[i] + kp[i]) / 2;
    }
    vector<PII> stos; // pozycja, zasieg
    RE (i, 2 * n) {
      while (SZ(stos) >= 2 && i - resp[i] <= stos[SZ(stos) - 2].st) {//stos.back().st - stos.back().nd >= 
        stos.pop_back();
      }
      stos.PB({i, resp[i]});
      if (i > n) {
        if (kl[i - n] > kp[i - n]) { continue; }
        if (SZ(stos) < aktc[i - n]) {
          left[i - n] = n + 1;
        } else {
          debug(SZ(stos), SZ(aktc), i - n, aktc[i - n] - 1);
          left[i - n] = i - stos[aktc[i - n] - 1].st + stos[aktc[i - n] - 1].nd;
        }
      }
    }
    stos.clear();
    FORD (i, 2 * n, 1) {
      while (SZ(stos) >= 2 && i + resp[i] >= stos[SZ(stos) - 2].st) {//stos.back().st - stos.back().nd >= 
        stos.pop_back();
      }
      stos.PB({i, resp[i]});
      
      if (i <= n) {
        
        if (kl[i] > kp[i]) { continue; }
        if (SZ(stos) < aktc[i]) {
          right[i] = n + 1;
        } else {
          right[i] = -i + stos[aktc[i] - 1].st + stos[aktc[i] - 1].nd;
        }
      }
    }
    RE (i, n) {
      if (aktc[i] == 1) { debug(i, left[i], right[i]); }
      if (kl[i] > kp[i]) { continue; }
      if (left[i] + right[i] >= n - 1) {
        faj[i] = aktc[i];
        kp[i] = aktc[i] - 1;
      } else {
        kl[i] = aktc[i] + 1;
      }
    }
  }
  RE (i, n) {
    cout<<faj[i]<<" ";
  }
  cout<<endl;*/
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}