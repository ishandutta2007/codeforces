// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rng(1234);

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
vector<P> tangents(P c1, double r1, P c2, double r2=0) {
	P d = c2 - c1;
	double dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
	if (d2 == 0 || h2 < 0)  return {};
	vector<P> out;
	for (double sign : {-1, 1}) {
		P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
		out.push_back(c1 + v * r1);
	}
	return out;
}

template<class P>
vector<P> circleLine(P c, double r, P a, P b) {
	P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
	double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	P h = ab.unit() * sqrt(h2);
	return {p - h, p + h};
}
 
const int maxn=200007;
const int inf=LLONG_MAX/4;
const double eps=1e-8;
const double pi=3.1415926536;
int n;
double l;
int x[maxn],y[maxn];


using P = Point<double>;
P pts[maxn];
double sum=0;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    double res=0;
    cin>>n>>l;
    rep(i,n) cin>>x[i]>>y[i], pts[i]=P(x[i],y[i]);
    for (int i=n;i<=3*n;++i) pts[i]=pts[i-n];
    rep(i,n) l-=(pts[i+1]-pts[i]).dist();
    int le=1, ri=2;
    l+=(pts[2]-pts[1]).dist();
    while (le<=n){
        P dir=pts[ri]-pts[le], cent=(pts[ri]+pts[le])/2;
        double ang=dir.angle(), major=l/2, minor=sqrt(major*major-dir.dist2()/4);
        auto trans=[&](P p)->P{
            p=p-cent;
            p=p.rotate(-ang);
            p.x/=major, p.y/=minor;
            return p;
        };
        auto ptle1=circleLine(P(0,0),1,trans(pts[le-1]),trans(pts[le]))[1].angle();
        auto ptle2=circleLine(P(0,0),1,trans(pts[le]),trans(pts[le+1]))[1].angle();
        if (ptle2<ptle1) ptle2+=2*pi;
        auto ptri1=circleLine(P(0,0),1,trans(pts[ri]),trans(pts[ri-1]))[1].angle();
        auto ptri2=circleLine(P(0,0),1,trans(pts[ri+1]),trans(pts[ri]))[1].angle();
        if (ptri2<ptri1) ptri2+=2*pi;
        if (ptri2>ptle1+2*pi) ptri2-=2*pi, ptri1-=2*pi;
        if (ptle2>ptri1+2*pi) ptle2-=2*pi, ptle1-=2*pi;
        auto unfold=[&](double alpha){
            P r(major*cos(alpha),minor*sin(alpha));
            r=r.rotate(ang);
            r=r+cent;
        };
        auto calc=[&](double alpha1,double alpha2)->double{
            if (alpha1>alpha2) return 0;
            unfold(alpha1), unfold(alpha2);
            double ans=0;
            ans+=major*minor*(alpha2-alpha1);
            ans+=cent.cross(dir.unit())*major*(cos(alpha2)-cos(alpha1));
            ans+=cent.cross(dir.normal())*minor*(sin(alpha2)-sin(alpha1));
            
            return ans;
        };
        res+=calc(max(ptle1,ptri1),min(ptle2,ptri2));
        if (le+1<ri&&ptle2<ptri2) l-=(pts[le+1]-pts[le]).dist(), le++;
        else l+=(pts[ri+1]-pts[ri]).dist(), ri++;
    }
    cout<<res/2;
    return 0;
}