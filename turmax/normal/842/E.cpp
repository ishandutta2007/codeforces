#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector <int> ch[maxn];
int pr[maxn];
int u[maxn][20];
int tin[maxn];
int tout[maxn];
int corn[maxn];
int timer=0;
void dfs(int x)
{
    tin[x]=timer;++timer;
    for(int i=1;i<20;++i) u[x][i]=u[u[x][i-1]][i-1];
    for(auto v:ch[x])
    {
        pr[v]=x;u[v][0]=x;corn[v]=corn[x]+1;dfs(v);
    }
    ++timer;tout[x]=timer;
}
bool pred(int x,int y)
{
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
int lca(int x,int y)
{
    if(pred(x,y)) return x;
    if(pred(pr[x],y)) return pr[x];
    for(int i=1;i<20;++i)
    {
        if(pred(u[x][i],y)) return lca(u[x][i-1],y);
    }
    assert(false);
}
int dist(int x,int y)
{
    return corn[x]+corn[y]-2*corn[lca(x,y)];
}
int c1,c2,l;
int up(int x,int d)
{
    if(d==0) return x;
    if(d==1) return pr[x];
    for(int i=1;i<20;++i) if((1<<i)>d)
    {
        return up(u[x][i-1],d-(1<<(i-1)));
    }
}
int ser(int x,int y)
{
    int o=dist(x,y);
    if(corn[x]>=corn[y])
    {
        return up(x,o/2);
    }
    else
    {
        return up(y,o/2);
    }
}
int fin(int x,int y)
{
    if(!pred(y,x)) return pr[y];
    return up(x,corn[x]-corn[y]-1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>pr[i];pr[i]--;ch[pr[i]].push_back(i);
    }
    dfs(0);
    c1=0,c2=0,l=0;
    int sz[3]={0};sz[1]=1;
    map <int,int> u;
    for(int i=1;i<=n;++i)
    {
        int d1=dist(i,c1);int d2=dist(i,c2);
        //cout<<d1<<" d1 "<<d2<<" d2 "<<endl;
        if(max(d1,d2)<l) {cout<<sz[0]+sz[1]+sz[2]<<endl;continue;}
        if(max(d1,d2)==l)
        {
             if(d1<d2) sz[0]++;
             else if(d1==d2) {sz[1]++;int o=ser(c1,c2);int v=fin(i,o);u[v]++;}
             else sz[2]++;
        }
        else
        {
            if(d1==(l+1) && d2<(l+1))
            {
                c2=i;sz[0]+=sz[1];sz[1]=0;sz[2]=1;
            }
            else if(d1<(l+1) && d2==(l+1))
            {
                c1=i;sz[2]+=sz[1];sz[1]=0;sz[0]=1;
            }
            else
            {
                int o=ser(c1,c2);int key=fin(i,o);
                c2=i;sz[0]+=sz[1];sz[0]+=sz[2];sz[0]-=u[key];sz[1]=0;sz[2]=1;
            }
            u.clear();
            ++l;
        }
        //cout<<c1<<' '<<c2<<endl;
        //cout<<sz[0]<<' '<<sz[1]<<' '<<sz[2]<<endl;
        cout<<sz[0]+sz[1]+sz[2]<<endl;
    }
    return 0;
}
/*
5
1 1 1 1 4
*/
/*
9
1 1 1 1 5 5 2 4 1
*/