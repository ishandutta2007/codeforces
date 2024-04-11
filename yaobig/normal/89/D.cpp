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

int Ax,Ay,Az,vx,vy,vz,R;

db cal(ll x,ll y,ll z,ll C)
{
    ll X=Ax-x,Y=Ay-y,Z=Az-z;
    ll a=vx*vx+vy*vy+vz*vz;
    ll b=2*(vx*X+vy*Y+vz*Z);
    ll c=X*X+Y*Y+Z*Z-C*C;
    if(b*b-4*a*c<0) return 1e100;
    db delta=sqrt(b*b-4*a*c);
    db t1=(-b-delta)/(a*2);
    db t2=(-b+delta)/(a*2);
    assert(t2>=t1);
    if(t1>=0) return t1;
    if(t2>=0) return t2;
    return 1e100;
}

int main()
{
    scanf("%d%d%d%d%d%d%d",&Ax,&Ay,&Az,&vx,&vy,&vz,&R);
    int n; scanf("%d",&n);
    db ans=1e100;
    rep(i,1,n)
    {
        int ox,oy,oz,r; scanf("%d%d%d%d",&ox,&oy,&oz,&r);
        chmin(ans,cal(ox,oy,oz,r+R));
        int m; scanf("%d",&m);
        while(m--)
        {
            int px,py,pz; scanf("%d%d%d",&px,&py,&pz);
            chmin(ans,cal(ox+px,oy+py,oz+pz,R));
        }
    }
    if(ans>1e99) puts("-1");
    else printf("%.10f\n",ans);
    return 0;
}