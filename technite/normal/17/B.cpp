#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    vector<int> q(n);
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n;i++) cin>>q[i];
        cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[b].push_back({a,c});
    }
    int cnt=0;
    long long cost=0;
    for(int i=0;i<n;i++)
    {
        int mn=1e9;
        if(adj[i].size()==0) cnt++;
        else
        {
            for(auto x:adj[i])mn=min(x.second,mn);
            cost+=mn;
        }

    }
    if(cnt>1) cout<<-1<<'\n';
    else
    cout<<cost<<'\n';
}