#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


template<class T> struct Point3D {
  typedef Point3D P;
  typedef const P& R;
  T x, y, z;
  explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
  bool operator<(R p) const {
    return tie(x, y, z) < tie(p.x, p.y, p.z); }
  bool operator==(R p) const {
    return tie(x, y, z) == tie(p.x, p.y, p.z); }
  P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
  P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
  P operator*(T d) const { return P(x*d, y*d, z*d); }
  P operator/(T d) const { return P(x/d, y/d, z/d); }
  T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
  P cross(R p) const {
    return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
  }
  T dist2() const { return x*x + y*y + z*z; }
  ld dist() const { return sqrt((ld)dist2()); }
  //Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
  ld phi() const { return atan2(y, x); } 
  //Zenith angle (latitude) to the z-axis in interval [0, pi]
  ld theta() const { return atan2(sqrt(x*x+y*y),z); }
  P unit() const { return *this/(T)dist(); } //makes dist()=1
  //returns unit vector normal to *this and p
  P normal(P p) const { return cross(p).unit(); }
  //returns point rotated 'angle' radians ccw around axis
  P rotate(ld angle, P axis) const {
    ld s = sin(angle), c = cos(angle); P u = axis.unit();
    return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
  }

  friend istream& operator>>(istream& is, P& p) { return is >> p.x >> p.y >> p.z; }

};

using P = Point3D<ld>;


using POLY = array<ld,3>;

POLY NICOLE(vector<P> triangle, long double h) {
  sort(all(triangle), [&](P a, P b) { return a.z > b.z; });

  //triangle.sort(); //TODO: sortera med avseende p z-koordinat. Strst frst.

  POLY ret = {0,0,0};

  if(triangle[2].z>=h) {
    P u = triangle[1]-triangle[0];
    P v = triangle[2]-triangle[0];
    ret[0] = u.cross(v).dist()/2;
    assert(ret[0]>=0);
  }
  else if(triangle[1].z>=h) {
    assert(triangle[0].z != triangle[2].z);
    ld lambda = (triangle[1].z-triangle[2].z)/(triangle[0].z-triangle[2].z);
    P intersection = triangle[0]*lambda+triangle[2]*(1-lambda);
    vector<P> top_triangle;
    ld top_area = (triangle[1]-triangle[0]).cross(intersection-triangle[0]).dist()/2;
    ld bot_area = (triangle[1]-triangle[2]).cross(intersection-triangle[2]).dist()/2;

    //vector<P> bottom_triangle;
    //bottom_triangle.push_back(intersection);
    //bottom_triangle.push_back(triangle[1]);
    //bottom_triangle.push_back(triangle[2]);
    //ret = area_diffs(bottom_triangle,triangle[1].z,true);

    P u = triangle[1]-triangle[2];
    P v = intersection-triangle[2];
    P u_scaled = u/u.z;
    P v_scaled = v/v.z;
    ld z0 = triangle[2].z;
    ld da = u_scaled.cross(v_scaled).dist()/2;
    ret[0]= bot_area - da*z0*z0;
    ret[1]=  +da*2*z0;
    ret[2]=  -da;

    ret[0] += top_area;

  } else if(triangle[0].z>=h){
    P u = triangle[1]-triangle[0];
    P v = triangle[2]-triangle[0];
    P u_scaled = u/u.z;
    P v_scaled = v/v.z;
    ld z0 = triangle[0].z;
    ld da = u_scaled.cross(v_scaled).dist()/2;
    ret[0]=da*z0*z0;
    ret[1]=-da*2*z0;
    ret[2]=da;
    // h = t[1].z
  }
  return ret;
}


struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  vector<P> pts(n);
  rep(i,0,n) cin>>pts[i];

  vector<vi> g(n);
  vector<vi> in_face(n);
  auto ae = [&](int a, int b) {
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  };

  using F = tuple<int,int,int>;
  int m;
  cin>>m;
  vector<F> faces(m);
  vector<POLY> face_poly(m, POLY{0,0,0});
  int tf = 0;
  for(auto& [a,b,c] : faces) {
    cin>>a>>b>>c;
    --a,--b,--c;
    ae(a,b);
    ae(b,c);
    ae(c,a);
    in_face[a].emplace_back(tf);
    in_face[b].emplace_back(tf);
    in_face[c].emplace_back(tf);
    ++tf;
  }

  map<int,pair<vi,vi>> at_h;
  rep(i,0,n) at_h[-pts[i].z].first.emplace_back(i);

  int q;
  cin>>q;
  vi queries(q);
  rep(i,0,q) {
    int hh;
    cin>>hh>>queries[i];
    --queries[i];
    at_h[-hh].second.emplace_back(i);
  }
  vector<ld> ans(q,-99);


  UF uf(n);
  vector<POLY> poly(n);
  rep(i,0,n) rep(j,0,sz(poly[i])) poly[i][j] = 0;

  POLY BAD{-97,-97,-97};

  auto join = [&](int x, int y) {
    if(uf.sameSet(x,y)) return;
    x = uf.find(x);
    y = uf.find(y);
    assert(x != y);
    POLY q;
    rep(i,0,sz(q)) q[i] = poly[x][i] + poly[y][i];
    uf.join(x,y);
    poly[x] = poly[y] = BAD;
    poly[uf.find(x)] = q;
  };

  int H = 1e9+10;
  int LH = 1e9+10;

  auto eval = [&](const auto& p) { return p[0] + p[1]*H + p[2]*H*H; };
  auto query = [&](int x) -> ld {
    if(pts[x].z <= H) return -97;
    return eval(poly[uf.find(x)]);
  };

  auto JOCKE = [&](P a, P b, P c, int h) -> POLY {
    ld area = (c-a).cross(b-a).dist()/2;
    //if(h > max({a.z, b.z, c.z})) return POLY{0,0,0};
    if(h <= min({a.z, b.z, c.z})) return POLY{area,0,0};
    return POLY{0,0,0};

    //TODO other cases...
  };

  auto get_poly = [&](int f, int h) -> POLY {
    auto [a,b,c] = faces[f];
    return NICOLE(vector<P>{pts[a],pts[b],pts[c]},h);
    //return JOCKE(pts[a],pts[b],pts[c],h);
    //return POLY{0,0,0};
  };

  auto update_poly = [&](auto& p, int x) {
    for(int f : in_face[x]) {
      //auto prv = get_poly(f,LH);
      auto prv = face_poly[f];
      auto nxt = get_poly(f,H);
      rep(i,0,sz(p)) p[i] = p[i] - prv[i] + nxt[i];
      face_poly[f] = nxt;
    }
  };

  for(auto [_hh, v] : at_h) {
    LH = H;
    H = -_hh;

    for(int x : v.second) ans[x] = query(queries[x]);

    for(int x : v.first) for(int y : g[x]) if(pts[y].z >= H) join(x,y);
    for(int x : v.first) update_poly(poly[uf.find(x)], x);
    //TODO move

  }
  assert(H == 0);

  cout << setprecision(14) << fixed;
  rep(i,0,q) {
    if(ans[i] == -97) cout << -1 << "\n";
    else cout << ans[i] << "\n";
  }
}