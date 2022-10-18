#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

vector<int> g[N];
int par[N],dep[N];
set<int> level[N];

void dfs(int v,int p,int d)
{
    par[v]=p;
    dep[v]=d;
    level[d].insert(v);
    for(int to:g[v])
        if(to!=p)
            dfs(to,v,d+1);
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
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
            g[i].clear(),
            level[i].clear();
        for(int _=1;_<=n-1;_++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<"? "<<n<<" ";
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
        int r,m;
        cin>>r>>m;
        if(r==-1)
            exit(1);
        dfs(r,0,0);
        int h=0;
        for(int i=1;;i++)
            if(level[i].empty())
                break;
            else
                h=i;
        int lo=(m+1)/2,hi=min(m,h);
        int s=-1;
        while(lo<=hi)
        {
            int mi=(lo+hi)/2;
            cout<<"? "<<level[mi].size()<<" ";
            for(int x:level[mi])
                cout<<x<<" ";
            cout<<endl;
            int v,d;
            cin>>v>>d;
            if(v==-1)
                exit(1);
            if(d==m)
                s=v,
                lo=mi+1;
            else
                hi=mi-1;
        }
        for(int i=s;i!=r;i=par[i])
            level[dep[i]].erase(i);
        int mi=m-dep[s];
        cout<<"? "<<level[mi].size()<<" ";
        for(int x:level[mi])
            cout<<x<<" ";
        cout<<endl;
        int f,d;
        cin>>f>>d;
        if(f==-1)
            exit(1);
        cout<<"! "<<s<<" "<<f<<endl;
        string resp;
        cin>>resp;
        if(resp!="Correct")
            exit(0);
    }
}