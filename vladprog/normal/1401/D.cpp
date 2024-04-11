#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,M=6e4+100,MOD=1e9+7;

vector<int> g[N];
int p[M];
int cnt[N];

int dfs(int v,int par)
{
    int&res=cnt[v]=1;
    for(int to:g[v])
        if(to!=par)
            res+=dfs(to,v);
    return res;
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
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
            cnt[i]=cnt[i]*(n-cnt[i]);
        swap(cnt[1],cnt[n]);
        sort(cnt+1,cnt+n);
//        for(int i=1;i<=n-1;i++)
//            cout<<cnt[i]<<" ";
//        cout<<endl;

        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>p[i];
        for(int i=m+1;i<=n-1;i++)
            p[i]=1;
        m=max(m,n-1);
        sort(p+1,p+m+1);
        for(int i=n;i<=m;i++)
            p[n-1]=p[n-1]*p[i]%MOD;
//        for(int i=1;i<=n-1;i++)
//            cout<<p[i]<<" ";
//        cout<<endl;

        int ans=0;
        for(int i=1;i<=n-1;i++)
            ans+=cnt[i]%MOD*p[i]%MOD;
        cout<<ans%MOD<<"\n";
    }
}