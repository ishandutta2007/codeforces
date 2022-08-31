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

VPII que[256][256];
VI que1[256];
struct Dwu {
  Dwu(int n) {
    l.resize(n + 2);
    r.resize(n + 2);
    alive.resize(n + 2);
    RE (i, n + 1) {
      l[i] = i - 1;
    }
    REP (i, n + 1) {
      r[i] = i + 1;
    }
    RE (i, n) {
      alive[i] = 1;
    }
  }
  VI l, r, alive;
  int Rem(int a) {
    assert(alive[a]);
    int R = r[a];
    int L = l[a];
    r[L] = R;
    l[R] = L;
    alive[a] = 0;
    return R;
  }
};

int Magic(int n) {
  return n - (n & (n - 1));
}

struct Sol {
  void Test() {
    FOR (i, 'a', 'z') {
      que1[i].clear();
      FOR (j, 'a', 'z') {
        que[i][j].clear();
      }
    }
    string s;
    cin>>s;
    int n = SZ(s);
    
    VI fenw(n + 2);
    auto Up = [&](int x) {
      while (x < n + 2) {
        fenw[x]++;
        x += Magic(x);
      }
    };
    auto Left = [&](int x) {
      int sum = 0;
      while (x) {
        sum += fenw[x];
        x -= Magic(x);
      }
      return sum;
    };
    Dwu all(n + 1);
    
    vector<pair<char, int>> eqs;
    REP (i, n - 1) {
      if (s[i] == s[i + 1]) {
        eqs.PB({s[i], i + 1});
      }
    }
    Dwu cons(SZ(eqs) + 2);
    vector<int> cnt('z' + 2);
    for (auto eq : eqs) {
      cnt[eq.st]++;
    }
    eqs.insert(eqs.begin(), pair<char, int>('$', -1));
    auto Put = [&](int a, int b) {
      assert(a < b);
      int la = eqs[a].st;
      int lb = eqs[b].st;
      que[la][lb].PB({a, b});
      que[lb][la].PB({a, b});
      assert(cons.alive[a]);
      assert(cons.alive[b]);
      assert(cons.r[a] == b);
    };
    RE (i, SZ(eqs) - 2) {
      Put(i, i + 1);
    }
    VPII ans;
    while (1) {
      int ma = 0;
      int wh_ma = 0;
      FOR (i, 'a', 'z') {
        if (cnt[i]) {
          debug((char)i, cnt[i]);
        }
        if (cnt[i] > ma) {
          wh_ma = i;
          ma = cnt[i];
        }
      }
      if (ma == 0) {
        break;
      }
      debug((char)wh_ma, ma);
      int any = 0;
      FOR (oth, 'a', 'z') {
        if (oth == wh_ma) { continue; } 
        while (!que[wh_ma][oth].empty()) {
          auto p = que[wh_ma][oth].back();
          if (cons.alive[p.st] && cons.alive[p.nd]) {
            debug(p.st, p.nd);
            any = 1;
            int l = eqs[min(p.st, p.nd)].nd + 1;
            int r = eqs[max(p.st, p.nd)].nd;
            ans.PB({l - Left(l), r - Left(r)});
            int cur = l;
            while (cur <= r) {
              Up(cur);
              cur = all.Rem(cur);
            }
            cnt[wh_ma]--;
            cnt[oth]--;
            cons.Rem(p.st);
            int R = cons.Rem(p.nd);
            int L = cons.l[R];
            debug(L, R);
            if (L >= 1 && R <= SZ(eqs) - 1) {
              Put(L, R);
            }
            goto End;
          } else {
            que[wh_ma][oth].pop_back();
          }
        }
      }   
      End: ;
      if (any) { continue; }
      RE (i, SZ(eqs) - 1) {
        if (cons.alive[i]) {
          int l = eqs[i].nd + 1;
          ans.PB({l - Left(l), l - Left(l)});
          cons.Rem(i);
          Up(l);
        }
      }
      break;
    }
    ans.PB({1, n - Left(n)});
    cout<<SZ(ans)<<"\n";
    for (auto x : ans) {
      cout<<x.st<<" "<<x.nd<<"\n";
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