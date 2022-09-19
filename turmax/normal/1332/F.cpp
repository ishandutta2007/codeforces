#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
int inv(int x)
{
    return po(x,p-2);
}
const int maxn=300000;
vector <int> a[maxn];
int dp[maxn][2][2];
bool used[maxn];
void dfs(int x)
{
    used[x]=true;
    int v;
    vector <int> z;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            dfs(v);
            z.push_back(v);
        }
    }
    if(z.empty())
    {
        dp[x][0][1]=1;
        dp[x][1][1]=1;
        dp[x][0][0]=1;
        dp[x][1][0]=0;
        return;
    }
    int ans11=1;
    for(int i=0;i<z.size();++i)
    {
        ans11*=(dp[z[i]][0][0]+dp[z[i]][1][0]+dp[z[i]][0][1]+dp[z[i]][1][1]);
        ans11%=p;
        ans11*=inv(2);
        ans11%=p;
    }
    dp[x][0][1]=ans11;
    int ans12=1;
    for(int i=0;i<z.size();++i)
    {
        ans12*=(((dp[z[i]][0][0]+dp[z[i]][0][1]+dp[z[i]][1][0])*inv(2))%p);
        ans12%=p;
    }
    dp[x][1][1]=ans12;
    int ans21=ans11;
    dp[x][0][0]=ans21;
    int ans22=ans12;
    int ans221=1;
    for(int i=0;i<z.size();++i)
    {
        ans221*=inv(2);
        ans221%=p;
        ans221*=(dp[z[i]][0][0]+dp[z[i]][1][0]);
        ans221%=p;
    }
    ans22-=ans221;
    ans22%=p;
    ans22+=p;
    ans22%=p;
    dp[x][1][0]=ans22;
    //cout<<x<<" x "<<endl;
    //cout<<dp[x][0][0]<<" "<<dp[x][0][1]<<" "<<dp[x][1][0]<<" "<<dp[x][1][1]<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    int ans=dp[0][0][0]+dp[0][1][0];
    ans%=p;
    ans*=(po(2,n-1));
    ans%=p;
    ans--;
    ans%=p;
    ans+=p;
    ans%=p;
    cout<<ans;
    return 0;
}