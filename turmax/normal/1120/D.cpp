#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
vector <int> b[2*maxn];
vector <bool> d[2*maxn];
int c[maxn];
int dp[maxn][2];
bool used[2*maxn];
bool used1[2*maxn];
void dfs(int x)
{
    used[x]=true;
    int ans0=0;
    bool h=false;
    int ma=(-1e18);
    vector <int> u;
    vector <int> z;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            z.push_back(v);
            dfs(v);
            ans0+=dp[v][0];
            b[2*x].push_back(2*v);d[2*x].push_back(true);
            int curr=dp[v][0]-dp[v][1];
            if(curr>ma)
            {
                ma=curr;
                u.clear();
                u.push_back(v);
            }
            else if(curr==ma)
            {
                u.push_back(v);
            }
            h=true;
        }
    }
    if(!h) {dp[x][0]=c[x];dp[x][1]=0;b[2*x].push_back(2*x+1);d[2*x].push_back(true);return;}
    dp[x][1]=ans0-ma;
    dp[x][0]=ans0;
    if(u.size()==1)
    {
        for(auto v:z)
        {
            if(v!=u[0])
            {
                b[2*x+1].push_back(2*v);
                d[2*x+1].push_back(true);
            }
            else
            {
                b[2*x+1].push_back(2*v+1);
                d[2*x+1].push_back(false);
            }
        }
    }
    else
    {
        for(auto v:z)
        {
            b[2*x+1].push_back(2*v);
            d[2*x+1].push_back(true);
        }
        for(auto v:u)
        {
            b[2*x+1].push_back(2*v+1);
            d[2*x+1].push_back(false);
        }
    }
    if((dp[x][1]+c[x])<ans0)
    {
        dp[x][0]=(dp[x][1]+c[x]);
        b[2*x].clear();
        d[2*x].clear();
        b[2*x].push_back(2*x+1);
        d[2*x].push_back(true);
    }
    else if((dp[x][1]+c[x])==ans0)
    {
        b[2*x].push_back(2*x+1);
        d[2*x].push_back(true);
    }
}
void dfs1(int x)
{
    used[x]=true;
    for(int i=0;i<b[x].size();++i)
    {
        int v=b[x][i];
        if(!used[v]){
        dfs1(v);
        if(d[x][i])
        {
            used1[v]=true;
        }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>c[i];
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    cout<<dp[0][0]<<' ';
    for(int i=0;i<2*maxn;++i) used[i]=false;
    dfs1(0);
    vector <int> v;
    for(int i=0;i<maxn;++i) if(used1[2*i+1]) v.push_back(i);
    cout<<v.size()<<endl;
    for(auto h:v) cout<<h+1<<' ';
    return 0;
}