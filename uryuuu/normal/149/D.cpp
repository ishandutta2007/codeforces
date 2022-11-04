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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1005;
const ll Mod=1000000007;
//const ll Mod=998244353;


string s;
int a[maxn],st[maxn];
int mp[maxn][maxn];
ll dp[maxn][maxn][3][3];
int nxt[maxn];

ll dfs(int l,int r,int lc,int rc)
{
    if(l>r)
        return 0;
    if(dp[l][r][lc][rc]!=-1)
        return dp[l][r][lc][rc];
    if(l==r)
    {
        if(lc==rc)
            return dp[l][r][lc][rc]=1;
        return dp[l][r][lc][rc]=0;
    }
    
    
    if(l+1==r)
    {
        if(lc&&rc)
            return dp[l][r][lc][rc]=0;
        if(lc==0&&rc==0)
            return dp[l][r][lc][rc]=0;
        return dp[l][r][lc][rc]=1;
    }
    
    int i,j;
    dp[l][r][lc][rc]=0;
    int L,R;

    if(mp[l][r])
    {
        if(lc&&rc)
            return dp[l][r][lc][rc]=0;
        if(lc==0&&rc==0)
            return dp[l][r][lc][rc]=0;
        ll sum=0ll;
        L=l+1;
        R=r-1;
        for(i=0;i<=2;i++)
        {
            if(lc==i&&i)
                continue;
            for(j=0;j<=2;j++)
            {
                if(j==rc&&j)
                    continue;
                if(mp[L][R])
                {
                    if(i&&j)
                        continue;
                    if(i==0&&j==0)
                        continue;
                }
                if(dfs(L,R,i,j))
                    sum=(sum+dfs(L,R,i,j))%Mod;
            }
        }
        return dp[l][r][lc][rc]=sum;
    }
        
    R=nxt[l];
    L=R+1;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            if(j==i&&i)
                continue;
            if(mp[R][L])
            {
                if(i&&j)
                    continue;
                if(i==0&&j==0)
                    continue;
            }
            dp[l][r][lc][rc]=(dp[l][r][lc][rc]+dfs(l,R,lc,i)*dfs(L,r,j,rc)%Mod)%Mod;
        }
    }

    return dp[l][r][lc][rc];
}

int main()
{
    sync;
    int n;
    cin>>s;
    n=s.length();
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='(')
            a[i]=1;
        else
            a[i]=-1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
            st[++cnt]=i;
        else
        {
            mp[st[cnt]][i]=1;
            nxt[st[cnt]]=i;
            cnt--;
        }
    }
    
    
    memset(dp,-1,sizeof(dp));
    ll ans=0ll;
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            ans=(ans+dfs(1,n,i,j))%Mod;
        }
    }
    cout<<(ans%Mod+Mod)%Mod<<endl;
    
    return 0;
}