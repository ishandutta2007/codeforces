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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;



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

ll a[maxn];
ll b[maxn];
ll dp[maxn][2];

int main()
{
    sync
    int n;
    ll k;
    cin>>n>>k;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    dp[0][0]=0;
    dp[0][1]=1;
    dp[1][0]=k-1;
    dp[1][1]=k-2;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=1ll*(k-1)*dp[i-1][1]%Mod;
        dp[i][1]=(1ll*dp[i-1][0]+1ll*(k-2)*dp[i-1][1])%Mod;
    }
    int m=0;
    for(int i=2;i<=n;i+=2)
    {
        b[++m]=a[i];
    }
    n=(n+1)/2;
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i*2-1];
    }
    
    int f=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=-1&&a[i]==a[i-1])
            f=1;
    }
    for(int i=2;i<=m;i++)
    {
        if(b[i]!=-1&&b[i]==b[i-1])
            f=1;
    }
    if(f)
    {
        cout<<0<<endl;
        return 0;
    }
    
    int L,R;
    L=1;
    ll ans=1ll;
    while(L<=n)
    {
        while(L<=n&&a[L]!=-1)
        {
            L++;
        }
        if(L>n)
            break;
        R=L;
        while(R<=n&&a[R]==-1)
        {
            R++;
        }
        R--;
        if(L==1)
        {
            if(R==n)
            {
                ans=(ans*(1ll*k*ksm(k-1,(R-L))%Mod)%Mod+Mod)%Mod;
            }
            else
            {
                ans=(ans*(1ll*(k-1)*dp[R-L][1]%Mod+dp[R-L][0])%Mod)%Mod;
            }
        }
        else if(R==n)
        {
            ans=(ans*(1ll*(k-1)*dp[R-L][1]%Mod+dp[R-L][0])%Mod)%Mod;
        }
        else
        {
            if(a[L-1]==a[R+1])
                ans=(ans*dp[R-L+1][0])%Mod;
            else
                ans=(ans*dp[R-L+1][1])%Mod;
        }
        L=R+1;
    }
    
    
    n=m;
    ll as=ans;

    ans=1ll;
    
    for(int i=1;i<=n;i++)
    {
        a[i]=b[i];
//        cout<<a[i]<<' ';
    }
//    cout<<endl;
    L=1;
    while(L<=n)
    {
        while(L<=n&&a[L]!=-1)
        {
            L++;
        }
        if(L>n)
            break;
        R=L;
        while(R<=n&&a[R]==-1)
        {
            R++;
        }
        R--;
        if(L==1)
        {
            if(R==n)
            {
                ans=(ans*(1ll*k*ksm(k-1,(R-L))%Mod)%Mod+Mod)%Mod;
            }
            else
            {
                ans=(ans*(1ll*(k-1)*dp[R-L][1]%Mod+dp[R-L][0])%Mod)%Mod;
            }
        }
        else if(R==n)
        {
            ans=(ans*(1ll*(k-1)*dp[R-L][1]%Mod+dp[R-L][0])%Mod)%Mod;
        }
        else
        {
            if(a[L-1]==a[R+1])
                ans=(ans*dp[R-L+1][0])%Mod;
            else
                ans=(ans*dp[R-L+1][1])%Mod;
        }
        L=R+1;
    }
//    cout<<as<<' '<<ans<<endl;
    
    cout<<((1ll*as*ans)%Mod+Mod)%Mod<<endl;
    
    return 0;
}