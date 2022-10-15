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

const int maxn=200007;
const int inf=LLONG_MAX/4;
const double eps=1e-8;
int n,k;
int x[maxn],y[maxn],C[maxn],pos[maxn];
vector<tuple<int,double,int>> res;

int lowbit(int u){return u&(-u);}
void update(int u,int w){
    for (int i=u;i<=2*n;i+=lowbit(i)) C[i]+=w;
}
int query(int u){
    int res=0;
    for (int i=u;i>0;i-=lowbit(i)) res+=C[i];
    return res;
}

using P = Point<double>;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15);
    cin>>n>>k;
    rep(i,n) cin>>x[i]>>y[i];
    double ans=0;
    auto check=[&](double R){
        res.clear();
        int removed=0;
        rep(i,n){
            if (x[i]*x[i]+y[i]*y[i]<R*R) {removed++; continue;}
            auto ret=tangents<P>(P(0,0),R,P(x[i],y[i]));
            rep(j,2){
                if (ret[j].y>0||(ret[j].y==0&&ret[j].x>0)) res.pb({-1,-ret[j].x,i});
                else res.pb({1,ret[j].x,i});
            }
        }
        memset(pos,0,sizeof(pos));
        sort(range(res));
        int ans=n*(n-1)/2;
        int hii=0;
        rep1(i,sz(res)){
            auto [u,v,w]=res[i-1];
            if (pos[w]){
                ans-=query(i)-query(pos[w]);
                update(pos[w],-1);
                pos[w]=0;
            }
            else{
                pos[w]=i;
                update(i,1);
            }
        }
        return ans<k;
    };
    for (double ret=1e4;ret>eps;ret/=2){
        if (check(ans+ret)) ans+=ret;
    }
    cout<<ans;
    return 0;
}