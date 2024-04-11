#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510,MOD=998244353;

int a[2*N][N];
vector<int> pos[N];
vector<int> g[2*N];
int col[2*N];

bool dfs(int v,int c)
{
    if(col[v])
        return false;
    col[v]=c;
    for(int to:g[v])
        dfs(to,-c);
    return true;
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
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        for(int i=1;i<=2*n;i++)
            col[i]=0;
        while(true)
        {
            int cur=0;
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                    pos[k].clear();
                for(int i=1;i<=2*n;i++)
                    if(!col[i])
                        pos[a[i][j]].push_back(i);
                for(int k=1;k<=n;k++)
                    if(pos[k].size()==1)
                    {
                        cur=pos[k][0];
                        break;
                    }
                if(cur)
                    break;
            }
            if(!cur)
                break;
            col[cur]=1;
            for(int i=1;i<=2*n;i++)
                for(int j=1;j<=n;j++)
                    if(!col[i]&&a[i][j]==a[cur][j])
                        col[i]=-1;
        }
        for(int i=1;i<=2*n;i++)
            g[i].clear();
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
                pos[k].clear();
            for(int i=1;i<=2*n;i++)
                if(!col[i])
                    pos[a[i][j]].push_back(i);
            for(int k=1;k<=n;k++)
                if(pos[k].size()==2)
                {
                    int u=pos[k][0],
                        v=pos[k][1];
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
        }
        int ans=1;
        for(int i=1;i<=2*n;i++)
            if(dfs(i,1))
                ans=ans*2%MOD;
        cout<<ans<<"\n";
        for(int i=1;i<=2*n;i++)
            if(col[i]==1)
                cout<<i<<" ";
        cout<<"\n";
    }
}