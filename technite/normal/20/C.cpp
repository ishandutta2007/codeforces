#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<bool> vis(n,0);
    priority_queue<pair<long long,long long>> q;
    q.push({0,0});
    vector<long long> d(n,1e18);
    d[0]=0;
    vector<int> p(n);
    while(q.size())
    {
        auto [dist,node]=q.top();q.pop();
        if(vis[node]) continue;
        vis[node]=1;
        for(auto [u,v]:adj[node])
        {
            if(d[node]+v<d[u])
            {
                d[u]=d[node]+v;
                q.push({-d[u],u});
                p[u]=node;
            }
        }
    }       
    if(d[n-1]==1e18) cout<<-1<<'\n';
    else
    {
        int node=n-1;
        vector<int> ans;
        while(node!=0)
        {
            ans.push_back(node);
            node=p[node];
        }
        ans.push_back(0);
        reverse(ans.begin(),ans.end());
        for(auto x:ans) cout<<x+1<<" ";
    }

}