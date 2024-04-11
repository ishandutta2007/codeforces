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
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod = 998244353;
//#define int long long

int a[maxn];
ll dp[maxn][210][2];   // 0 <= 1>

 int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[1]!=-1)
    {
        dp[1][a[1]][1]=1ll;
    }
    else
    {
        for(int i=1;i<=200;i++)
        {
            dp[1][i][1]=1ll;
        }
    }
    
    
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=-1)
        {
            for(int j=1;j<a[i];j++)
            {
                dp[i][a[i]][1]=(1ll*dp[i][a[i]][1]+dp[i-1][j][0]+dp[i-1][j][1])%Mod;
            }
            dp[i][a[i]][0]=(1ll*dp[i][a[i]][0]+dp[i-1][a[i]][0]+dp[i-1][a[i]][1])%Mod;
            for(int j=a[i]+1;j<=200;j++)
            {
                dp[i][a[i]][0]=(1ll*dp[i][a[i]][0]+dp[i-1][j][0])%Mod;
            }
        }
        else
        {
            for(int j=1;j<=200;j++)
            {
                dp[i][j][1]=(1ll*dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i][j-1][1])%Mod;
            }
            
            for(int j=200;j>=1;j--)
            {
                dp[i][j][0]=(1ll*dp[i-1][j][0]+dp[i][j+1][0])%Mod;
            }
            
            for(int j=200;j>=1;j--)
            {
                dp[i][j][0]=(1ll*dp[i-1][j][1]+dp[i][j][0])%Mod;
            }
        }
    }
    
    ll ans=0;
    if(a[n]==-1)
    {
        for(int i=1;i<=200;i++)
        {
            ans=(1ll*ans+dp[n][i][0])%Mod;
        }
    }
    else
        ans=(1ll*dp[n][a[n]][0])%Mod;
    cout<<(ans%Mod+Mod)%Mod<<endl;
    
    return 0;
}