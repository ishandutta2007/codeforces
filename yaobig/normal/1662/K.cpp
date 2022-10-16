#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(char c) {return "'" + string(1,c) + "'";}
string to_string(bool x) {return x ? "true" : "false";}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

const db pi = acos(-1.0);
const db eps = 1e-9;
int sgn(db x) {return (x>eps)-(x<-eps);}
int cmp(db x,db y) {return sgn(x-y);}
db sqr(db x) {return x*x;}

struct P
{
    db x,y;
    P():x(0),y(0){}
    P(db a,db b):x(a),y(b){}
    void in() {scanf("%lf%lf",&x,&y);}
    void out() {printf("%.10f %.10f\n",x,y);}
    P operator +(P a) const {return P(x+a.x,y+a.y);}
    P operator -(P a) const {return P(x-a.x,y-a.y);}
    P operator *(db a) const {return P(x*a,y*a);}
    P operator /(db a) const {return P(x/a,y/a);}
    bool operator == (P a) const {return cmp(x,a.x)==0 && cmp(y,a.y)==0;}
    bool operator < (P a) const {return cmp(x,a.x)==0?cmp(y,a.y)<0:x<a.x;}
    db len() const {return sqrt(x*x+y*y);}
    db len2() const {return x*x+y*y;}
    P unit() const {return *this/len();}

    db dot(P b) const {return x*b.x+y*b.y;}
    db cross(P b) const {return x*b.y-y*b.x;}
    // when you use the following two functions, say to test if vectors are collinear, you should make sure that the coordinates are integers. Otherwise precision error might be enlarged by the norm.

    db dis_to(P a,P b) const {return (*this-a).cross((b-a).unit());} // signed.

    P rotate(db theta) const
    {
        P a(cos(theta),sin(theta));
        return P(x*a.x-y*a.y, x*a.y+y*a.x);
    }
    void deb() {debug(x,y);}
};


db fermat(P a,P b,P c)
{
    if(a==b) return (a-c).len();
    if(a==c) return (a-b).len();
    if(b==c) return (a-b).len();
    
    vector<pair<db,P>> vec;
    vec.pb({(b-c).len(),a});
    vec.pb({(a-c).len(),b});
    vec.pb({(a-b).len(),c});
    
    if(vec[0].FI<vec[1].FI) swap(vec[0], vec[1]);
    if(vec[0].FI<vec[2].FI) swap(vec[0], vec[2]);
    
    a = vec[0].SE;
    b = vec[1].SE;
    c = vec[2].SE;
    
    
    if(sgn( b.dis_to(a,c) ) < 0) swap(b,c);
    // a.deb();
    // b.deb();
    // c.deb();
    P cp = a + (c-a).rotate(pi/3);
    db res = (b-cp).len();
    if(a.dis_to(b,cp) > eps) res = (a-b).len() + (a-c).len();
    // debug(res);
    return res;
}


int main()
{
    // P A(0,0), B(2,0), C(1,sqrt(3));
    // fermat(A,B,C);

    using node = array<db,2>;
    vector<node> a(3);
    for(auto &[x,y]: a) scanf("%lf%lf",&x,&y);
    
    db mx[2],mn[2];
    rep(j,0,1)
    {
        vector<db> vec;
        rep(i,0,2) vec.pb(a[i][j]);
        mx[j] = *max_element(all(vec));
        mn[j] = *min_element(all(vec));
    }
    auto getP = [&](node a) {return P(a[0],a[1]);};
    function<db(int,node)> ts = [&](int dep,node p) {
        if(dep==2)
        {
            db res = 0;
            chmax(res, fermat(getP(p), getP(a[0]), getP(a[1])));
            chmax(res, fermat(getP(p), getP(a[1]), getP(a[2])));
            chmax(res, fermat(getP(p), getP(a[2]), getP(a[0])));
            return res;
        }
        db l = mn[dep], r = mx[dep];
        rep(_,1,60)
        {
            db m1 = (l*2+r)/3;
            db m2 = (l+r*2)/3;
            p[dep] = m1;
            db res1 = ts(dep+1,p);
            p[dep] = m2;
            db res2 = ts(dep+1,p);
            if(res1<res2) r = m2;
            else l = m1;
        }
        p[dep] = (l+r)/2;
        return ts(dep+1,p);
    };
    node p{};
    db ans = ts(0,p);
    printf("%.10f\n",ans);
    return 0;
}