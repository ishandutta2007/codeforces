#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int p[N],h[N],s[N];
vector<int> g[N];

bool dfs(int v,int par)
{
    s[v]=p[v];
    int good=0,bad=p[v];
    for(int to:g[v])
        if(to!=par)
        {
            if(!dfs(to,v))
                return false;
            s[v]+=s[to];
            good+=(s[to]+h[to])/2;
            bad+=(s[to]-h[to])/2;
        }
    int x2=h[v]-(good-bad);
    return x2%2==0&&x2>=0&&x2<=2*bad;
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>p[i];
        for(int i=1;i<=n;i++)
            cin>>h[i];
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout<<(dfs(1,0)?"YES\n":"NO\n");
    }
}