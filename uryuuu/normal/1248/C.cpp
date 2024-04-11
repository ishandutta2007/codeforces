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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn=100005;
const ll Mod=1000000007;

ll dp[maxn];
ll p[maxn],inv[maxn];

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
    return res;
}
 
 
ll C(int n,int m)
{
    if(m==0)
        return 1;
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

int main()
{
    sync;
    int n,m;
    p[0]=inv[0]=1;
    for(int i=1;i<maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
        inv[i]=ksm(p[i],Mod-2);
    }
    cin>>n>>m;
    ll s=0;
    for(int i=1;i<=m/2;i++)
    {
        s=(s+C(m-i,i)+Mod)%Mod;
    }
    for(int i=1;i<=n/2;i++)
    {
        s=(s+C(n-i,i)+Mod)%Mod;
    }
    s=(s*2+Mod+2)%Mod;
    cout<<s<<endl;
    
    return 0;
}