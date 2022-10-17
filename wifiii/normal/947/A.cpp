#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
const int mod = 1e9+7;


const int maxn = 1000005;
int prime[maxn],np[maxn],tot=0;
void init()
{
    np[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) prime[++tot] = i;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>=maxn) break;
            np[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}

int dp[1000005],dp2[1000005];
int dfs2(int x)
{
    if(dp2[x]) return dp2[x];
    int mx=1;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            if(!np[i]) mx=max(mx,i);
            if(!np[x/i]) mx=max(mx,x/i);
        }
    }
    int ret=x-mx+1;
    return dp2[x]=ret;
}
int dfs(int x)
{
    if(dp[x]) return dp[x];
    int ret=1e9;
    int mx=1;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            if(!np[i]) mx=max(mx,i);
            if(!np[x/i]) mx=max(mx,x/i);
        }
    }
    for(int i=x-mx+1;i<=x;++i) ret=min(ret,dfs2(i));
    return dp[x]=ret;
}
int main()
{
    init();
    int n;
    cin>>n;
    cout<<dfs(n)<<endl;
}