#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int d[maxn+5][maxn+5];
int dep[maxn+5];

void dfs(int now)
{
    for(auto v: e[now]) 
    {
        if(dep[v]==-1) {dep[v]=dep[now]+1; dfs(v);}
        else if((dep[now]+dep[v])%2==0) {puts("NO"); exit(0);}
    }
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    memset(d,63,sizeof d);
    rep(i,1,n) d[i][i]=0;
    rep(i,1,m)
    {
        int u,v,b; scanf("%d%d%d",&u,&v,&b);
        e[u].pb(v); e[v].pb(u);
        if(b==0) d[u][v]=d[v][u]=1;
        else d[u][v]=1,d[v][u]=-1;
    }
    memset(dep,-1,sizeof dep); dep[1]=0;
    dfs(1);
    rep(k,1,n) rep(i,1,n) rep(j,1,n) if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
    rep(i,1,n) if(d[i][i]<0) return puts("NO"),0;
    int st=1,ed=1;
    rep(i,1,n) rep(j,1,n) if(d[i][j]>d[st][ed]) st=i,ed=j;
    puts("YES");
    printf("%d\n",d[st][ed]);
    rep(i,1,n) printf("%d%c",d[st][i]," \n"[i==n]);
    return 0;
}