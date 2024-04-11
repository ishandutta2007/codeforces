#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define M_PI (acos(-1))
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

#define R(x) const { return x; }
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) R(x<p.x || x==p.x && y<p.y)
    bool operator==(P p) R(x==p.x && y==p.y)
    P operator+(P p) R(P(x+p.x, y+p.y))
    P operator-(P p) R(P(x-p.x, y-p.y))
    P operator*(T d) R(P(x*d, y*d))
    P operator/(T d) R(P(x/d, y/d))
    T dot(P p) R(x*p.x + y*p.y)
    T cross(P p) R(x*p.y - y*p.x)
    T dist2() R(x*x + y*y) // distance2
    double dist() R(sqrt((double)dist2())) //length
    // angle to xaxis in interva l [pi , pi ]
    double angle() R(atan2(y, x))
    P unit() R(*this/(T)dist()) // makes d is t ()=1
    P perp() R(P(-y, x)) // rotates +pi/2 radians
    P normal() R(perp().unit())
    // returns point rotated a radians ccw around the origin
    P rotate(double a) R(P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)))
};
typedef Point<double> pt;

template <class P>
pair<P,P> circleTangents(const P &p, const P &c, double r) {
    P a = p-c;
    double x = r*r/a.dist2(), y = sqrt(x-x*x);
    return mp(c+a*x+a.perp()*y, c+a*x-a.perp()*y);
}
template <class P>
pair<P,P> circleCircle(const P &c, double r,double rr) {
    double d = c.dist();
    if(d>=r+rr) return mp(P(0,0),P(0,0));
    double d1 = (d*d-r*r+rr*rr)/(2.0*d);
    assert(rr>d1);
    P p = c.unit()*d1;
    P of = c.unit().perp()*sqrt(rr*rr-d1*d1);
    return mp(p-of,p+of);
}

map<double,int> m;
void cover(double a,double b){
    while(a<0)a+=2*M_PI;
    while(b<0)b+=2*M_PI;
    //cout<<a<<" "<<b<<endl;
    if(a>b){
        cover(0,b);
        cover(a,2*M_PI);
    }
    else{
        m[a] += 1;
        m[b] -= 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x0,y0,v,t,n;
    cin>>x0>>y0>>v>>t>>n;
    double rr = v*1.0*t,r2=rr*rr;
    rep(i,0,n){
        int x,y,r;
        cin>>x>>y>>r;
        x-=x0,y-=y0;
        if(x*1LL*x+y*1LL*y<=r*1LL*r){
            puts("1.0");
            return 0;
        }
        auto p = circleTangents(pt(0,0),pt(x,y),r);
        if(p.X.dist2()<=r2){ //tangent points inside
            cover(p.X.angle(),p.Y.angle());
        }
        else{
            auto p = circleCircle(pt(x,y),r,rr);
            if(p!=mp(pt(0,0),pt(0,0)))cover(p.X.angle(),p.Y.angle());
        }
    }
    double tt=0;
    double res=0;
    int cnt=0;
    for(auto p:m){
        if(cnt)res+=(p.X-tt);
        cnt+=p.Y;
        tt=p.X;
    }
    cout<<setprecision(30)<<res/(2.0*M_PI)<<endl;
    return 0;
}