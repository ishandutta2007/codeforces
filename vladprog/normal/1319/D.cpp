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
int p[N];
int d[N];
set<int> can[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
        cin>>p[i];
    int s=p[1],t=p[k];
    queue<int> q;
    q.push(t);
    for(int i=1;i<=n;i++)
        d[i]=-1;
    d[t]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int to:g[v])
            if(d[to]==-1)
                d[to]=d[v]+1,
                q.push(to);
    }
    for(int to=1;to<=n;to++)
        for(int from:g[to])
            if(d[to]==d[from]-1)
                can[from].insert(to);
    int mn=0,mx=0;
    for(int i=1;i<=k-1;i++)
    {
        if(!can[p[i]].count(p[i+1]))
            mn++,mx++;
        else if(can[p[i]].size()>=2)
            mx++;
    }
    cout<<mn<<" "<<mx;
}