#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double db;

const db eps=1e-8;
const db pi=acos(-1.0);
int sgn(db x) {return (x>eps)-(x<-eps);}
int cmp(db x,db y) {return sgn(x-y);}

struct P
{
    db x,y;
    P():x(0),y(0){}
    P(db a,db b):x(a),y(b){}
    void in() {int a,b; scanf("%d%d",&a,&b); x=a; y=b;}
    //void out() {printf("? %.6f %.6f\n",x,y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
    db norm() {return sqrt(x*x+y*y);}
    db norm2() {return x*x+y*y;}
};
typedef vector<P> vp;

db dot(P a,P b) {return a.x*b.x+a.y*b.y;}
db cross(P a,P b) {return a.x*b.y-a.y*b.x;}

db area(vp a)
{
    P a0=a[0];
    for(auto &p: a) p=p-a0;
    int n=a.size();
    db sum=0;
    rep(i,0,n-1) sum+=cross(a[i],a[(i+1)%n]);
    return sum/2;
}
P center(vp a)
{
    P a0=a[0];
    for(auto &p: a) p=p-a0;
	int n=a.size();
    P ans(0,0);
    db S=area(a);
    if(sgn(S)==0) return ans;
    rep(i,0,n-1) ans=ans+(a[i]+a[(i+1)%n])*(cross(a[i],a[(i+1)%n])/(S*6));
    return ans+a0;
}

db getang(db x)
{
    while(x<0) x+=pi*2;
    while(x>=pi*2) x-=pi*2;
    return x;
}

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    vector<P> A(n);
    rep(i,0,n-1) A[i].in();
    P c=center(A);
    vector<db> ang(n+1),len(n+1);
    rep(i,0,n-1)
    {
        P p=A[i]-c;
        ang[i+1]=getang(atan2(p.y,p.x));
        len[i+1]=p.norm();
    }
    db theta=pi/2;
    int pin=1^2;

    auto getp=[&](int i){
        db s=getang(ang[i]-theta+pi/2);
        return c+P(cos(s),sin(s))*len[i];
    };

    while(q--)
    {
        int op; scanf("%d",&op);
        if(op==1)
        {
            int f,t; scanf("%d%d",&f,&t);
            pin^=f;
            P p=getp(pin);
            theta=ang[pin];
            c=p+P(0,-1)*len[pin];
            pin^=t;
        }
        else
        {
            int id; scanf("%d",&id);
            P p=getp(id);
            printf("%.10f %.10f\n",(double)p.x,(double)p.y);
        }   
    }
    return 0;
}