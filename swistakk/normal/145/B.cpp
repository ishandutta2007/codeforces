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
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
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
using namespace std;
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
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}

void Exit() {
  cout<<"-1\n";
  exit(0);
}
VI res;
VI trures;
int inv;
int t4, t7, t47, t74;
void Print() {
  for (auto x : res) {
    if ((x == 4 && !inv) || (x == 7 && inv)) {
      trures.PB(4);
      cout<<4;
    } else {
      trures.PB(7);
      cout<<7;
    }
  }
  for (int i = 0; i < SZ(trures); i++) {
    if (trures[i] == 4) { t4--; }
    if (trures[i] == 7) { t7--; }
    if (i < SZ(trures) - 1 && trures[i] == 4 && trures[i + 1] == 7) { t47--; }
    if (i < SZ(trures) - 1 && trures[i] == 7 && trures[i + 1] == 4) { t74--; }
  }
  //debug(t4, t7, t47
  cout<<endl;
  assert(t4 == 0 && t7 == 0 && t47 == 0 && t74 == 0);
  
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make4(int, c4, c7, c47, c74);
  if (abs(c47 - c74) > 1) {
    Exit();
  }
  t4 = c4;
  t7 = c7;
  t47 = c47;
  t74 = c74;
  if (min(c4, c7) < max(c47, c74) || c4 + c7 == c47 + c74) {
    Exit();
  }
  
//   if (c47 < c74) {
//     swap(c4, c7);
//     swap(c47, c74);
//     inv ^= 1;
//   }
  if (c47 > c74) {
    
      cerr<<"Cas1\n";
    res.PB(4);
    RE (i, c4 - c47) {
      res.PB(4);
    }
    res.PB(7);
    RE (i, c47 - 1) {
      res.PB(4);
      res.PB(7);
    }
    RE (i, c7 - c47) {
      res.PB(7);
    }
  } else if (c74 > c47) {
    
    cerr<<"Cas2\n";
    res.PB(7);
    RE (i, c4 - c74 + 1) {
      res.PB(4);
    }
    RE (i, c74 - 1) {
      res.PB(7);
      res.PB(4);
    }
    res.pop_back();
    RE (i, c7 - c74) {
      res.PB(7);
    }
    res.PB(4);
  } else {
    if (c4 > c47) {
      
      cerr<<"Cas3\n";
      res.PB(4);
      RE (i, c4 - c47 - 1) {
        res.PB(4);
      }
      RE (i, c74) {
        res.PB(7);
        res.PB(4);
      }
      res.pop_back();
      RE (i, c7 - c74) {
        res.PB(7);
      }
      res.PB(4);
    } else {
      cerr<<"Cas4\n";
      res.PB(7);
      RE (i, c47) {
        res.PB(4);
        res.PB(7);
      }
      RE (i, c7 - c74 - 1) {
        res.PB(7);
      }
      
    }
  }
  Print();
  
  assert(SZ(res) == c4 + c7);
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}