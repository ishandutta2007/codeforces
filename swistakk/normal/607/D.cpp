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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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



struct Node {
  int sum, mult;
};

const int N = 2e5 + 5;
const int M = 1 << 18;
Node tree[2 * M + 5];
const int P = 1e9 + 7;
void Mu(int& a, int b) {
  a = a * b % P;
}
// wartosc wierzcholka = tree[v].sum * (mult na drodze do korzenia bez v)
// tree[v].sum = suma orig_lisci wymnozonych przez multy do v (z liscmi)
int SumRec(int l, int r, int bl, int br, int v) {
  if (l <= bl && br <= r) {
    return tree[v].sum;
  }
  if (l > br || r < bl) {
    return 0;
  }
  int m = (bl + br) / 2;
  int sum = SumRec(l, r, bl, m, 2 * v);
  sum += SumRec(l, r, m + 1, br, 2 * v + 1);
  sum = sum * tree[v].mult % P;
  return sum;
}
int Sum(int a, int b) {
  return SumRec(a, b, 1, M, 1);
}
void MultRec(int l, int r, int bl, int br, int v, int val) {
  if (l <= bl && br <= r) {
    Mu(tree[v].mult, val);
    Mu(tree[v].sum, val);
    return;
  }
  if (l > br || r < bl) {
    return;
  }
  int m = (bl + br) / 2;
  MultRec(l, r, bl, m, 2 * v, val);
  MultRec(l, r, m + 1, br, 2 * v + 1, val);
  tree[v].sum = (tree[2 * v].sum + tree[2 * v + 1].sum) * tree[v].mult % P;
}
void Mult(int l, int r, int val) {
  MultRec(l, r, 1, M, 1, val);
}
void Add(int v, int val) {
  v += M - 1;
  int prod = 1;
  while (v) {
    prod = prod * tree[v].mult % P;
    tree[v].sum = (tree[v].sum + prod * val) % P;
    v /= 2;
  }
}
int d;
int mult[2 * M + 5];
void MultEZ(int a, int b, int v) {
  a += M;
  b += M;
  mult[a] = mult[a] * v % P;
  if (a != b) {
    mult[b] = mult[b] * v % P;
  }
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      mult[a + 1] = mult[a + 1] * v % P;
    }
    if (b % 2 == 1) {
      mult[b - 1] = mult[b - 1] * v % P;
    }
    a /= 2;
    b /= 2;
  }
}
int GetMultEZ(int v) {
  v += M;
  int prod = 1;
  while (v) {
    prod = prod * mult[v] % P;
    v /= 2;
  }
  return prod;
}
  
int pre[N];
int sz[N];
VI slo[N];
void Dfs(int v) {
  d++;
  sz[v] = 1;
  pre[v] = d;
  for (auto nei : slo[v]) {
    Dfs(nei);
    sz[v] += sz[nei];
  }
}
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2 == 1) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int Inv(int a) {
  return spow(a, P - 2);
}
int c[N], p[N], v[N];
int ch[N];
int cur_sz[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  
  
  int q, v1;
  cin>>v1>>q;
  int node_cnt = 1;
  RE (i, q) {
    cin>>c[i];
    if (c[i] == 2) {
      cin>>v[i];
    } else {
      cin>>p[i]>>v[i];
      node_cnt++;
      ch[i] = node_cnt;
      slo[p[i]].PB(node_cnt);
    }
  }
  FORD (i, 2 * M, 1) {
    mult[i] = 1;
    tree[i].mult = 1;
  }
  Dfs(1);
  RE (i, node_cnt) {
    debug(pre[i], sz[i]);
  }
  cur_sz[1] = 1;
  Add(1, v1);
  RE (i, q) {
    debug(c[i], p[i], v[i]);
    if (c[i] == 2) {
      debug(GetMultEZ(pre[v[i]]));
      cout<<Sum(pre[v[i]], pre[v[i]] + sz[v[i]] - 1) * Inv(GetMultEZ(pre[v[i]])) % P * cur_sz[v[i]] % P<<"\n";
    } else {
      cur_sz[p[i]]++;
      cur_sz[ch[i]] = 1;
      Mult(pre[p[i]], pre[p[i]] + sz[p[i]] - 1, cur_sz[p[i]] * Inv(cur_sz[p[i]] - 1) % P);
      Add(pre[ch[i]], v[i]);
      MultEZ(pre[p[i]], pre[p[i]] + sz[p[i]] - 1, cur_sz[p[i]] * Inv(cur_sz[p[i]] - 1) % P);
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}