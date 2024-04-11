#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=610,INF=1.005e9;

vector<pii> g[N];
int dist[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    for(int start=0;start<n;start++)
    {
        for(int i=0;i<n;i++)
            dist[i]=INF;
        dist[start]=0;
        set<pii> q;
        for(auto[b,c]:g[start])
        {
            int to=b;
            int tim=c;
            if(dist[to]>tim)
                q.erase({dist[to],to}),
                dist[to]=tim,
                q.insert({dist[to],to});
            int delta=(start+1-to+n)%n;
            to=(to+delta)%n;
            tim+=delta;
            if(dist[to]>tim)
                q.erase({dist[to],to}),
                dist[to]=tim,
                q.insert({dist[to],to});
        }
        while(!q.empty())
        {
            auto[s,a]=*q.begin();
            q.erase(q.begin());
            {
                int to=(a+1)%n;
                int tim=s+1;
                if(dist[to]>tim)
                    q.erase({dist[to],to}),
                    dist[to]=tim,
                    q.insert({dist[to],to});
            }
            for(auto[b,c]:g[a])
            {
                int to=(b+s)%n;
                int tim=s+c;
                if(dist[to]>tim)
                    q.erase({dist[to],to}),
                    dist[to]=tim,
                    q.insert({dist[to],to});
                int delta=(start+1-to+n)%n;
                to=(to+delta)%n;
                tim+=delta;
                if(dist[to]>tim)
                    q.erase({dist[to],to}),
                    dist[to]=tim,
                    q.insert({dist[to],to});
            }
        }
        for(int i=0;i<n;i++)
            cout<<dist[i]<<" ";
        cout<<"\n";
    }
}