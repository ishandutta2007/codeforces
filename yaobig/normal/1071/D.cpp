#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

bool np[maxn+5]={1,1};
int id[maxn+5],p[10]={0,2,3,5,7,11,13,17};
vi fac[maxn+5];
int idx[maxn+5],idy[50000+5],nx,ny;
int dis[305][1005];

void dfs(int dep,int d,int x,int y,int k1,int k2)
{
    if(!idx[x]) idx[x]=++nx;
    if(!idy[y]) idy[y]=++ny;
    if(dis[idx[x]][idy[y]]<=d) return;
    if(dep>7) {dis[idx[x]][idy[y]]=d;return;}
    rep(i,0,k1) if(x<=maxn)
    {
        rep(j,0,k2) if(d+abs(i-j)<=10) dfs(dep+1,d+abs(i-j),x,y*(1+j),i,j);
        x*=p[dep];
    }
}
int main()
{
    rep(i,1,maxn) if(!np[i])
    {
        fac[i].pb(1);
        for(int j=i*2;j<=maxn;j+=i)
        {
            np[j]=1;
            int x=j,c=0;
            while(x%i==0) c++,x/=i;
            fac[j].pb(c);
        }
    }
    rep(i,1,maxn)
    {
        sort(fac[i].begin(),fac[i].end(),greater<int>());
        id[i]=1;
        int l=fac[i].size();
        rep(j,0,l-1) rep(k,1,fac[i][j]) id[i]*=p[j+1];
    }
    memset(dis,63,sizeof dis);
    dfs(1,0,1,1,20,22);
    int T; scanf("%d",&T);
    while(T--)
    {
        int a,b; scanf("%d%d",&a,&b);
        int ans=1000;
        rep(i,1,ny) ans=min(ans,dis[idx[id[a]]][i]+dis[idx[id[b]]][i]);
        printf("%d\n",ans);
    }
    return 0;
}