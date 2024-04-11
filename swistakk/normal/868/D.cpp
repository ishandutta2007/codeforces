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

string B(string s) {
  return s.substr(0, 12);
}
string E(string s) {
  return s.substr(max(0ll, SZ(s) - 12), 12);
}
void Fill(VVI& masks, string s) {
  REP (i, SZ(s)) {
    REP (j, SZ(s)) {
      int len = j - i + 1;
      if (len <= 0 || len > 12) { continue; }
      string sub = s.substr(i, len);
      int acc = 0;
      REP (pos, len) {
        if (sub[pos] == '1') {
          acc += 1 << pos;
        }
      }
      masks[len][acc] = 1;
    }
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
  vector<string> begs(222);
  vector<string> ens(222);
  vector<vector<VI>> masks(222, vector<VI>(13, VI(1 << 12)));
  RE (i, n) {
    string s;
    cin>>s;
    begs[i] = B(s);
    ens[i] = E(s);
    Fill(masks[i], s);
    REP (j, 4) {
      cerr<<masks[i][2][j];
    }
    cerr<<endl;
  }
  int m;
  cin>>m;
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    debug(a, b);
    masks[n + i] = masks[a];
    RE (len, 12) {
      REP (mask, 1 << 12) {
        if (masks[b][len][mask]) {
          masks[n + i][len][mask] = 1;
        }
      }
    }
    ens[n + i] = E(ens[a] + ens[b]);
    begs[n + i] = B(begs[a] + begs[b]);
    debug(ens[n + i], begs[n + i]);
    Fill(masks[n + i], ens[a] + begs[b]);
    bool any = false;
    FORD (len, 12, 1) {
      bool fail = false;
      REP (mask, 1 << len) {
        if (masks[n + i][len][mask] == 0) {
          fail = true;
          break;
        }
      }
      if (!fail) {
        any = 1;
        cout<<len<<"\n";
        break;
      }
    }
    if (!any) {
      cout<<"0\n";
    }
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}