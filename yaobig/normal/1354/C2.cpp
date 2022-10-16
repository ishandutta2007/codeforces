#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
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
int sgn(db x) {return (x>eps)-(x<-eps);}
int cmp(db x,db y) {return sgn(x-y);}

const db pi=acos(-1.0);
db theta;
int n; 

db myacos(db x)
{
    if(x>1.0) return acos(1.0);
    if(x<-1.0) return acos(-1.0);
    return acos(x);
}

bool check(db X,db R)
{
    db alpha=myacos(X/R);
    rep(i,0,n-1)
    {
        db beta=alpha+theta*i;
        db x=R*cos(beta);
        db y=R*sin(beta);
        if(cmp(fabs(x),X)>0 || cmp(fabs(y),X)>0) return 0;
    }
    return 1;
}

db lb(db l,db r,db R)
{
    rep(t,1,100)
    {
        db mid=(l+r)/2;
        if(check(mid,R)) r=mid;
        else l=mid;
    }
    return (l+r)/2;
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        scanf("%d",&n);
        n*=2;
        theta=pi*2/n;
        db r=0.5/sin(theta/2.0);
        db ans=lb(0.0001,r,r);
        printf("%.10f\n",ans*2.0);
    }
    return 0;
}