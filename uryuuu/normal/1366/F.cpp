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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=2010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int u[maxn],v[maxn],w[maxn],n,m,q;
ll dp[2][maxn],b[maxn],ans;

int main()
{
    sync;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=-1e9;
        dp[1][i]=-1e9;
    }
    for(int i=1;i<=m;i++)
    {
        b[i]=-1e9;
    }
    dp[0][1]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i&1][v[j]]=max(dp[i&1][v[j]],dp[i-1&1][u[j]]+w[j]);
            dp[i&1][u[j]]=max(dp[i&1][u[j]],dp[i-1&1][v[j]]+w[j]);
        }
        for(int j=1;j<=m;j++)
        {
            b[j]=max(b[j],max(dp[i&1][u[j]],dp[i&1][v[j]])-i*w[j]);
        }
        ans=(ans+*max_element(dp[i&1]+1,dp[i&1]+n+1))%Mod;
    }
    
    for(int i=1;i<=m;i++)
    {
        ll l=n,r=q;
        for(int j=1;l<=r&&j<=m;j++)
            if(i!=j)
            {
                ll k=w[i]-w[j];
                ll db=b[j]-b[i];
                if(k>0)
                    l=max(l,db/k+1);
                else if(k<0)
                    r=min(r,db/k);
                if(k==0)
                {
                    if(!(db<0||(db==0&&j>i)))
                        r=-1;
                }
            }
        if(l<=r)
            ans=(ans+(l+r)*(r-l+1)/2%Mod*w[i]%Mod+(b[i]%Mod+Mod)%Mod*(r-l+1)%Mod)%Mod;
    }
    cout<<ans<<endl;
    return 0;
}
// https://blog.csdn.net/NeverMakeIt/article/details/106736616?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase
//
//