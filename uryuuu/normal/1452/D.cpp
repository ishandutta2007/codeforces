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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

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

ll dp[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    dp[0]=1ll;
    ll pre1=0;
    ll pre0=1ll;
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            dp[i]=(1ll*dp[i]+pre0)%Mod;
            pre1=(1ll*pre1+dp[i])%Mod;
        }
        else
        {
            dp[i]=(1ll*dp[i]+pre1)%Mod;
            pre0=(1ll*pre0+dp[i])%Mod;
        }
    }
    ll p=ksm(2,n);
    ll ans=1ll*dp[n]*ksm(p,Mod-2)%Mod;
    cout<<(ans%Mod+Mod)%Mod<<endl;
    
    return 0;
}