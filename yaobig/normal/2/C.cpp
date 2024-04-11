#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

const db eps=1e-10;
const db pi=acos(-1.0);
int sgn(db x) {return (x>eps)-(x<-eps);}
int cmp(db x,db y) {return sgn(x-y);}

struct P
{
    db x,y;
    P():x(0),y(0){}
    P(db a,db b):x(a),y(b){}
    void in() {scanf("%lf%lf",&x,&y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
    db norm() {return sqrt(x*x+y*y);}
};
db dot(P a,P b) {return a.x*b.x+a.y*b.y;}
db cross(P a,P b) {return a.x*b.y-a.y*b.x;}

P rotate_point(P a,db sita)
{
    db x=a.x,y=a.y;
    return P(x*cos(sita)-y*sin(sita),x*sin(sita)+y*cos(sita));
}

struct L
{
    P a,b;
    L(){}
    L(P x,P y):a(x),b(y){}
};

L getmidline(P a,P b)
{
    P c=(a+b)/2.0;
    P v=rotate_point(b-a,pi/2);
    return L(c,c+v);
}
bool l_cross(L l1,L l2,P &a)
{
    if(!sgn(cross(l1.a-l1.b,l2.a-l2.b))) return 0;
    db s1=cross(l1.a-l2.a,l2.b-l2.a);
    db s2=cross(l1.b-l2.a,l2.b-l2.a);
    a=(l1.b*s1-l1.a*s2)/(s1-s2);
    return 1;
}

void getcircle(P o1,db r1,P o2,db r2,P &o,db &r)
{
    P v=o2-o1;
    P a=o1+v*(r1/(r1+r2));
    P b=o1+v*(r1/(r1-r2));
    r=(a-b).norm()/2.0;
    o=(a+b)/2.0;
}

db myacos(db x)
{
    if(x>1.0) return acos(1.0);
    if(x<-1.0) return acos(-1.0);
    return acos(x);
}

int main()
{
    vector<P> o(3);
    vector<db> r(3);
    rep(i,0,2) o[i].in(), scanf("%lf",&r[i]);
    if(r[0]==r[1] && r[0]==r[2])
    {
        if(sgn(cross(o[2]-o[0],o[1]-o[0]))==0) return 0;
        L l1=getmidline(o[0],o[1]);
        L l2=getmidline(o[0],o[2]);
        P c;
        assert(l_cross(l1,l2,c));
        printf("%.5f %.5f\n",c.x,c.y);
        return 0;
    }
    P o1,o2; db r1,r2;
    if(r[0]!=r[1] && r[0]!=r[2]) getcircle(o[0],r[0],o[1],r[1],o1,r1),getcircle(o[0],r[0],o[2],r[2],o2,r2);
    if(r[1]!=r[0] && r[1]!=r[2]) getcircle(o[1],r[1],o[0],r[0],o1,r1),getcircle(o[1],r[1],o[2],r[2],o2,r2);
    if(r[2]!=r[0] && r[2]!=r[1]) getcircle(o[2],r[2],o[0],r[0],o1,r1),getcircle(o[2],r[2],o[1],r[1],o2,r2);
    if(cmp(r1+r2,(o1-o2).norm())<0) return 0;
    if(cmp(r1-r2,(o1-o2).norm())>0) return 0;
    if(cmp(r2-r1,(o1-o2).norm())>0) return 0;
    db c=(o2-o1).norm();
    db theta=myacos((c*c+r1*r1-r2*r2)/(2.0*r1*c));
    P v=(o2-o1)/c;
    P p1=o1+rotate_point(v,theta)*r1;
    P p2=o1+rotate_point(v,-theta)*r1;
    if((p1-o[0]).norm()<(p2-o[0]).norm()) printf("%.5f %.5f\n",p1.x,p1.y);
    else printf("%.5f %.5f\n",p2.x,p2.y);
    return 0;
}