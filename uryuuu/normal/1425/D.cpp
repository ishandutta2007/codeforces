#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define flush fflush(stdout)
using namespace std;
typedef pair<int,ll> pii;
const double pi=acos(-1);
const int maxn=2010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
//#define int long long

ll p[maxn],inv[maxn];
//inv[0]=inv[1]=1;
//inv[i]=1LL*(Mod-Mod/i)*inv[Mod%i]%Mod;          // 
//S(n,m)=S(n,m1)+C(n m),S(n,m)=2S(n1,m)C(n1 m)
ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}

ll C(ll n,ll m)
{
    if(n==0&&m==0)
        return 1ll;
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

ll sz[maxn],mp[maxn][maxn];
struct node
{
    int x,y;
    ll val;
}a[maxn];


int pre[maxn][maxn],g[maxn][maxn];

int main()
{
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
//        inv[i]=ksm(p[i],Mod-2);
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].val);
        g[a[i].x][a[i].y]=1;
    }


    for(int i=1;i<=1010;i++)
        for(int j=1;j<=1010;j++)
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+g[i][j];
    for(int i=1;i<=n;i++)
        sz[i]++;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        mp[i][i]=1;
        for(int j=i+1;j<=n;j++)
        {
            if(max(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y))<=r)
            {
                sz[i]++;
                sz[j]++;
                mp[i][j]=mp[j][i]=1;
            }
        }
    }
    ll sum=C(n,m);
    ll s=0;
    ll d;
    ll q;
    ll f=0;
    ll L,R;

    ll zz;
    ll h;
    int xL,xR,yU,yD,Lx,Rx,Uy,Dy;


    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            f=0;
            d=0;
            xL=min(a[i].x,a[j].x);
            xR=max(a[i].x,a[j].x);
            yU=min(a[i].y,a[j].y);
            yD=max(a[i].y,a[j].y);
            Rx=min(1005,xL+r);
            Lx=max(1,xR-r);
            Uy=max(1,yD-r);
            Dy=min(1005,yU+r);
            //cout<<i<<' '<<j<<' '<<Lx<<' '<<yD<<' '<<Uy<<' '<<Rx<<' '<<' '<<Dy<<endl;

            if(Lx<=Rx&&Uy<=Dy)
            {
                f=pre[Rx][Dy]-pre[Rx][Uy-1]-pre[Lx-1][Dy]+pre[Lx-1][Uy-1];
            }
            //cout<<i<<' '<<j<<' '<<f<<endl;

            if(n-f>=m)
                q=C(n-f,m);
            else
                q=0;
            d=1ll*d+(1ll*sum-q);
            h=n-f;

            zz=sz[i]-f;
            if(h-zz>=m)
                q=C(h-zz,m);
            else
                q=0;
            L=q;

            zz=sz[j]-f;
            if(h-zz>=m)
                q=C(h-zz,m);
            else
                q=0;
            R=q;

            zz=sz[j]-f+sz[i]-f;
            if(h-zz>=m)
                q=C(h-zz,m);
            else
                q=0;
            
            if(h<m)
                s=0;
            else
                s=C(h,m);
            s=1ll*s-(L+R-q)+d;
            s=1ll*s%Mod;

            // cout<<i<<' '<<j<<' '<<L<<' '<<R<<' '<<' '<<q<<' '<<s<<endl;
            ans=(1ll*ans+2ll*s*(a[i].val*a[j].val%Mod))%Mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        d=n-sz[i];
        if(d<m)
            s=0;
        else
            s=C(d,m);
        s=1ll*sum-s;
        ans=(1ll*ans+1ll*s*(a[i].val*a[i].val%Mod)%Mod)%Mod;
    }
    printf("%lld\n",(ans%Mod+Mod)%Mod);
    return 0;
}