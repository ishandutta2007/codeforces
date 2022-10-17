#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int deg[1000005], now[1000005];
struct edge
{
    int u,v;
    bool del;
    bool operator < (const edge & e) const
    {
        return min(deg[u],deg[v]) > min(deg[e.u],deg[e.v]);
    }
}es[1000005];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    forij
    {
        int u,v;
        cin>>u>>v;
        es[i].u=u,es[i].v=v;
        ++deg[u],++deg[v];
    }
    forii now[i]=deg[i];
    sort(es+1,es+1+n);
    int ned = m-(m+n+1)/2, cnt = 0;
    forij
    {
        if(now[es[i].u]-1<(deg[es[i].u]+1)/2 || now[es[i].v]-1<(deg[es[i].v]+1)/2) continue;
        now[es[i].u]--,now[es[i].v]--,cnt++,es[i].del=1;
    }
    //cout<<ned<<" "<<cnt<<" "<<endl;
    assert(cnt>=ned);
    forii assert(now[i]>=(deg[i]+1)/2);
    cout<<m-cnt<<endl;
    forij if(!es[i].del) cout<<max(es[i].u,es[i].v)<<" "<<min(es[i].u,es[i].v)<<endl;
}