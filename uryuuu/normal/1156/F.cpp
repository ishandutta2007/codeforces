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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=5010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;
ll p[maxn][maxn],inv[maxn],sum[maxn];
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
 
ll v[maxn],a[maxn];

int main()
{
    sync;
    inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        inv[i]=ksm(i,Mod-2);
    }
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[a[i]]++;
    }
    
    for(int i=1;i<=n;i++)         // 
    {
        p[1][i]=v[i]*inv[n]%Mod;
        for(int len=2;n-len+1>0;len++)
        {
            p[len][i]=sum[len-1]*v[i]%Mod*inv[n-len+1]%Mod;
        }
        for(int len=1;len<=n;len++)
        {
            sum[len]=(sum[len]+p[len][i])%Mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)   //
    {
        if(v[i]>=2)
        {
            for(int len=1;len<n;len++)
            {
                ans=(ans+p[len][i]*(v[i]-1)%Mod*inv[n-len]%Mod)%Mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}