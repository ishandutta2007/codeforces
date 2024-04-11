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
typedef double db;

const db eps=1e-7;
const db pi=acos(-1.0);
int sgn(db x) {return (x>eps)-(x<-eps);}
int cmp(db x,db y) {return sgn(x-y);}

struct P
{
    db x,y;
    P():x(0),y(0){}
    P(db a,db b):x(a),y(b){}
    void in() {scanf("%lf%lf",&x,&y);}
    void out() {printf("? %.6f %.6f\n",x,y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
    db norm() {return sqrt(x*x+y*y);}
    db norm2() {return x*x+y*y;}
};

db dot(P a,P b) {return a.x*b.x+a.y*b.y;}
db cross(P a,P b) {return a.x*b.y-a.y*b.x;}


vector<P> Graham(vector<P> a)
{
    int n=a.size(),k=0;
    if(n<=2) return vector<P>{};
    rep(i,0,n-1) if(a[i].y<a[k].y || (a[i].y==a[k].y && a[i].x<a[k].x)) k=i;
    swap(a[0],a[k]);
    sort(a.begin()+1,a.end(),[a0=a[0]](P s,P t)
    {
        db z=cross(s-a0,t-a0);
        if(sgn(z)==1 || (sgn(z)==0 && cmp((s-a0).norm(),(t-a0).norm())<0)) return 1;
        return 0;
    });
    vector<P> p(n);
    int top=1;
    p[0]=a[0];
    p[1]=a[1];
    rep(i,2,n-1)
    {
        while(top && sgn(cross(p[top]-p[top-1],a[i]-p[top-1]))<=0) top--;
        p[++top]=a[i];
    }
    p.resize(top+1);
    return p;
}

bool on_seg(P p,P s,P t)
{
    return sgn(cross(p-s,t-s))==0 && sgn(dot(p-s,p-t))<=0;
}
P proj_on_line(P p,P s,P t)
{
    db r=dot(p-s,t-s)/dot(t-s,t-s);
    return s+(t-s)*r;
}

bool check(P p,P q,vector<P>&A,db l)
{
    db s=atan2((q-p).y,(q-p).x);
    db pos=0,neg=0;
    bool mark=0;
    for(auto &q: A) if(cmp((q-p).norm(),l)==0) 
    {
        db t=atan2((q-p).y,(q-p).x);
        t-=s;
        while(t<=-pi) t+=2*pi;
        while(t>pi) t-=2*pi;
        if(sgn(t)==0) continue;
        if(cmp(t,pi)==0 || cmp(t,-pi)==0) {mark=1; continue;}
        if(sgn(t)>0) chmax(pos,t);
        else chmax(neg,-t);
    }
    if(cmp(pos+neg,pi)>0) return 1;
    if(cmp(pos+neg,pi)==0) return mark;
    return 0;
}

int main()
{
    int n; scanf("%d",&n);
    vector<P> A(n);
    rep(i,0,n-1) A[i].in();
    auto convA=Graham(A);
    if(convA.size()<3) return puts("-1"),0;
    db ans=-1;
    rep(i,0,n-1) 
    {
        P &p=A[i];
        db d=1e10,D=0;
        rep(j,0,n-1) if(i!=j) 
        {
            chmin(d,(A[j]-p).norm());
            chmax(D,(A[j]-p).norm());
        }
        db R=sqrt(d*D);
        vector<P> B; B.pb(p);
        rep(j,0,n-1) if(i!=j) B.pb(p+(A[j]-p)*(R*R/(A[j]-p).norm2()));
        auto convB=Graham(B);
        int N=convB.size();
        rep(j,0,N-1)
        {
            P &a=convB[j];
            P &b=convB[(j+1)%N];
            if(on_seg(p,a,b)==0)
            {
                P o=proj_on_line(p,a,b);
                o=p+(o-p)*(R*R/(o-p).norm2()/2);
                if(check(o,p,A,(o-p).norm())==1) chmax(ans,(o-p).norm());
            }
        }
    }
    if(ans<0) puts("-1");
    else printf("%.10f\n",ans);
    return 0;
}