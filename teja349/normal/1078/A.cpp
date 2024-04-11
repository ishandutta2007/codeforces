//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


/*
Geometry Library which has been taken from user @alecsyde on codeforces
Its awesome
*/

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,itit )  for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const int N = 1e6+10;
const ll INF = 1e18;

//#define DEBUG

#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

//#define double long double
const double EPS =1e-12;
#define CT double
struct Point {
  CT x, y;
  Point() {}
  Point(CT x, CT y) : x(x), y(y) {}
  Point(const Point &p) : x(p.x), y(p.y)    {}
  Point operator + (const Point &p)  const { return Point(x+p.x, y+p.y); }
  Point operator - (const Point &p)  const { return Point(x-p.x, y-p.y); }
  Point operator * (double c)     const { return Point(x*c,   y*c  ); }
  Point operator / (double c)     const { return Point(x/c,   y/c  ); }
};

CT dot(Point p, Point q)     { return p.x*q.x+p.y*q.y; }
double dist2(Point p, Point q)   { return dot(p-q,p-q); }
CT cross(Point p, Point q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const Point &p) {
  os << "(" << p.x << "," << p.y << ")";
}

bool operator < (const Point& a, const Point& b) {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
bool operator == (const Point& a, const Point& b) {
    //change accordingly
    return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;
    //return make_pair(a.y, a.x) == make_pair(b.y, b.x);
}


// rotate a point CCW or CW around the origin
Point RotateCCW90(Point p)   { return Point(-p.y,p.x); }
Point RotateCW90(Point p)    { return Point(p.y,-p.x); }
Point RotateCCW(Point p, double t) {
  return Point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// project point c onto line through a and b
// assuming a != b
Point ProjectPointLine(Point a, Point b, Point c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// project point c onto line segment through a and b
Point ProjectPointSegment(Point a, Point b, Point c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}
//return line perpendicular through line passing through a and b and passing through c
pair<Point,Point> Perpendicularline(Point a,Point b,Point c){
  c=ProjectPointLine(a,b,c);
//  printf("%lf %lf %lf %lf %d\n",a.x,a.y,c.x,c.y,a==c);
  if(a==c) a=b;

  return mp(c,c+RotateCW90(a-c));
}
// compute distance from c to segment between a and b
double DistancePointSegment(Point a, Point b, Point c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d)
{
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(Point a, Point b, Point c, Point d) {
  return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(Point a, Point b, Point c, Point d) {
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS;
}

// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(Point a, Point b, Point c, Point d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
Point ComputeLineIntersection(Point a, Point b, Point c, Point d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

// compute center of circle given three points
Point ComputeCircleCenter(Point a, Point b, Point c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
bool PointInPolygon(const vector<Point> &p, Point q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<Point> &p, Point q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<Point> CircleLineIntersection(Point a, Point b, Point c, double r) {
  vector<Point> ret;
  b = b-a;
  a = a-c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r*r;
  double D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS)
    ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<Point> CircleCircleIntersection(Point a, Point b, double r, double R) {
  vector<Point> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  Point v = (b-a)/d;
  ret.push_back(a+v*x + RotateCCW90(v)*y);
  if (y > 0)
    ret.push_back(a+v*x - RotateCCW90(v)*y);
  return ret;
}

// This code computes the area or centroid of a (possibly nonconvex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
double ComputeSignedArea(const vector<Point> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}

double ComputeArea(const vector<Point> &p) {
  return fabs(ComputeSignedArea(p));
}

Point ComputeCentroid(const vector<Point> &p) {
  Point c(0,0);
  double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
  }
  return c / scale;
}

// tests whether or not a given polygon (in CW or CCW order) is simple
bool IsSimple(const vector<Point> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i+1; k < p.size(); k++) {
      int j = (i+1) % p.size();
      int l = (k+1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
        return false;
    }
  }
  return true;
}
typedef vector< Point > Polygon;
#define sqr(x) (x)*(x)
//#define REMOVE_REDUNDANT
CT area2(Point a, Point b, Point c) { return cross(b-a,c-a); }   // 2 times area
#ifdef REMOVE_REDUNDANT
bool between(const Point &a, const Point &b, const Point &c) {        // b is between a & c
    return abs(area2(a, b, c)) <eps && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0;
}
#endif

void ConvexHull(vector<Point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}

#define Det(a,b,c) ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)) //returns (B-A)X(C-A)
bool in_convex(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);     // orientation of area, a is above 0 and b below 0
    // Allow on edge --> if (Det... > 0 || Det ... < 0)
    if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) return false;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(l[0], l[c], p) > 0) b = c; else a = c;
    }
    // Alow on edge --> return Det... <= 0
    return Det(l[a], l[b], p) <= 0;
}
#define sqr(x) (x)*(x)
#define line pair<Point,Point>
#define NEED3RDTANGENT
// need to be careful when tangent has single common point with both circles specially when one cricle lies inside other
vector<line> find_tangent(Point a,Point b,CT r1,CT r2){
  vector<line> Q;
  if(dist2(a,b)<=sqr(r1-r2)) return Q;
  int f=0;
  if(r2>r1) swap(a,b),swap(r1,r2),f=1;
  if(abs(r2-r1)<=EPS){
    line m=Perpendicularline(a,b,a),n=Perpendicularline(a,b,b);
    //printf("%lf %lf %lf %lf\n",m.X.x,m.X.y,m.Y.x,m.Y.y);
    vector<Point> l1=CircleLineIntersection(m.X,m.Y,a,r1),l2=CircleLineIntersection(n.X,n.Y,b,r2);
    assert(l1.size()==2&&l2.size()==2);
    if(cross(b-a,l1[0]-b)*cross(b-a,l2[0]-b)<0) swap(l2[0],l2[1]);
    Q.pb(mp(l1[0],l2[0])); Q.pb(mp(l1[1],l2[1]));
  }else{
    Point out=(b*r1-a*r2)/(r1-r2);
  //  printf("%lf %lf\n",out.x,out.y);
    assert(dist2(out,a)>=r1&&dist2(out,b)>=r2);
    vector<Point> l1=CircleCircleIntersection(a,out,r1,sqrt(dist2(out,a)-sqr(r1))),l2=CircleCircleIntersection(b,out,r2,sqrt(dist2(out,b)-sqr(r2)));
    assert(l1.size()==2&&l2.size()==2);
    if(cross(b-a,l1[0]-b)*cross(b-a,l2[0]-b)<0) swap(l2[0],l2[1]);
    Q.pb(mp(l1[0],l2[0])); Q.pb(mp(l1[1],l2[1]));
  }
//  printf("%d\n",1);
  if(dist2(a,b)>sqr(r1+r2)+EPS){
    Point out=(b*r1+a*r2)/(r1+r2);
  //  printf("%lf %lf\n",out.x,out.y);
    assert(dist2(out,a)>=r1&&dist2(out,b)>=r2);
    vector<Point> l1=CircleCircleIntersection(a,out,r1,sqrt(dist2(out,a)-sqr(r1))),l2=CircleCircleIntersection(b,out,r2,sqrt(dist2(out,b)-sqr(r2)));
    assert(l1.size()==2&&l2.size()==2);
    if(cross(b-a,l1[0]-b)*cross(b-a,l2[0]-b)>0) swap(l2[0],l2[1]);
    Q.pb(mp(l1[0],l2[0])); Q.pb(mp(l1[1],l2[1]));
  }else if(abs(sqr(r1+r2)-dist2(a,b))<EPS){
    #ifdef NEED3RDTANGENT
      Point out=(b*r1+a*r2)/(r1+r2);
    //    printf("%lf %lf\n",out.x,out.y);
      Q.pb(Perpendicularline(a,b,out));
    #endif
  }
  if(f==1){
    REP(i,Q.size()) swap(Q[i].X,Q[i].Y);
  }
  return Q;
}
double error = 1e-8;
Point rect;
vector<pair<Point,double> > circ;
#define ld long double
bool inpoly(vector<Point> &a,Point b){
  int n=a.size();
  REP(i,a.size()){
    if(DistancePointSegment(a[i],a[(i+1)%n],b)<error) return 1;
  }
  return in_convex(a,b);
}
bool outcircle(Point cen,double rad,Point a){
  if(dist2(cen,a)>rad*rad-error) return 1;
  return 0;
}
Point bottom;
bool cmp(Point a,Point b){
    double val=cross(a-bottom,b-a);
    if(fabs(val)<EPS){
        return dist2(bottom,b)>dist2(bottom,a);
    }
    return val>EPS;
}
int myconvexhull(vector< Point > &pts){
  sort(all(pts));
  pts.resize(unique(pts.begin(),pts.end())-pts.begin());
  bottom=pts[0];
    sort(pts.begin()+1,pts.end(),cmp);
    vector <Point >hull;
    hull.clear();
    REP(i,pts.size()){
      while(hull.size()>=2&&cross(hull[hull.size()-2]-hull[hull.size()-1],pts[i]-hull[hull.size()-1])>=-1*EPS){
        hull.pop_back();
      }
      hull.push_back(pts[i]);

    }

    pts.clear();
    REP(i,hull.size()){
      pts.pb(hull[i]);
    }
    
    return 0;
}

bool checksegline(Point a,Point b,Point c,Point d){
	Point p= ComputeLineIntersection(a,b,c,d);
	double val=DistancePointSegment(a,b,p);
	//cout<<p<<endl;
	if(val<EPS)
		return 1;
	return 0;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	long double aa,bb,cc;
  	cin>>aa>>bb>>cc;
  	long double x1,y1,x2,y2;
  	cin>>x1>>y1>>x2>>y2;
  	if(x1==x2){
  		cout<<setprecision(30)<<abs(y1-y2)<<endl;
  		return 0;
  	}
  	if(y1==y2){
  		cout<<setprecision(30)<<abs(x1-x2)<<endl;
  		return 0;
  	}
  	if(aa==0 || bb==0){
  		cout<<setprecision(30)<<abs(x2-x1)+abs(y2-y1)<<endl;
  		return 0;
  	}
  	if(x1>x2){
  		swap(x1,x2);
  		swap(y1,y2);
  	}
  	//cout<<"DAs"<<endl;
  	long double gx1,gx2,gy1,gy2,val;
  	gx1=0;
  	gy1=-1*cc/bb;
  	gy2=0;
  	gx2=1;
  	gy2=-1*(cc+aa)/bb;
  	Point a=Point(gx1,gy1);
  	Point b=Point(gx2,gy2);
  	long double ans=abs(x2-x1)+abs(y2-y1);
  	if(checksegline(Point(x1,y1),Point(x2,y1),a,b) && checksegline(Point(x2,y1),Point(x2,y2),a,b)){
  		//cout<<"ds"<<endl;
      Point p=ComputeLineIntersection(Point(x1,y1),Point(x2,y1),a,b);
  		val=sqrt(dist2(p,Point(x1,y1)));
  		Point q=ComputeLineIntersection(Point(x2,y1),Point(x2,y2),a,b);
  		val+=sqrt(dist2(p,q));
  		val+=sqrt(dist2(q,Point(x2,y2)));
  		ans=min(val,ans);
  	}
  	if(checksegline(Point(x1,y1),Point(x1,y2),a,b) && checksegline(Point(x1,y2),Point(x2,y2),a,b)){
  		
      Point p=ComputeLineIntersection(Point(x1,y1),Point(x1,y2),a,b);
  		val=sqrt(dist2(p,Point(x1,y1)));
  		Point q=ComputeLineIntersection(Point(x1,y2),Point(x2,y2),a,b);
  		val+=sqrt(dist2(p,q));
  		val+=sqrt(dist2(q,Point(x2,y2)));
  		ans=min(val,ans);
  	}

    if(checksegline(Point(x1,y1),Point(x2,y1),a,b) && checksegline(Point(x1,y2),Point(x2,y2),a,b)){
      //cout<<"ds"<<endl;
      Point p=ComputeLineIntersection(Point(x1,y1),Point(x2,y1),a,b);
      val=sqrt(dist2(p,Point(x1,y1)));
      Point q=ComputeLineIntersection(Point(x1,y2),Point(x2,y2),a,b);
      val+=sqrt(dist2(p,q));
      val+=sqrt(dist2(q,Point(x2,y2)));
      ans=min(val,ans);
    }
    if(checksegline(Point(x1,y1),Point(x1,y2),a,b) && checksegline(Point(x2,y1),Point(x2,y2),a,b)){
      
      Point p=ComputeLineIntersection(Point(x1,y1),Point(x1,y2),a,b);
      val=sqrt(dist2(p,Point(x1,y1)));
      Point q=ComputeLineIntersection(Point(x2,y1),Point(x2,y2),a,b);
      val+=sqrt(dist2(p,q));
      val+=sqrt(dist2(q,Point(x2,y2)));
      ans=min(val,ans);
    }

  	cout<<setprecision(30)<<ans<<endl;

  	
    return 0;   
}