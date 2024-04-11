#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#include <stdexcept>
#include <exception>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
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
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

int mod3 (int a) {
  a = a % 3;
  if (a < 0) {
    a += 3;
  }
  return a;
}

ll det3(const vector<vector<ll> >& vec) {
  ll res = 0;
  for (int sign = -1; sign <= 1; sign += 2) {
    for (int i = 0; i < 3; i++) {
      res += sign * vec[0][i] * vec[1][mod3(i + sign)] * vec[2][mod3(i + 2 * sign)];
    }
  }
  return res;
}

ll gcd(ll a, ll b) {
  a = abs(a);
  b = abs(b);
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

struct p {
  vector<ll> coords;
  p(vector<ll>& c) {
    coords = c;
  }
  p() {
  }
  p operator-(const p& d) const {
    auto tmp = coords;
    while (coords.size() != 3 && d.coords.size() != 3) ;
    REP (i, 3) {
      tmp[i] -= d.coords[i];
    }
    p to_ret = p(tmp);
    return to_ret;
  }
};

void normalize(vector<ll>& c) {
  bool zeros = true;
  ll maxgcd = 0;
  for (int i = 0; i < c.size(); i++) {
    maxgcd = gcd(maxgcd, c[i]);
  }
  if (maxgcd == 0) {
    throw 1;
  }
  for (ll& a : c) {
    a /= maxgcd;
  }
  bool negate = false;
  for (ll&a : c) {
    if (zeros && a < 0) {
      negate = true;
    }
    if (negate) {
      a *= -1;
    }
    zeros &= (a == 0);
  }
}

struct plane {
  vector<ll> coefs;
 private:
  void make_plane(vector<ll>& c) {
    normalize(c);
    coefs = c;
  }
 public:
  plane(const p& p1, const p& p2, const p& p3) {
    p tab[] = {p1, p2, p3};
    vector<vector<ll> > basic;
    REP (i, 3) {
      basic.PB(tab[i].coords);
    }
    vector<ll> c;
    c.resize(4);
    ll D = det3(basic);
    c[3] = D;
    REP (i, 3) {
      auto tmp = basic;
      REP (j, 3) {
        tmp[j][i] = 1;
      }
      c[i] = det3(tmp);
    }
    make_plane(c);
  }
  bool check(p pkt) {
    ll acc = 0;
    REP (i, 3) {
      acc += pkt.coords[i] * coefs[i];
    }
    return acc == coefs[3];
  }
  plane() {
  }
};

vector<ll> convert(const p& p1, const p& p2) {
  p p3 = p1 - p2;
  normalize(p3.coords);
  return p3.coords;
}

vector<pair<ll, ll> > lines_intersection(const p& p1, const p& p2, const p& p3,
    const p& p4) {
  vector<vector<ll> > mat;
  mat.resize(3);
  mat[2].resize(3);
  p tab[] = {p1, p2};
  ll res[] = {0, 0};
  REP (j, 3) {
    REP (i, 2) {
      mat[0] = (p3 - tab[i]).coords;
      mat[1] = (p4 - tab[i]).coords;
      REP (k, 3) {
        mat[2][k] = (j == k);
      }
      res[i] = det3(mat);
    }
    if (res[0] != 0 || res[1] != 0) {
      break;
    }
  }
  if (res[0] == 0 && res[1] == 0) {
    throw -1; // segments are collinear
  }
  if (res[0] == res[1]) {
    throw -2; // segments are parallel
  }
  vector<pair<ll, ll> > to_ret;
  REP (i, 3) {
    pair<ll, ll> frac = MP(res[0] * p2.coords[i] - res[1] * p1.coords[i], res[0] - res[1]);
    ll gcd_ = gcd(frac.first, frac.second);
    frac.first /= gcd_;
    frac.second /= gcd_;
    to_ret.PB(frac);
  }
  return to_ret;
}
    
  
    

map<vector<ll>, set<vector<ll> > > mapka;
map<vector<pair<ll, ll> >, set<int> > intersections;

const int N = 1005;
p mets[N][2];

int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, n);
  
  RE (i, n) {
    REP (j, 2) {
      vector<ll> c;
      RE (k, 3) {
        make(int, d);
        c.PB(d);
      }
      mets[i][j] = p(c);
    }
  }
  int res = 1;
  RE (i, n) {
    FOR (j, i + 1, n) {
      plane tmp;
      try {
        tmp = plane(mets[i][0], mets[i][1], mets[j][0]);
      } catch (...) {
        tmp = plane(mets[i][0], mets[i][1], mets[j][1]);
      }
      if (!tmp.check(mets[j][1])) {
        continue;
      }
      try {
        vector<pair<ll, ll> > inter = lines_intersection(mets[i][0], mets[i][1], mets[j][0], mets[j][1]);
        auto& secik2 = intersections[inter];
        secik2.insert(i);
        secik2.insert(j);
        maxi(res, int(secik2.size()));
      } catch(...) {
      }
      
      set<vector<ll> >& secik = mapka[tmp.coefs];
      secik.insert(convert(mets[i][0], mets[i][1]));
      secik.insert(convert(mets[j][0], mets[j][1]));
      maxi(res, int(secik.size()));
    }
  }
  
  cout<<res<<endl;

  
  // nie zapomnij o ll
  return 0;
}