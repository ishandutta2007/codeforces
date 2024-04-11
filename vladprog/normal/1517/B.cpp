#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110,INF=1e18;

int b[N][N],ans[N][N];

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
            for(int j=1;j<=m;j++)
                cin>>b[i][j];
        for(int _=1;_<=m;_++)
        {
            tuple<int,int,int> mn{INF,INF,INF};
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(b[i][j])
                        mn=min(mn,tuple(b[i][j],i,j));
            for(int i=1;i<=n;i++)
            {
                int pos;
                if(i==get<1>(mn))
                    pos=get<2>(mn);
                else
                {
                    pair<int,int> mx={-1,-1};
                    for(int j=1;j<=m;j++)
                        if(b[i][j])
                            mx=max(mx,pair(b[i][j],j));
                    pos=mx.y;
                }
                ans[i][_]=b[i][pos];
                b[i][pos]=0;
            }
        }
        for(int i=1;i<=n;i++,cout<<"\n")
            for(int j=1;j<=m;j++)
                cout<<ans[i][j]<<" ";
    }
}