#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,INF=2e9;

struct pt
{
    int x,y,ind;
};

bool cmpx(pt a,pt b)
{
    return a.x<b.x;
}

bool cmpy(pt a,pt b)
{
    return a.y<b.y;
}

pt fast[N];
vector<pii> g[N];
int dist[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    m++;
    int sx,sy,fx,fy;
    cin>>sx>>sy>>fx>>fy;
    fast[1]=pt{sx,sy,1};
    for(int i=2;i<=m;i++)
        cin>>fast[i].x>>fast[i].y,
        fast[i].ind=i;
    sort(fast+1,fast+m+1,cmpx);
    for(int i=1;i<=m-1;i++)
    {
        int a=fast[i].ind,b=fast[i+1].ind;
        int w=fast[i+1].x-fast[i].x;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    sort(fast+1,fast+m+1,cmpy);
    for(int i=1;i<=m-1;i++)
    {
        int a=fast[i].ind,b=fast[i+1].ind;
        int w=fast[i+1].y-fast[i].y;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    for(int i=2;i<=m;i++)
        dist[i]=INF;
    set<pii> s{{0,1}};
    while(!s.empty())
    {
        int d,v;
        tie(d,v)=*s.begin();
        s.erase(s.begin());
        for(pii to:g[v])
            if(d+to.y<dist[to.x])
                s.erase({dist[to.x],to.x}),
                dist[to.x]=d+to.y,
                s.insert({dist[to.x],to.x});
    }
    int ans=INF;
    for(int i=1;i<=m;i++)
        ans=min(ans,dist[fast[i].ind]+abs(fast[i].x-fx)+abs(fast[i].y-fy));
    cout<<ans;
}