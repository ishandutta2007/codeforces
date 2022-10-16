#include<bits/stdc++.h>
using namespace std;
int main()
{
     ios::sync_with_stdio(0);cin.tie(0);   
     long long n,m,k;
     cin>>n>>m>>k;
     vector<vector<pair<long long,long long>>> road(n),adj(n);
     vector<long long> train(n,1e18);
     int deleted=0;
     for(long long i=0;i<m;i++)
     {
        long long a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        road[a].push_back({b,c});
        road[b].push_back({a,c});
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
     }
     vector<long long> d(n,1e18);
     for(long long i=0;i<k;i++)
     {
        long long a,b;
        cin>>a>>b;
        a--;
        adj[a].push_back({0,b});
        adj[0].push_back({a,b});
        if(train[a]==1e18)  train[a]=b;
        else
        {
            deleted++;
            train[a]=min(train[a],b);
        }
     }
     priority_queue<pair<long long,long long>> q;
     vector<bool> vis(n,0);
     q.push({0,0});
     d[0]=0;
     while(q.size())
     {
        auto [dist,node]=q.top();
        q.pop();
        if(vis[node]) continue;
        vis[node]=1;
        for(auto x:adj[node])
        {
            long long u=x.first,w=x.second;
            if(d[node]+w<d[u])
            {
                d[u]=d[node]+w;
                q.push({-d[u],u});
            }
        }
     }
     long long ans=0;
     for(int i=1;i<n;i++)
     {
        if(train[i]==1e18) continue;
        if(d[i]<train[i]) ans++;
        else if(d[i]==train[i])
        {
            for(auto [u,v]:road[i])
            {
                if(d[u]+v==d[i])
                {
                    ans++;
                    break;
                }
            }
        }
     }
     
     cout<<ans+deleted<<'\n';
}