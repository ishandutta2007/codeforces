#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=100000;
vector <vector <int> > a;
vector <bool> used;
int u[maxn][20];
vector <int> timein;
vector <int> timeout;
vector <int> corn;
int timer=0;
void dfs(int x,int pr=(-1))
{
    timein[x]=timer;
    ++timer;
    used[x]=true;
    u[x][0]=pr;
    for(int i=1;i<20;++i)
    {
        if(u[x][i-1]==(-1))
        {
            u[x][i]=(-1);
        }
        else{
            u[x][i]=u[u[x][i-1]][i-1];
        }
    }
    for(auto v:a[x])
    {
        if(!used[v]) {
            corn[v] = corn[x] + 1;
            dfs(v, x);
        }
    }
    ++timer;
    timeout[x]=timer;
}
bool pred(int x,int y)
{
    if(x==(-1))
    {
        return true;
    }
    if(y==(-1))
    {
        return false;
    }
    if(timein[x]<=timein[y] && timeout[x]>=timeout[y])
    {
        return true;
    }
    return false;
}
int lca(int x,int y)
{
    if(pred(x,y))
    {
        return x;
    }
    if(pred(u[x][0],y))
    {
        return u[x][0];
    }
    for(int i=1;i<20;++i)
    {
        if(pred(u[x][i],y))
        {
            return lca(u[x][i-1],y);
        }
    }
}
int dist(int x,int y)
{
    return corn[x]+corn[y]-2*corn[lca(x,y)];
}
int go(int x,int y)
{
    return x<=y && !((x-y) & 1);
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    a.resize(n);
    corn.resize(n);
    corn[0]=0;
    int x,y;
    for(int i=0;i<(n-1);++i)
    {
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    used.resize(n);
    timein.resize(n);
    timeout.resize(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    dfs(0);
    int q;
    cin>>q;
    for(int i=0;i<q;++i)
    {
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        x--;y--;a--;b--;
        if(go(dist(a,b),k) || go((dist(a,x)+dist(b,y)+1),k) || go(dist(a,y)+dist(b,x)+1,k))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}