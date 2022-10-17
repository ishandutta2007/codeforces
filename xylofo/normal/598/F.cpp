#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const ld EPS=(ld)1e-9;

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
        ld dist() R(sqrt((ld)dist2())) //length
        // angle to xaxis in interva l [pi , pi ]
        ld angle() R(atan2(y, x))
        P unit() R(*this/(T)dist()) // makes d is t ()=1
        P perp() R(P(-y, x)) // rotates +pi/2 radians
        P normal() R(perp().unit())
        // returns point rotated a  radians ccw around the origin
        P rotate(ld a) R(P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)))
};
template <class P>
int lineIntersection(const P& s1, const P& e1, const P& s2,
        const P& e2, P& r) {
    if ((e1-s1).cross(e2-s2)) { // i f not p a r a l l e l l
        r = s2-(e2-s2)*(e1-s1).cross(s2-s1)/(e1-s1).cross(e2-s2);
        return 1;
    } else
        return -((e1-s1).cross(s2-s1)==0 || s2==e2);
}
//template <class P, class It>
//vector<P> polygonCut(It begin, It end, P s, P e) {
//    vector<P> res;
//    if (begin == end) return res;
//    for (It i = begin, j = end-1; i != end; j = i++) {
//        bool side = (e-s).cross(*i-s) < 0;
//        if (side != ((e-s).cross(*j-s)<0)) {
//            res.push_back(P());
//            lineIntersection(s, e, *i, *j, res.back());
//        }
//        if (side)
//            res.push_back(*i);
//    }
//    return res;
//}

template <class P, class It>
ld polygonCut(It begin, It end, P s, P e) {
    vector<P> res;
    vector<pair<ld,ld> > l1;
    for (It i = begin, j = end-1; i != end; j = i++) {
        ld si = (e-s).cross(*i-s);
        ld sj = (e-s).cross(*j-s);
        if(fabs(si)<EPS && fabs(sj)<EPS)l1.pb(min(mp((s-*i).dist(),(s-*j).dist()),mp((s-*j).dist(),(s-*i).dist())));
        if((si<0) != (sj<0)){
            res.push_back(P());
            lineIntersection(s, e, *i, *j, res.back());
        }
    }
    map<ld,int> m;
    bool in=true;
    sort(allof(res),[&](P x, P y){return (x-s).dist()<(y-s).dist();});
    ld ans=0;
    for(auto p:res){
        m[(p-s).dist()]+=(in?1:-1);
        in = !in;
    } 
    for(auto p:l1){
        m[p.X]+=1;
        m[p.Y]-=1;
    } 
    int k=0;
    ld la=0;
    for(auto p:m){
        assert(k>=0);
       if(k>0)ans+=p.X-la;
       k+=p.Y;
       la=p.X;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(30);
    int n,m;
    cin>>n>>m;
    vector<Point<ld> > v(n);
    rep(i,0,n){
        cin>>v[i].x>>v[i].y; 
    }
    rep(i,0,m){
        Point<ld> s,e,nrm;
        cin>>s.x>>s.y>>e.x>>e.y;
        s = e + (s-e).unit()*(ld(1e6));
        nrm=(s-e).normal()*1e-10;
        ld d=polygonCut(allof(v),s,e);
        //d=max(d,polygonCut(allof(v),s+nrm,e+nrm));
        //d=max(d,polygonCut(allof(v),s-nrm,e-nrm));
        cout<<d<<endl;
    }
    return 0;
}