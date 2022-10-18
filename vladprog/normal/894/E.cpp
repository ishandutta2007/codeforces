//#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

vector<pii> g[N];
vector<int> h[N];
vector<int> top;
bool used[N];

void dfs1(int v)
{
    if(used[v])
        return;
    used[v]=true;
    for(pii to:g[v])
        dfs1(to.x);
    top.push_back(v);
}

vector<vector<int>> comp;

void dfs2(int v)
{
    if(used[v])
        return;
    used[v]=true;
    for(int to:h[v])
        dfs2(to);
    comp.back().push_back(v);
}

int dp[N];

int sum(int x)
{
    /// x,x-1,x-1-2,...,x-1-2-...-y
    /// x-y(y+1)/2>=0
    /// 2x-y^2-y>=0
    /// y^2+y-2x<=0
    /// D=8x+1
    /// y=(sqrt(8x+1)-1)/2
    int y=(sqrt(8*x+1)-1)/2;
    while(x-y*(y+1)/2>=0)
        y++;
    while(x-y*(y+1)/2<0)
        y--;
    int z=x-y*(y+1)/2;
    int ans=x*(y+1)-y*(y+1)*(y+2)/6;
//    cout<<x<<" -> "<<y<<" -> "<<z<<" -> "<<ans<<"\n";
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        h[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        dfs1(i);
    reverse(top.begin(),top.end());
    memset(used,0,sizeof(used));
    for(auto v:top)
        if(!used[v])
        {
            comp.push_back(vector<int>());
            dfs2(v);
        }
    reverse(comp.begin(),comp.end());
    memset(dp,255,sizeof(dp));
    for(auto c:comp)
    {
        int cur=0,nxt=0;
        for(int v:c)
            for(auto to:g[v])
                if(dp[to.x]==-1)
                    cur+=sum(to.y);
                else
                    nxt=max(nxt,to.y+dp[to.x]);
        int ans=cur+nxt;
        for(int v:c)
            dp[v]=ans;
    }
    int s;
    cin>>s;
    cout<<dp[s];
}