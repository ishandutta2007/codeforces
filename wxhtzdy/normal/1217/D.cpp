#include <bits/stdc++.h>

#define ff(i,a,b) for(int i=a;i<b;i++)
#define fff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair

using namespace std;

vector<vector<pair<int,int>>> g(5005);
int u[5005],v[5005];
int res[5005];
bool was[5005];
bool in[5005];

void dfs(int u)
{
    was[u]=1, in[u]=1;
    for(auto c: g[u])
    {
        int v=c.first;
        int i=c.second;
        if(!was[v]) dfs(v),res[i]=1;
        else if(!in[v]) res[i]=1;
        else res[i]=2;
    }
    in[u]=0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    int n,m; cin>>n>>m;
    fff(i,1,m)
    {
        cin>>u[i]>>v[i];
        g[u[i]].pb({v[i],i});
    }
    fff(i,1,n) if(!was[i]) dfs(i);
    cout<<*max_element(res+1,res+m+1)<<'\n';
    fff(i,1,m) cout<<res[i]<<" ";
}