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
const int maxn=200010;;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

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
    return res%Mod;
}
 
ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

ll fac[maxn];

int main()
{
    sync;
    p[0]=inv[0]=1;
    fac[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
        fac[i]=fac[i-1]*10%Mod;
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    
    int n;
    cin>>n;
    ll sum=0;
    ll s;
    for(int i=1;i<n;i++)
    {
        s=(1ll*9*10*2*fac[max(0,n-i-1)]%Mod+1ll*max(0,n-i-1)*9*9*10*fac[max(0,n-i-2)]%Mod+Mod+Mod)%Mod;
        cout<<s<<' ';
    }
    cout<<10<<endl;
    return 0;
}