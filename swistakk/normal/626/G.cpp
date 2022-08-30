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

const int N = 2e5 + 5;
int p[N];
const LD kEps = 1e-14;
typedef pair<LD, int> Z;
struct CmpGr {
  bool operator() (const Z& lhs, const Z& rhs) const {
    if (lhs.st != rhs.st /*abs(lhs.st - rhs.st) > kEps*/) {
      return lhs.st > rhs.st;
    }
    return lhs.nd < rhs.nd;
  }
};
struct CmpLess {
  bool operator() (const Z& lhs, const Z& rhs) const {
    if (lhs.st != rhs.st /*abs(lhs.st - rhs.st) > kEps*/) {
      return lhs.st < rhs.st;
    }
    return lhs.nd < rhs.nd;
  }
};
LD Diff(int k, int l) {
  return 1. * k / (l + k) - 1. * (k - 1) / (l + k - 1);
}
int l[N];
int cur[N];
LD ValNew(int i) {
  return p[i] * Diff(cur[i] + 1, l[i]);
}
LD ValTop(int i) {
  if (cur[i] == 0) { return 0; }
  return p[i] * Diff(cur[i], l[i]);
}
set<pair<LD, int>, CmpGr> active_raff;
set<pair<LD, int>, CmpLess> tops;
int to_use;
LD res;
void AddMy(int i) {
  cerr<<"AddMy "<<i<<endl;
  tops.erase({ValTop(i), i});
  active_raff.erase({ValNew(i), i});
  assert(cur[i] < l[i]);
  cur[i]++;
  to_use--;
  res += ValTop(i);
  tops.insert({ValTop(i), i});
  if (cur[i] < l[i]) {
    active_raff.insert({ValNew(i), i});
  }
}
void RemoveMy(int i) {
  cerr<<"RemoveMy "<<i<<endl;
  tops.erase({ValTop(i), i});
  active_raff.erase({ValNew(i), i});
  res -= ValTop(i);
  cur[i]--;
  to_use++;
  if (cur[i]) {
    tops.insert({ValTop(i), i});
  }
  if (cur[i] < l[i]) {
    active_raff.insert({ValNew(i), i});
  }
}
void RemoveTheir(int i) {
  if (cur[i]) {
    RemoveMy(i);
  }
  res += p[i] * (1. * cur[i] / (l[i] + cur[i] - 1) - 1. * cur[i] / (l[i] + cur[i]));
  tops.erase({ValTop(i), i});
  active_raff.erase({ValNew(i), i});
  l[i]--;
  if (cur[i]) {
    tops.insert({ValTop(i), i});
  }
  if (cur[i] < l[i]) {
    active_raff.insert({ValNew(i), i});
  }
  REP (tr, 2) {
    if (!tops.empty()) {
      auto pa = *tops.begin();
      RemoveMy(pa.nd);
    }
  }
}
void AddTheir(int i) {
  if (cur[i]) {
    RemoveMy(i);
  }
  debugv(tops);
  tops.erase({ValTop(i), i});
  res -= p[i] * (1. * cur[i] / (l[i] + cur[i]) - 1. * cur[i] / (l[i] + cur[i] + 1));
  active_raff.erase({ValNew(i), i});
  l[i]++;
  if (cur[i]) {
    tops.insert({ValTop(i), i});
  }
  if (cur[i] < l[i]) {
    active_raff.insert({ValNew(i), i});
  }
  if (cur[i]) {
    RemoveMy(i);
  }
  REP (tr, 2) {
    if (!tops.empty()) {
      auto pa = *tops.begin();
      RemoveMy(pa.nd);
    }
  }
}
bool TryAdd() {
  if (to_use == 0 || active_raff.empty()) { return false; }
  auto pa = *active_raff.begin();
  AddMy(pa.nd);
  return true;
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  
//   active_raff.insert({0, 1});
//   active_raff.erase({1e-13, 1});
  debug(SZ(active_raff));
  int n, t, q;
  cin>>n>>t>>q;
  
  RE (i, n) {
    cin>>p[i];
  }
  RE (i, n) {
    cin>>l[i];
    active_raff.insert({p[i] * Diff(1, l[i]), i});
  }
  res = 0;
  to_use = t;
  while (TryAdd());
  RE (_, q) {
    int typ, r;
    cin>>typ>>r;
    if (typ == 2) {
      RemoveTheir(r);
    } else {
      AddTheir(r);
    }
    while (TryAdd());
    cout<<res<<"\n";
  }
        
  
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}