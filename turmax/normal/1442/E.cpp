#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
bool used[maxn];
int b[maxn];
int dp[maxn][2];
int ans;
void dfs(int x)
{
    used[x]=true;
    vector <pair<int,int> > z;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
            z.push_back({dp[v][0],dp[v][1]});
        }
    }
    if(b[x]==0)
    {
        dp[x][1]=0;
        dp[x][0]=1;
        for(int i=0;i<z.size();++i)
        {
            dp[x][0]=max(dp[x][0],max(z[i].first,z[i].second+1));
        }
        vector <int> u0,u1;
        for(int i=0;i<z.size();++i)
        {
            u0.push_back(z[i].first);u1.push_back(z[i].second);
        }
        sort(u0.begin(),u0.end());reverse(u0.begin(),u0.end());
        sort(u1.begin(),u1.end());reverse(u1.begin(),u1.end());
        for(int i=0;i<z.size();++i)
        {
            int r=z[i].first;
            ans=max(ans,r);
            if(r!=u0[0])
            {
                ans=max(ans,r+u0[0]-1);
            }
            else if(u0.size()!=1)
            {
                ans=max(ans,r+u0[1]-1);
            }
            if(z[i].second!=u1[0])
            {
                ans=max(ans,r+u1[0]);
            }
            else if(u1.size()!=1)
            {
                ans=max(ans,r+u1[1]);
            }
            r=z[i].second;
            ans=max(ans,r+1);
            if(r!=u1[0])
            {
                ans=max(ans,r+u1[0]+1);
            }
            else if(u1.size()!=1)
            {
                ans=max(ans,r+u1[1]+1);
            }
        }
    }
    if(b[x]==1)
    {
        dp[x][1]=1;
        dp[x][0]=0;
        for(int i=0;i<z.size();++i)
        {
            dp[x][1]=max(dp[x][1],max(z[i].first+1,z[i].second));
        }
        vector <int> u0,u1;
        for(int i=0;i<z.size();++i)
        {
            u0.push_back(z[i].first);u1.push_back(z[i].second);
        }
        sort(u0.begin(),u0.end());reverse(u0.begin(),u0.end());
        sort(u1.begin(),u1.end());reverse(u1.begin(),u1.end());
        for(int i=0;i<z.size();++i)
        {
            int r=z[i].first;
            ans=max(ans,r+1);
            if(r!=u0[0])
            {
                ans=max(ans,r+u0[0]+1);
            }
            else if(u0.size()!=1)
            {
                ans=max(ans,r+u0[1]+1);
            }
            if(z[i].second!=u1[0])
            {
                ans=max(ans,r+u1[0]);
            }
            else if(u1.size()!=1)
            {
                ans=max(ans,r+u1[1]);
            }
            r=z[i].second;
            ans=max(ans,r);
            if(r!=u1[0])
            {
                ans=max(ans,r+u1[0]-1);
            }
            else if(u1.size()!=1)
            {
                ans=max(ans,r+u1[1]-1);
            }
        }
    }
    if(b[x]==(-1))
    {
        dp[x][1]=0;
        dp[x][0]=0;
        for(int i=0;i<z.size();++i)
        {
            dp[x][0]=max(dp[x][0],z[i].first);
            dp[x][1]=max(dp[x][1],z[i].second);
        }
        vector <int> u0,u1;
        for(int i=0;i<z.size();++i)
        {
            u0.push_back(z[i].first);u1.push_back(z[i].second);
        }
        sort(u0.begin(),u0.end());reverse(u0.begin(),u0.end());
        sort(u1.begin(),u1.end());reverse(u1.begin(),u1.end());
        for(int i=0;i<z.size();++i)
        {
            int r=z[i].first;
            ans=max(ans,r);
            if(r!=u0[0])
            {
                ans=max(ans,r+u0[0]-1);
            }
            else if(u0.size()!=1)
            {
                ans=max(ans,r+u0[1]-1);
            }
            if(z[i].second!=u1[0])
            {
                ans=max(ans,r+u1[0]);
            }
            else if(u1.size()!=1)
            {
                ans=max(ans,r+u1[1]);
            }
            r=z[i].second;
            ans=max(ans,r);
            if(r!=u1[0])
            {
                ans=max(ans,r+u1[0]-1);
            }
            else if(u1.size()!=1)
            {
                ans=max(ans,r+u1[1]-1);
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ans=0;
        for(int i=0;i<n;++i) {a[i].clear();used[i]=false;}
        for(int i=0;i<n;++i) {cin>>b[i];b[i]--;}
        for(int i=0;i<(n-1);++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);a[y].push_back(x);
        }
        dfs(0);
        cout<<ans/2+1<<endl;
    }
    return 0;
}