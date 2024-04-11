#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct P
{
    int x,y;
    P():x(0),y(0){}
    P(int a,int b):x(a),y(b){}
    void in() {scanf("%d%d",&x,&y);}
    void out() {printf("??? %d %d\n",x,y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
}p[maxn+5];

ll cross(P a,P b) {return 1ll*a.x*b.y-1ll*a.y*b.x;}

void Madd(P &a,P b) 
{
    a=a+b;
    a.x%=mod;
    a.y%=mod;
}
ll Mcross(P a,P b) {return (1ll*a.x*b.y%mod-1ll*a.y*b.x%mod+2ll*mod)%mod;}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) p[i].in(),p[i].y*=-1;
    rep(i,1,n) p[i+n]=p[i];
    ll S=0;
    rep(i,1,n) S+=cross(p[i],p[i+1]);
    ll s=0,sum=0; P q=p[n];
    int ptr=n;
    while(2ull*(s+cross(p[ptr]-p[ptr-1],p[n+1]-p[ptr]))<1ull*S)
    {
        s+=cross(p[ptr]-p[ptr-1],p[n+1]-p[ptr]);
        sum=(sum+s)%mod;
        ptr--;
        Madd(q,p[ptr]);
    }
    ll ans=0,cnt=0;
    rep(i,n+1,n*2)
    {
        while(2ull*s>=1ull*S)
        {
            sum=(sum-s%mod+mod)%mod;
            s-=cross(p[ptr+1]-p[ptr],p[i]-p[ptr]);
            Madd(q,P(0,0)-p[ptr]);
            ptr++;
        }
        ans=(ans+sum)%mod;
        cnt+=i-ptr-1;
        sum=(sum+Mcross(p[i+1]-p[i],q-P(1ll*p[i].x*(i-ptr)%mod,1ll*p[i].y*(i-ptr)%mod))+mod)%mod;
        s+=cross(p[i+1]-p[i],p[ptr]-p[i]);
        Madd(q,p[i]);
    }
    ll A=cnt%mod*(S%mod)%mod-ans*2%mod+mod;
    printf("%lld",A%mod);
    return 0;
}