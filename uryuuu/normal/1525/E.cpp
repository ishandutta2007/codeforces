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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=50005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll p[maxn],inv[maxn];
//inv[0]=inv[1]=1;
//inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;          // 
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
 
ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

int a[maxn][22];

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
    
    sync;
    int n,m;
    cin>>n>>m;
    int j;
    ll sum=1ll;
    for(int i=1;i<=n;i++)
    {
        sum=1ll*sum*i%Mod;
    }
    ll ans=0ll;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cin>>a[j][i];
    }
    
    
    int lv;
    ll s=1ll;
    for(int i=1;i<=m;i++)
    {
        lv=n;
        sort(a[i]+1,a[i]+n+1);
//        for(j=1;j<=n;j++)
//            cout<<a[i][j]<<' ';
        s=1ll;
        for(j=1;j<=n;j++)
        {
            if(a[i][j]<=j)
            {
                s=0;
                break;
            }
            s=1ll*s*(a[i][j]-j)%Mod;
        }
        ans+=sum-s;
//        cout<<sum-s<<endl;
    }
    ans=ans%Mod;
//    cout<<ans<<endl;
    ans=ans*ksm(sum,Mod-2)%Mod;
    cout<<(ans%Mod+Mod)%Mod<<endl;
    
    return 0;
}