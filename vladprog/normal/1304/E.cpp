#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,L=20;

vector<int> g[N];
int h[N],pos[N];
vector<pii> ord;

void dfs(int v,int p,int cur)
{
    h[v]=cur;
    pos[v]=ord.size();
    ord.push_back({cur,v});
    for(int to:g[v])
        if(to!=p)
            dfs(to,v,cur+1),
            ord.push_back({cur,v});
}

pii st[L][N];

pii get(int l,int r)
{
    if(l>r)
        swap(l,r);
    int j=31-__builtin_clz(r-l+1);
    return min(st[j][l],st[j][r-(1<<j)+1]);
}

int dist(int a,int b)
{
    return h[a]+h[b]-2*get(pos[a],pos[b]).first;
}

bool ok(int k,int m)
{
    return m<=k&&m%2==k%2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    for(int i=0;i<ord.size();i++)
        st[0][i]=ord[i];
    for(int j=1;j<L;j++)
        for(int i=0;i+(1<<j)-1<ord.size();i++)
            st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        cout<<(ok(k,dist(a,b))||ok(k,dist(a,x)+1+dist(b,y))||ok(k,dist(a,y)+1+dist(b,x))?"YES\n":"NO\n");
    }
}