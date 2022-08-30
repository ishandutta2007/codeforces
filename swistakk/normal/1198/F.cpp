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

const int N = 1e6 + 5;
VI who_small[N];
//map<int, VI> who_big;
int a[N];
vector<int> lp;
int sieve[N];
const int S = 30;
int last[N];
int parity[N];
VI slo[N];

int cand[N];
void Dfs(int v, int nr) {
  last[v] = nr;
  for (auto nei : slo[v]) {
    if (last[nei] == nr) { continue; }
    parity[nei] = parity[v] ^ 1;
    cand[nei] = cand[v] ^ 3;
    Dfs(nei, nr);
  }
}
void Exit() {
  cout<<"NO\n";
  exit(0);
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  for (int i = 2; i < N; i++) {
    if (sieve[i] == 0) {
      lp.PB(i);
      for (int j = 1; i * j < N; j++) {
        sieve[i * j] = 1;
      }
    }
  }
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>a[i];
    int tmp = a[i];
    VI factors;
    for (auto p : lp) {
      if (p > 1000) { break; }
      if (tmp % p == 0) {
        factors.PB(p);
        while (tmp % p == 0) {
          tmp /= p;
        }
        
      }
      if (tmp == 1) { break; }
      if (p * p > tmp) {
        factors.PB(tmp);
        break;
      }
    }
    for (auto fact : factors) {
      if (fact < N) {
        who_small[fact].PB(i);
      }/* else {
        who_big[fact].PB(i);
      }*/
    }
  }
  vector<VI> small_complements;
  for (auto p : lp) {
    int complement_sz = n - SZ(who_small[p]);
    if (complement_sz <= 1) {
      Exit();
    }
    if (complement_sz <= S) {
      VI comple;
      for (auto x : who_small[p]) {
        last[x] = p;
      }
      RE (i, n) {
        if (last[i] != p) {
          comple.PB(i);
        }
      }
//       if (complement_sz == 2) {
//         slo[comple[0]].PB(comple[1]);
//         slo[comple[1]].PB(comple[0]);
//       } else {
        small_complements.PB(comple);
      //}
    }
  }
  sort(ALL(small_complements), [&](VI L, VI R) { return SZ(L) < SZ(R); });
  int cnt = 1;
  RE (i, n) {
    last[i] = 0;
  }
  while (1) {
    int any_change = 0;
    vector<VI> n_compls;
    // zawiera dwoch ludzi z dwoch stron jednej skladowej -> wyrzucamy
    // zawiera ludzi z jednej skladowej -> Exit()
    // zawiera ludzi z dwoch roznych skladowych -> dodajemy krawedz i wyrzucamy
    // zawiera ludzi z wiecej niz dwoch skladowych -> zostawiamy
    
    for (auto comple : small_complements) {
      int first_cnt = cnt;
      vector<int> zioms;
      int done = 0;
      for (auto v : comple) {
        if (last[v] >= first_cnt) {
          if (parity[v]) {
            done = 1;
            break;
          }
          continue;
        }
        zioms.PB(v);
        if (SZ(zioms) >= 3) {
          break;
        }
        parity[v] = 0;
        Dfs(v, cnt);
        cnt++;
      }
      if (done) {
      } else if (SZ(zioms) >= 3){
        n_compls.PB(comple);
      } else if (SZ(zioms) == 1) {
        Exit();
      } else {
        debug(zioms);
        if (SZ(zioms) != 2) {
          debug(comple, zioms);
        }
        assert(SZ(zioms) == 2);
        slo[zioms[0]].PB(zioms[1]);
        slo[zioms[1]].PB(zioms[0]);
      }
    }
    if (small_complements == n_compls) { break; }
    small_complements = n_compls;
  }
  
  RE (i, n) {
    if (!slo[i].empty()) {
      debug(i, slo[i]);
    }
  }
  while (1.0 * clock() / CLOCKS_PER_SEC < 0.4) {
    int first_cnt = cnt;
    RE (i, n) {
      if (last[i] >= first_cnt) { continue; }
      cand[i] = 1 + rand() % 2;
      Dfs(i, cnt);
      cnt++;
    }
    int g1 = 0, g2 = 0;
    RE (i, n) {
      if (cand[i] == 1) {
        g1 = __gcd(g1, a[i]);
      } else {
        g2 = __gcd(g2, a[i]);
      }
    }
    if (g1 == 1 && g2 == 1) {
      cout<<"YES\n";
      RE (i, n) {
        cout<<cand[i]<<" ";
      }
      cout<<endl;
      return 0;
    }
  }
  Exit();
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}