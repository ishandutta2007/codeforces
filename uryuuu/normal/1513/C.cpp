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
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
   
ll dp[10];
ll pd[10];
ll d[10][maxn];

int main()
{
    sync;
    int t;
    
    ll ans=0;
    for(int k=0;k<=9;k++)
    {
        mm(dp);
        dp[k]=1ll;
        int j;
        for(int i=1;i<=200000;i++)
        {
            mm(pd);
            for(j=1;j<=9;j++)
                pd[j]=dp[j-1];
            pd[1]=(pd[1]+dp[9])%Mod;
            pd[0]=dp[9];
            for(j=0;j<=9;j++)
                dp[j]=pd[j];
            
            ans=0;
            for(int i=0;i<=9;i++)
            {
                ans=(ans+dp[i])%Mod;
            }
            d[k][i]=ans;
        }
    }
    
    cin>>t;
    while(t--)
    {
        ll x;
        int m;
        cin>>x>>m;
        mm(dp);
        while(x)
        {
            dp[x%10]++;
            x/=10;
        }
        ll ans=0;
        for(int i=0;i<10;i++)
        {
            ans=(ans+1ll*dp[i]*d[i][m]%Mod)%Mod;
        }
        cout<<(ans%Mod+Mod)%Mod<<endl;
    }
    
    return 0;
}