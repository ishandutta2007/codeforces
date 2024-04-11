#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vector<pii> e[maxn+5];
ll dis[maxn+5][4];
bool mark[maxn+5][4];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        e[u].pb({v,w});
        e[v].pb({u,w});
    }
    memset(dis,63,sizeof dis);
    priority_queue<pair<ll,pii> > Q;
    dis[1][0]=0;
    Q.push({-0ll,{1,0}});
    while(Q.size())
    {
        auto [d,it]=Q.top(); Q.pop();
        int now=it.FI,s=it.SE;
        if(mark[now][s]) continue;
        mark[now][s]=1;
        for(auto [v,w]: e[now])
        {
            if(dis[v][s]>dis[now][s]+w) 
            {
                dis[v][s]=dis[now][s]+w;
                Q.push({-dis[v][s],{v,s}});
            }
            if((s&1)==0)
            {
                if(dis[v][s|1]>dis[now][s]+w*2) 
                {
                    dis[v][s|1]=dis[now][s]+w*2;
                    Q.push({-dis[v][s|1],{v,s|1}});
                }
            }
            if((s&2)==0)
            {
                if(dis[v][s|2]>dis[now][s]) 
                {
                    dis[v][s|2]=dis[now][s];
                    Q.push({-dis[v][s|2],{v,s|2}});
                }
            }
            if(s==0)
            {
                if(dis[v][3]>dis[now][s]+w)
                {
                    dis[v][3]=dis[now][s]+w;
                    Q.push({-dis[v][3],{v,3}});
                }
            }
        }
    }
    rep(i,2,n) printf("%lld%c",dis[i][3]," \n"[i==n]);
    return 0;
}