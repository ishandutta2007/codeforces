#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5010,INF=1e6;

vector<pair<int,int>> g[N];
int val[N];
int a[N],b[N],x[N];

bool upd(int v,int p,int d,int x)
{
    if(v==d)
        return true;
    for(pii to:g[v])
        if(to.x!=p&&upd(to.x,v,d,x))
        {
            val[to.y]=x;
            return true;
        }
    return false;
}

bool check(int v,int p,int d,int x,bool&eq)
{
    if(v==d)
        return true;
    for(pii to:g[v])
        if(to.x!=p&&check(to.x,v,d,x,eq))
        {
            if(val[to.y]==x)
                eq=true;
            return true;
        }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        val[i]=INF;
        g[x].emplace_back(y,i);
        g[y].emplace_back(x,i);
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i]>>x[i];
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            if(x[i]>x[j])
                swap(a[i],a[j]),
                swap(b[i],b[j]),
                swap(x[i],x[j]);
    for(int i=1;i<=m;i++)
        upd(a[i],0,b[i],x[i]);
    for(int i=1;i<=m;i++)
    {
        bool eq=false;
        check(a[i],0,b[i],x[i],eq);
        if(!eq)
            cout<<-1,exit(0);
    }
    for(int i=1;i<=n-1;i++)
        cout<<val[i]<<" ";
}