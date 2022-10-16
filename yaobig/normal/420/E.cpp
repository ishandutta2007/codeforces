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

P p[maxn+5];

db myacos(db x)
{
    if(x>1.0) return acos(1.0);
    if(x<-1.0) return acos(-1.0);
    return acos(x);
}

int main()
{
    int n,d; scanf("%d%d",&n,&d);
    vector<pair<db,int>> A;
    int cnt=0;
    rep(i,1,n)
    {
        P p; p.in();
        int r; scanf("%d",&r);
        db L=p.norm();
        db alpha=atan2(p.y,p.x);
        for(int i=ceil((L-r-eps)/d);i<=floor((L+r+eps)/d);i++) 
        {
            db a=i*d;
            db theta=myacos((L*L+a*a-r*r)/(2.0*L*a));
            db s1=alpha-theta,s2=alpha+theta;
            if(s1<=-pi) s1+=pi*2;
            if(s2>pi) s2-=pi*2;
            A.pb(mp(s1,-1));
            A.pb(mp(s2,1));
            if(s1>s2) cnt++;
        }
    }
    sort(A.begin(),A.end());
    int ans=0;
    for(auto [s,b]: A)
    {
        cnt-=b;
        chmax(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}