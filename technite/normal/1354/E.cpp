#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
int mv_x[]={0,0,1,-1};
int mv_y[]={1,-1,0,0};
vector<bool> vis;
bool isBipartite(vvi &adj, int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : adj[v]) { 
  
        // if vertex u is not explored before 
        if (visited[u] == false) { 
  
            // mark present vertic as visited 
            visited[u] = true; 
  
            // mark its color opposite to its parent 
            color[u] = !color[v]; 
  
            // if the subtree rooted at vertex v is not bipartite 
            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
  
        // if two adjacent are colored with same color then 
        // the graph is not bipartite 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 
void reps(int x,vvi&adj)
{
    //cout<<"YESS"<<endl;
    for(auto node:adj[x])
    {
        if(!vis[node])
        {
            vis[node]=1;
            reps(node,adj);
        }
    }
}
void dfs(int i,int x,vvi&adj,vvi v[],bool boo)
{
    vis[x]=1;
    for(auto node:adj[x])
    {
        if(vis[node]) continue;
        vis[node]=1;
        v[i][boo].pb(node);
        dfs(i,node,adj,v,!boo);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vis=vector<bool>(n,0);
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vvi adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi rep;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            rep.pb(i);
            reps(i,adj);
        }
    }
    for(int i=0;i<n;i++) vis[i]=0;   
    vvi v[rep.size()];
    vector<vector<bool>> dp(rep.size()+1,vector<bool>(n+1,0));
    bool boo=false;
    dp[0][0]=1;
    vi tmp;
    tmp.clear();
    vector<bool> xis(n,0);
    vi color(n);
    for(int i=0;i<rep.size();i++)
    {
        if(!isBipartite(adj,rep[i],xis,color))
        {
            cout<<"NO"<<'\n';
            return 0;
        }
        v[i].pb(tmp);
        v[i].pb(tmp);
        v[i][1].pb(rep[i]);
        dfs(i,rep[i],adj,v,boo);
        for(int j=0;j<=n;j++)
        {
            if(dp[i][j])
            {
                if(j+v[i][1].size()<=n) dp[i+1][j+v[i][1].size()]=1;
                if(j+v[i][0].size()<=n) dp[i+1][j+v[i][0].size()]=1;
            }
        }
    }
    if(dp[rep.size()][n2]==1)
    {
        int x=rep.size();
        vpi ans;
        cout<<"YES"<<'\n';
        while(n2)
        {
            bool yru=false;
            if(n2-(int)v[x-1][0].size()>=0)
            {     
                if(dp[x-1][n2-(int)v[x-1][0].size()])
                {
                    n2-=v[x-1][0].size();
                    ans.pb({x-1,0});
                    x--;
                    yru=true;
                }
            }
            if(n2-v[x-1][1].size()>=0&&!yru)
            {
                if(dp[x-1][n2-v[x-1][1].size()]){
                    n2-=v[x-1][1].size();
                    ans.pb({x-1,1});
                    x--;   
                }
            }
        }
        vi col(n,0);
        for(auto x:ans)
        {
            for(auto node:v[x.F][x.S])
            {
                col[node]=2;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(col[i]==0)
            {
                if(n1){
                cout<<1;
                n1--;
                }
                else cout<<3;
            }
            else cout<<2;
        }

    }
    else cout<<"NO"<<'\n';
}