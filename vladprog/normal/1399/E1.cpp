#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<pii> g[N];
int sum;

struct cmp
{
    bool operator()(pii a,pii b)
    {
        return (a.x-a.x/2)*a.y>
               (b.x-b.x/2)*b.y;
    }
};

multiset<pii,cmp> edges;

int dfs(int v,int p,int d,int last)
{
    int cnt=0;
    bool leaf=true;
    for(pii to:g[v])
        if(to.x!=p)
        {
            leaf=false;
            cnt+=dfs(to.x,v,d+to.y,to.y);
        }
    if(leaf)
        sum+=d,cnt+=1;
    if(last!=-1)
        edges.insert({last,cnt});
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
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        sum=0;
        edges.clear();
        dfs(1,0,0,-1);
        int ans=0;
//        cout<<sum<<endl;
        while(sum>s)
        {
            pii p=*edges.begin();
//            cout<<p.x<<" "<<p.y<<endl;
            edges.erase(edges.begin());
            sum-=(p.x-p.x/2)*p.y;
            ans++;
            p.x/=2;
            edges.insert(p);
        }
        cout<<ans<<"\n";
    }
}