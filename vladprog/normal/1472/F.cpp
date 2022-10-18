#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int M=2e5+100;

int r[M],c[M];
bool b[3][3*M];

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
        map<int,int> compress;
        for(int i=1;i<=m;i++)
            cin>>r[i]>>c[i],
            compress[c[i]];
        compress[n+1];
        int last=0,delta=0;
        for(auto&p:compress)
        {
            p.y=p.x-delta;
            if(p.y-last>3)
                delta+=(p.y-last-3)/2*2,
                p.y=p.x-delta;
            last=p.y;
        }
        for(int i=1;i<=m;i++)
            c[i]=compress[c[i]];
        n=compress[n+1]-1;
        for(int i=0;i<=n+1;i++)
            b[1][i]=b[2][i]=true;
        for(int i=1;i<=m;i++)
            b[r[i]][c[i]]=false;
        b[1][n+1]=b[2][n+1]=false;
        bool ok=true;
        for(int i=1;i<=n;i++)
            if(b[1][i]&&!b[2][i])
            {
                if(!b[1][i+1])
                {
                    ok=false;
                    break;
                }
                b[1][i+1]=false;
            }
            else if(b[2][i]&&!b[1][i])
            {
                if(!b[2][i+1])
                {
                    ok=false;
                    break;
                }
                b[2][i+1]=false;
            }
        cout<<(ok?"YES\n":"NO\n");
    }
}