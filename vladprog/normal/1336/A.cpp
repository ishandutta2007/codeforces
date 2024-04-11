#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

vector<int> g[N];
int d[N],s[N];

int dfs1(int v,int p,int h)
{
    d[v]=h;
    s[v]=1;
    for(int to:g[v])
        if(to!=p)
            s[v]+=dfs1(to,v,h+1);
    return s[v];
}

pii fv[N];
bool choose[N];
int ans=0;

void dfs2(int v,int p,int h)
{
    if(choose[v])
        ans+=h;
    else
        h++;
    for(int to:g[v])
        if(to!=p)
            dfs2(to,v,h);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0,0);
    for(int i=1;i<=n;i++)
        fv[i]={d[i]-(s[i]-1),i};
    sort(fv+1,fv+n+1,greater<pii>());
    for(int i=1;i<=k;i++)
        choose[fv[i].y]=true;
    dfs2(1,0,0);
    cout<<ans;
}