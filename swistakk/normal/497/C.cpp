#include <bits/stdc++.h>
long long max(int a, long long b) { return max((long long)a, b); }
long long max(long long b, int a) { return max(a, (long long)b); }
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
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
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int N = 2e5 + 5;
struct Point {
  int x, y, is_song, nr;
};

struct PtCompare {
    bool operator() (const Point& p1, const Point& p2) const {
        return p1.y < p2.y;
    }
};

bool Cmp(Point a, Point b) {
  if (a.x != b.x) { return a.x > b.x; }
  return a.is_song > b.is_song;
}
int ass[N];
int a[N], b[N], c[N], d[N], k[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  
  vector<Point> evs;
  make(int, song);
  RE (i, song) {
    cin>>a[i]>>b[i];
    evs.PB(Point{a[i], b[i], 1, i});
  }
  make(int, actor);
  RE (i, actor) {
    cin>>c[i]>>d[i]>>k[i];
    evs.PB(Point{c[i], d[i], 0, i});
  }
  sort(ALL(evs), Cmp);
  multiset<Point, PtCompare> songs;
  for (auto p : evs) {
    debug4(p.x, p.y, p.is_song, p.nr);
    if (p.is_song) {
      songs.insert(p);
    } else {
      int ac = p.nr;
      while (k[ac]) {
        Point szt = Point{p.x, p.y + 1, 0, 0}; 
        auto it = songs.lower_bound(szt);
        if (it == songs.begin()) { break; }
        it--;
        ass[it->nr] = ac;
        songs.erase(it);
        k[ac]--;
      }
    }
  }
  if (SZ(songs)) {
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  RE (i, song) {
    cout<<ass[i]<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}