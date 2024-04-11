#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);
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
struct node
{
    ll arr,dep;
};
int t=0;
void dfs(int x,int p,vvi&adj,vector<node>&v,vvi&dp,vi&depth)
{
    v[x].arr=t++;
    for(auto node:adj[x])
    {
        if(node^p){
            dp[node][0]=x;
            depth[node]=depth[x]+1;
            dfs(node,x,adj,v,dp,depth);
        }
    }
    v[x].dep=t++;
}
bool is_ancestor(int a,int b,vector<node>&v)
{
    return v[a].arr<=v[b].arr&&v[a].dep>=v[b].dep;
}
int lca(int n,int a, int b,vvi&dp,vector<node>&v)
{
    if (is_ancestor(a,b,v))
        return a;
    if (is_ancestor(b,a,v))
        return b;
    int l=0;
    while(n)
    {
        l++;
        n/=2;
    }
    l++;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(dp[a][i], b,v)&&dp[a][i]!=-1)
            a = dp[a][i];
    }
    return dp[a][0];
}
vi depth;
bool cmp(int a,int b)
{
    return depth[a]<depth[b];
}
int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    vvi adj(n);
    vector<node> v(n);
    vvi dp(n+1,vi(20,-1));

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    depth=vector<int>(n,0);
    dfs(0,0,adj,v,dp,depth);
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[j][i-1]!=-1)
                dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    //cout<<dp[10][0]<<'\n';
    //cout<<lca(n,9,5,dp,v)<<'\n';
    
    while(q--)
    {
        int k;
        cin>>k;
        vi query(k);
        for(int i=0;i<k;i++) {cin>>query[i];query[i]--;}
        sort(query.begin(),query.end(),cmp);
        bool ans=true;
        for(int i=0;i<k-1;i++)
        {
            int w=lca(n,query[k-1],query[i],dp,v);
            //cout<<query[k-1]<<" "<<query[i]<<" "<<w<<" aaa"<<'\n';
            if(abs(depth[w]-depth[query[i]])>1)
            {
                ans=false;
                break;
            }
        }
        if(ans) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    
}