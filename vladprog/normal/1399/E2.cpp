#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<pair<int,pii>> g[N];
int sum;

vector<int> edges[3];

int dfs(int v,int p,int d,int w,int c)
{
    int cnt=0;
    bool leaf=true;
    for(auto to:g[v])
        if(to.x!=p)
        {
            leaf=false;
            cnt+=dfs(to.x,v,d+to.y.x,to.y.x,to.y.y);
        }
    if(leaf)
        sum+=d,cnt+=1;
    if(w!=-1)
        for(;w;w/=2)
            edges[c].push_back((w-w/2)*cnt);
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v,w,c;
            cin>>u>>v>>w>>c;
            g[u].push_back({v,{w,c}});
            g[v].push_back({u,{w,c}});
        }
        sum=0;
        edges[1].clear();
        edges[2].clear();
        dfs(1,0,0,-1,-1);
        sort(edges[1].begin(),edges[1].end(),greater<>());
        sort(edges[2].begin(),edges[2].end(),greater<>());
        edges[1].insert(edges[1].begin(),0);
        edges[2].insert(edges[2].begin(),0);
        for(int i=1;i<edges[1].size();i++)
            edges[1][i]+=edges[1][i-1];
        for(int i=1;i<edges[2].size();i++)
            edges[2][i]+=edges[2][i-1];
//        for(int x:edges[1])
//            cout<<x<<" ";
//        cout<<"\n";
//        for(int x:edges[2])
//            cout<<x<<" ";
//        cout<<"\n";
        int ans=1e9;
        for(int i=0,j=edges[2].size();i<edges[1].size();i++)
        {
            while(j>0&&sum-(edges[1][i]+edges[2][j-1])<=s)
                j--;
            if(j<edges[2].size())
                ans=min(ans,i+2*j);
        }
        cout<<ans<<"\n";
    }
}