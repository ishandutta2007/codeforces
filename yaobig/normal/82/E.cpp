#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

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
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
    bool operator == (const P &a) {return cmp(x,a.x)==0 && cmp(y,a.y)==0;}
    bool operator < (const P &a) {return cmp(x,a.x)==0 ? cmp(y,a.y)<0 : x < a.x;}
    db len() {return sqrt(x*x+y*y);}
    db len2() {return x*x+y*y;}
    P unit() {return *this/len();}

    db dot(const P b) {return x*b.x+y*b.y;}
    db cross(const P b) {return x*b.y-y*b.x;}
    // when you use the following two functions, say to test if vectors are collinear,
    // you should make sure that the coordinates are integers. Otherwise precision error
    // might be enlarged by the norm.

    db unitdot(P b) {return unit().dot(b.unit());}
    db unitcross(P b) {return unit().cross(b.unit());}

};
typedef vector<P> vp;
vp A[maxn+5];

struct L
{
    P a,b; 
    db angle;
    void get_angle() {angle = atan2(b.y-a.y,b.x-a.x);}
    L(){}
    L(P x,P y):a(x),b(y){get_angle();}
};

db area(vp a)
{
    if(a.size()==0) return 0;
    P a0=a[0];
    for(auto &p: a) p=p-a0;
    int n=a.size();
    db sum=0;
    rep(i,0,n-1) sum+=a[i].cross(a[(i+1)%n]);
    return sum/2;
}
// Note that the resulting convex hull might have colinear points
vp HPI(vector<L> l)
{
    // LHS <-> inside (i.e. counter clockwise)
    auto onleft = [](L l,P p) {return (l.b-l.a).cross(p-l.a)>eps;};
    auto onright = [](L l,P p) {return (l.b-l.a).cross(p-l.a)<-eps;};
    
    int n=l.size();
    vector<L> q(n);
    sort(l.begin(),l.end(),[&](L s1,L s2) {
        // sort according to the angle.
        if(cmp(s1.angle,s2.angle)!=0) return s1.angle<s2.angle;
        return onleft(s2,s1.b);
    });
    int tmp=1;
    rep(i,1,n-1) if(cmp(l[i].angle,l[tmp-1].angle)!=0) l[tmp++]=l[i];
    n=tmp;
    q[0]=l[0];q[1]=l[1];

    // Note that we assume l1 and l2 are not parallel.
    auto lcross = [](L l1,L l2) {
        db s1=(l1.a-l2.a).cross(l2.b-l2.a);
        db s2=(l1.b-l2.a).cross(l2.b-l2.a);
        if(s1-s2==0) assert(0);
        return (l1.b*s1-l1.a*s2)/(s1-s2);
    };

    int front=0,rear=1;
    rep(i,2,n-1)
    {
        if(front<rear && sgn((q[rear].b-q[rear].a).cross(q[rear-1].b-q[rear-1].a))==0) return vp{};
        while(front<rear && onright(l[i],lcross(q[rear],q[rear-1]))) rear--;
        while(front<rear && onright(l[i],lcross(q[front],q[front+1]))) front++;
        q[++rear]=l[i];
    }
    if(front<rear && sgn((q[rear].b-q[rear].a).cross(q[rear-1].b-q[rear-1].a))==0) return vp{};
    while(front<rear && onright(q[front],lcross(q[rear],q[rear-1]))) rear--;
    while(front<rear && onright(q[rear],lcross(q[front],q[front+1]))) front++;
    if(front==rear) return vp{};
    vp res;
    rep(i,front,rear-1) res.pb(lcross(q[i],q[i+1]));
    if(rear-front>1) res.pb(lcross(q[front],q[rear]));
    return res;
}

int main()
{
    int n,h,f; scanf("%d%d%d",&n,&h,&f);
    rep(i,1,n)
    {
        int l,r; scanf("%d%d",&l,&r);
        A[i].pb(P(r,h));
        A[i].pb(P(l,h));
        A[i].pb(P((db)l/(f-h)*(f+h),-h));
        A[i].pb(P((db)r/(f-h)*(f+h),-h));
        A[i+n].pb(P(l,-h));
        A[i+n].pb(P(r,-h));
        A[i+n].pb(P((db)r/(f-h)*(f+h),h));
        A[i+n].pb(P((db)l/(f-h)*(f+h),h));
    }
    db ans=0;
    rep(i,1,n*2) ans+=area(A[i]);
    rep(i,1,n) rep(j,n+1,n*2) 
    {
        vector<L> l;
        rep(k,0,3) l.pb(L(A[i][k],A[i][(k+1)%4]));
        rep(k,0,3) l.pb(L(A[j][k],A[j][(k+1)%4]));
        vp B=HPI(l);
        ans-=area(B);
    }
    printf("%.10f\n",ans);
    return 0;
}