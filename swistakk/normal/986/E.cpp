#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define LL long long
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

struct LCA {
  LCA(const vector<vector<int> >& their_slo, int root = 1) {
    M = 1;
    while (M <= 2 * (int)their_slo.size()) {
      M *= 2;
    }
    my_slo.resize(M);
    REP (i, (int)their_slo.size()) {
      for (auto nei : their_slo[i]) {
        my_slo[i].PB(nei);
      }
    }
    drz.resize(2 * M + 5);
    pre.resize(M);
    inv.resize(M);
    vis.resize(M);
    ind.resize(M);
    dep.resize(M);
    ojc.resize(M);
    d=1;
    akt=1;
    dfs(root);
    for(int i=M-1; i>=1; i--)
    {
        drz[i]=min(drz[2*i], drz[2*i+1]);
    }
  }
  int M;
  vector<int> drz;
  vector<int> pre;
  vector<int> inv;
  vector<int> vis;
  vector<int> ind;
  vector<int> dep;
  vector<vector<int> > my_slo;
  int d;
  int akt;
  
  int Lca(int a, int b) // pobiera a i b, a zwraca ich lca (przy ukorzenieniu w jedynce (ale to mozna zmienic zapuszczajac skad inad dfsa) )
  {
      a=pre[a];
      b=pre[b];
      int w;
      w=czyt(min(ind[a], ind[b]), max(ind[a], ind[b]) );
      return inv[w];
  }
  
  int Dis(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[Lca(a, b)];
  }
  VI ojc;
private:
  int czyt(int a, int b)
  {
      a+=M-1;
      b+=M-1;
      int mini=M;
      mini=min(mini, drz[a]);
      mini=min(mini, drz[b]);
      while(a/2 != b/2)
      {
          if(a%2==0)
          {
              mini=min(mini, drz[a+1]);
          }
          if(b%2==1)
          {
              mini=min(mini, drz[b-1]);
          }
          a/=2;
          b/=2;
      }
      return mini;
  }
  void dfs(int v)
  {
    vis[v]=1;
    pre[v]=d;
    inv[d]=v;
    d++;
    drz[akt+M-1]=pre[v];
    ind[pre[v]]=akt;
    akt++;
    for (int nei : my_slo[v]) {
      if (vis[nei]) {
        continue;
      }
      dep[nei] = dep[v] + 1;
      ojc[nei] = v;
      dfs(nei);
      drz[akt+M-1]=pre[v];
      ind[pre[v]]=akt;
      akt++;
    }
  }
}; 

struct FastNewton {
  long long P;
  long long range;
  vector<long long> inv;
  vector<long long> fact;
  vector<long long> fact_inv;
  vector<long long> v_p;
 
 public:
  FastNewton (long long _P, long long _range = 0) {
    init(_P, _range);
  }
  
  // Initialize structures to support computing n choose k mod _P, where n <= range
  void init(long long _P, long long _range = -1) {
    P = _P;
    if (_range == -1) {
      range = P;
    } else {
      range = _range;
    }
    inv.resize(range + 5);
    fact.resize(range + 5);
    fact_inv.resize(range + 5);
    v_p.resize(range + 5);
    fact[0] = 1;
    fact_inv[0] = 1;
    inv[0] = -1;
    inv[1] = 1;
    for (int i = 2; i < min(range, P); i++) {
      inv[i] = P - (P / i) * inv[P % i] % P;
    }
    for (int i = 1; i <= range; i++) {
      ll tmp = i;
      while (tmp % P == 0) {
        tmp /= P;
      }
      fact[i] = tmp * fact[i - 1] % P;
      fact_inv[i] = fact_inv[i - 1] * inv[tmp % P] % P;
    }
    for (int i = 1; i <= range; i++) {
      v_p[i] = i / P + v_p[i / P];
    }
  }
  
  long long get_inv(long long a) const {
    if (a % P == 0) {
      cout<<"ERROR: 0 has not got its inverse\n";
      return -1;
    }
    return inv[a % P];
  }
  
  // Computes n! mod P
  long long get_normal_fact(long long n) const {
    if (n >= P) {
      return 0;
    }
    return fact[n];
  }
  
  // Computes n!/p^(v_p(n!)) mod P
  long long get_better_fact(long long n) const {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return fact[n];
  }
  
  // Computes largest k such that p^k | n!
  long long get_v_p(long long n) const {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return v_p[n];
  }
  
  // Computes (n choose k) mod p
  long long choose(long long n, long long k) const {
    if (k < 0 || k > n) {
      return 0;
    }
    if (v_p[n] == v_p[k] + v_p[n - k]) {
      return fact[n] * fact_inv[k] % P * fact_inv[n - k] % P;
    } else {
      return 0;
    }
  }
  
};

const int P = 1e9 + 7;
const int N = 1e7 + 5;
const int M = 1e5 + 5;
FastNewton newt(P, N);
int spow(int a, int b) {
  LL r = 1;
  while (b) {
    if (b % 2) {
      r = 1ll * r * a % P;
    }
    a = 1ll * a * a % P;
    b /= 2;
  }
  return r;
}

int sito[N];
//int cnt[N];
VI wh_q;
vector<int> cnt[N];
VPII GetRoz(int tmp) {
  VPII lol;
  while (tmp > 1) {
    int p = sito[tmp];
    int ex = 0;
    while (tmp % p == 0) {
      tmp /= p;
      ex++;
    }
    lol.PB({p, ex});
  }
  return lol;
}
VPII roz_v[M];
VPII roz_q[M];
int res[M];
VI qs[M];
int vis[M];
VVI slo;
void Dfs(int v) {
  vis[v] = 1;
  for (auto parka : roz_v[v]) {
    int p = parka.st;
    int ex = parka.nd;
    if (SZ(cnt[p]) <= ex) {
      cnt[p].resize(ex + 2);
    }
    cnt[p][ex]++;
  }
  for (auto q : qs[v]) {
    int ab = abs(q);
    for (auto parka : roz_q[ab]) {
      int p = parka.st;
      LL ex = 0;
      REP (i, SZ(cnt[p])) {
        ex += 1ll * cnt[p][i] * min(i, parka.nd);
      }
      if (v == 2 && p == 3) {
        debug(cnt[p]);
      }
      debug(v, q, p, ex);
      if (q > 0) {
        res[ab] = (1ll * res[ab] * spow(p, ex)) % P;
      } else {
        res[ab] = (1ll * res[ab] * spow(newt.inv[p], ex)) % P;
      }
    }
  }
  for (auto nei : slo[v]) {
    if (vis[nei]) { continue; }
    Dfs(nei);
  }
  for (auto parka : roz_v[v]) {
    int p = parka.st;
    int ex = parka.nd;
    if (SZ(cnt[p]) <= ex) {
      cnt[p].resize(ex + 2);
    }
    cnt[p][ex]--;
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  
  FOR (i, 2, N - 1) {
    if (sito[i] == 0) {
      RE (j, (N - 1) / i) {
        sito[i * j] = i;
      }
    }
  }
  
  slo.resize(n + 1);
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  RE (i, n) {
    int val;
    cin>>val;
    roz_v[i] = GetRoz(val);
  }
  LCA lca(slo);
  int q;
  cin>>q;
  RE (i, q) {
    res[i] = 1;
    int u, v, x;
    cin>>u>>v>>x;
    roz_q[i] = GetRoz(x);
    int l = lca.Lca(u, v);
    qs[lca.ojc[l]].PB(-i);
    qs[l].PB(-i);
    qs[u].PB(i);
    qs[v].PB(i);
  }
  Dfs(1);
  RE (i, q) {
    cout<<res[i]<<"\n";
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}