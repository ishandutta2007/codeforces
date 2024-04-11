#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,INF=1e18;

int c[3][N];
vector<int> g[N];
int out[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int j=0;j<3;j++)
        for(int i=1;i<=n;i++)
            cin>>c[j][i];
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(g[i].size()>2)
            cout<<-1,exit(0);
    vector<int> path;
    for(int i=1;i<=n;i++)
        if(g[i].size()==1)
        {
            path.push_back(i);
            path.push_back(g[i].front());
            break;
        }
    while(g[path.back()].size()==2)
        for(int to:g[path.back()])
            if(to!=path[path.size()-2])
            {
                path.push_back(to);
                break;
            }
    int ans=INF,col[3]={-10,-10,-10};
    int p[3]={0,1,2};
    do
    {
        int cur=0;
        for(int i=0;i<n;i++)
            cur+=c[p[i%3]][path[i]];
        if(cur<ans)
            ans=cur,
            col[0]=p[0],
            col[1]=p[1],
            col[2]=p[2];
    }
    while(next_permutation(p,p+3));
    cout<<ans<<"\n";
    for(int i=0;i<n;i++)
        out[path[i]]=col[i%3];
    for(int i=1;i<=n;i++)
        cout<<out[i]+1<<" ";
}