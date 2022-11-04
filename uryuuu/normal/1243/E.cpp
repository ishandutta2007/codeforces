//#include <bits/stdc++.h>
#include<iostream>
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
#include<time.h>
#include<cstdlib>
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=5005*16;
unordered_map<ll,int>mp;
vector<pair<int,int>>ans[1<<15];
int cnt,dp[1<<15];
int k[16],a[16][5005],vis[16],G[5005*16];
ll s[16];
pair<int,int>p[maxn];
void solve(int jie)
{
    mm(vis);
    queue<int>q;
    vector<pair<int,int>>tmp;
    int ss=(1<<p[jie].first-1);
    q.push(jie);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==jie&&vis[p[u].first])
        {
            dp[ss]=1;
            ans[ss]=tmp;
            return;
        }
        if(vis[p[u].first])
        {
            return;
        }
        vis[p[u].first]=1;
        if(G[u])
        {
            int v=G[u];
            q.push(v);
            ss|=(1<<p[v].first-1);
            tmp.push_back(make_pair(a[p[v].first][p[v].second], p[u].first));
        }
    }
    
}

bool cmp(pair<int,int>a,pair<int,int>b)
{
    int p1=mp[a.first],p2=mp[b.first];
    return p[p1].first<p[p2].first;
}
int main()
{
    sync;
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            sum+=a[i][j];
            s[i]+=a[i][j];
            mp.emplace(a[i][j],++cnt);
            p[cnt]=make_pair(i,j);
        }
    }
    if(sum%n)
    {
        cout<<"No"<<endl;
        return 0;
    }
    sum/=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            ll v=sum-(s[i]-a[i][j]);
            int cur=mp[v];
            if(!cur||(p[cur].first==i&&p[cur].second!=j))
                continue;
            G[mp[a[i][j]]]=cur;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        solve(i);
    }
    int ss=(1<<n)-1;
    for(int i=1;i<=ss;i++)
    {
        if(!dp[i])
        {
            for(int j=(i-1)&i;j;j=(j-1)&i)
            {
                if(dp[j]&&dp[i^j])
                {
                    dp[i]=1;
                    ans[i]=ans[j];
                    for(auto tmp:ans[i^j])
                        ans[i].push_back(tmp);
                    break;
                }
            }
        }
    }
    if(dp[ss]==0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    sort(ans[ss].begin(),ans[ss].end(),cmp);
    for(auto tmp:ans[(1<<n)-1])
        cout<<tmp.first<<' '<<tmp.second<<endl;
    return 0;
}