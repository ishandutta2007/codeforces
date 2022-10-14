#include <bits/stdc++.h>

#define ff(i,a,b) for(int i=a;i<b;i++)
#define fff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

using namespace std;

const int mod=1e9+7;

vector<vector<int>> g(100005),rev(100005);
vector<int> ord;
vector<int> comp;
bool was[100005];

void dfs1(int u)
{
    was[u]=1;
    for(int v: g[u])
        if(!was[v]) 
            dfs1(v);
    ord.pb(u);
}

void dfs2(int u)
{
    was[u]=1;
    comp.pb(u);
    for(int v: rev[u])
        if(!was[v])
            dfs2(v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    int n; cin>>n;
    vector<int> a(n);
    ff(i,0,n) cin>>a[i];
    int m; cin>>m;
    ff(i,0,m)
    {
        int u,v; cin>>u>>v;
        --u,--v;
        g[u].pb(v);
        rev[v].pb(u);
    }
    
    ff(i,0,n) if(!was[i]) dfs1(i);
    reverse(ord.begin(), ord.end());
    ff(i,0,n) was[i]=0;
    
    long long s=0,ans=1;
    for(int i:ord)
    {
        if(!was[i])
        {
            comp.clear();
            dfs2(i);
            int mn=1e9;
            for(int j:comp)
                mn=min(mn,a[j]);
            int cnt=0;
            for(int j:comp)
                if(a[j]==mn)
                    cnt++;
            s+=mn, ans*=cnt;
            ans%=mod;
        }
    }
    cout<<s<<" "<<ans;
}