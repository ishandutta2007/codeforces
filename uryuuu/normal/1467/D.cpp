#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
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
const int maxn=5010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


ll dp[maxn][maxn],a[maxn];
ll c[maxn];

int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[0][i]=1ll;
    }
    
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i>1)
                dp[j][i]=1ll*(dp[j][i]+dp[j-1][i-1])%Mod;
            if(i<n)
                dp[j][i]=1ll*(dp[j][i]+dp[j-1][i+1])%Mod;
//            c[i]=(1ll*c[i]+dp[j][i])%Mod;
        }
    }
    
//    for(int j=0;j<=k;j++)
//    {
//        for(int i=2;i<n;i++)
//        {
//            dp[j][i]=max(dp[j][i],dp[k-j][i]);
////            dp[j][i]=2ll*dp[j][i]%Mod;
//        }
//    }
    
    for(int j=0;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(j<=k-j)
            dp[j][i]=1ll*(dp[j][i]*dp[k-j][i])%Mod;
            else
                dp[j][i]=1ll*(dp[k-j][i])%Mod;
//            if(j==k-j&&i!=1&&i!=n)
//                dp[j][i]=2ll*dp[j][i]%Mod;
//            cout<<dp[j][i]<<' ';
            c[i]=(1ll*c[i]+dp[j][i])%Mod;
        }
//        cout<<endl;
    }
    

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(1ll*ans+a[i]*c[i])%Mod;
    }
//    cout<<ans<<endl;
    
    ll pos,x;
    while(q--)
    {
        cin>>pos>>x;
        ans=(1ll*ans+(1ll*x-a[pos])*c[pos])%Mod;
        a[pos]=x;
        ans=(1ll*ans%Mod+Mod)%Mod;
        cout<<ans<<endl;
    }
    
    
}