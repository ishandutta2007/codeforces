#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],b[N],c[N];
vector<int> g[N];
int ans=0;

pii dfs(int v,int p,int cost)
{
    cost=min(cost,a[v]);
    pii res(0,0);
    if(b[v]!=c[v])
        if(!b[v])
            res.x++;
        else
            res.y++;
    for(int to:g[v])
        if(to!=p)
        {
            pii cur=dfs(to,v,cost);
            res.x+=cur.x;
            res.y+=cur.y;
        }
    int t=min(res.x,res.y);
    ans+=2*t*cost;
    res.x-=t,res.y-=t;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pii res=dfs(1,-1,2e9);
    if(res.x||res.y)
        ans=-1;
    cout<<ans;
}