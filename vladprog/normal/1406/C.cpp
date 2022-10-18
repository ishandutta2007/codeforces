#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<int> g[N];
int cnt[N];
int par[N];

int calc(int v,int p)
{
    par[v]=p;
    int&res=cnt[v]=1;
    for(int to:g[v])
        if(to!=p)
            res+=calc(to,v);
    return res;
}

int leaf(int v,int p)
{
    for(int to:g[v])
        if(to!=p)
            return leaf(to,v);
    return v;
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
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        calc(1,0);
        pii c(n+1,-1);
        for(int v=1;v<=n;v++)
            if(cnt[v]*2>=n)
                c=min(c,pii(cnt[v],v));
        int v=c.y,k=c.x;
        int l=leaf(v,par[v]);
        if(c.x*2==n)
        {
            cout<<l<<" "<<par[l]<<"\n";
            cout<<l<<" "<<par[v]<<"\n";
        }
        else
        {
            cout<<l<<" "<<par[l]<<"\n";
            cout<<l<<" "<<par[l]<<"\n";
        }
    }
}