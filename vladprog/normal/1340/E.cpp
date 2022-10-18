#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5010,INF=1e9;

int n;
vector<int> g[N];
int dist[3][N];

void bfs(int from,int*dist,int nastya)
{
    for(int i=1;i<=n;i++)
        dist[i]=INF;
    dist[from]=0;
    queue<int> q;
    q.push(from);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int to:g[v])
            if(dist[to]==INF&&to!=nastya)
                dist[to]=dist[v]+1,
                q.push(to);
    }
}

array<int,5> calc(int a,int b,int c,int v,int x,int y,int z)
{
    int neighbours=-1,mxdist=-1,a1=-1,b1=-1,c1=-1;
    #define ret array<int,5>{neighbours,mxdist,a1,b1,c1}
    neighbours=(set<int>{x,y,z}).size();
    mxdist=-max({dist[x][a],dist[y][b],dist[z][c]});
    if(mxdist==-INF)
        return neighbours=-INF,ret;
    for(int to:g[a]) if(dist[x][to]<dist[x][a]) a1=to;
    for(int to:g[b]) if(dist[y][to]<dist[y][b]) b1=to;
    for(int to:g[c]) if(dist[z][to]<dist[z][c]) c1=to;
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0)^((int)(new char)));

    int m;
    cin>>n>>m;
    while(m--)
    {
        int v,u;
        cin>>v>>u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int a=rand()%n+1,b=rand()%n+1,c=rand()%n+1;
    a=b=c=1;
    cout<<a<<" "<<b<<" "<<c<<endl;
    int v;
    cin>>v;
    for(int _=0;_<n;_++)
    {
        if(a==v||b==v||c==v)
            exit(0);
        if(count(g[a].begin(),g[a].end(),v))
            cout<<v<<" "<<b<<" "<<c<<endl,exit(0);
        if(count(g[b].begin(),g[b].end(),v))
            cout<<a<<" "<<v<<" "<<c<<endl,exit(0);
        if(count(g[c].begin(),g[c].end(),v))
            cout<<a<<" "<<b<<" "<<v<<endl,exit(0);
        for(int t=0;t<g[v].size();t++)
            bfs(g[v][t],dist[t],v);
        array<int,5> res{-INF,-INF,-INF,-INF,-INF};
        for(int x=0;x<g[v].size();x++)
            for(int y=0;y<g[v].size();y++)
                for(int z=0;z<g[v].size();z++)
                    res=max(res,calc(a,b,c,v,x,y,z));
        a=res[2],b=res[3],c=res[4];
        cout<<a<<" "<<b<<" "<<c<<endl;
        if(a==v||b==v||c==v)
            exit(0);
        cin>>v;
    }
}