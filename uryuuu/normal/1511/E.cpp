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
const int maxn=300005;
//const ll Mod=1000000007;
const ll Mod=998244353;

string s[maxn];
ll pw[maxn];
int L[maxn],R[maxn];
int len[maxn];
ll dp[maxn][2];
ll sum[maxn][2];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    pw[0]=1ll;
    for(int i=1;i<maxn;i++)
        pw[i]=2ll*pw[i-1]%Mod;
    
    dp[2][1]=1;
    sum[2][1]=3;
    sum[2][0]=1;
    for(int i=3;i<maxn;i++)
    {
        dp[i][1]=(dp[i-1][0]+dp[i-1][0]+dp[i-1][1]+sum[i-1][0])%Mod;
        dp[i][0]=dp[i-1][1];
        sum[i][1]=(sum[i-1][0]+sum[i-1][1]+sum[i-1][0])%Mod;
        sum[i][0]=sum[i-1][1];
    }
    
    int num=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='o')
                num++;
        }
    }
    
    ll ans=0ll;
    for(int i=0;i<n;i++)
    {
        if(s[i][0]=='o')
            L[0]=1;
        else
            L[0]=0;
        for(int j=1;j<m;j++)
        {
            if(s[i][j]=='o')
            {
                L[j]=L[j-1]+1;
            }
            else
                L[j]=0;
        }
        L[m]=0;
        for(int j=0;j<m;j++)
        {
            if(L[j+1]==0)
                len[L[j]]++;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(s[0][i]=='o')
            L[0]=1;
        else
            L[0]=0;
        for(int j=1;j<n;j++)
        {
            if(s[j][i]=='o')
            {
                L[j]=L[j-1]+1;
            }
            else
                L[j]=0;
        }
        L[n]=0;
        for(int j=0;j<n;j++)
        {
            if(L[j+1]==0)
                len[L[j]]++;
        }
    }
    
    for(int i=2;i<=num;i++)
    {
        ans=(ans+(1ll*len[i]*pw[num-i]%Mod)*(dp[i][0]+dp[i][1])%Mod)%Mod;
    }
    
    cout<<(ans%Mod+Mod)%Mod<<endl;

    
    return 0;
}