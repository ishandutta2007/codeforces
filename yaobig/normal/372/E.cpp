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

struct P
{
    db x,y,k;
    P():x(0),y(0){}
    P(db a,db b):x(a),y(b){}
    void in() {scanf("%lf%lf",&x,&y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
    db norm2() {return x*x+y*y;}
}p[maxn+5];

int main()
{
    int n; scanf("%d",&n); 
    rep(i,1,n)
    {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        p[i]=P((db)a/b,(db)c/d);
        p[i]=p[i]/p[i].norm2();
    }
    vector<P> pt;
    rep(i,1,n) rep(j,1,i-1)
    {
        P mid=(p[i]+p[j])/2,tmp=p[i]-p[j];
        mid.k=sgn(tmp.x)==0?1e100:tmp.y/tmp.x;
        pt.pb(mid);
    }
    sort(pt.begin(),pt.end(),[](P a,P b)
        {
            if(cmp(a.x,b.x)) return cmp(a.x,b.x)<0;
            if(cmp(a.y,b.y)) return cmp(a.y,b.y)<0;
            return a.k<b.k;
        }
    );
    int N=pt.size();
    ll ans=0;
    for(int l=0,r;l<N;l=r)
    {
        for(r=l;r<N && cmp(pt[r].x,pt[l].x)==0 && cmp(pt[r].y,pt[l].y)==0;r++);
        int c=2,ways=1;
        rep(i,l+1,r)
        {
            if(i<r && cmp(pt[i].k,pt[i-1].k)==0) c++;
            else ways=1ll*ways*c%mod,c=2;
        }
        ans=(ans+ways-1-(r-l)+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}