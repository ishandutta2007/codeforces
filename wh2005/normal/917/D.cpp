#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int N = 8e3+9;
int qpow(int x,int y){if(y<0) return 0;int t=1;while(y){if(y&1) t=1ll*t*x%mod;x=1ll*x*x%mod,y>>=1;}return t;}
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
int sz[N],h[N][2];
vector<int >f[N][2];
void dfs(int u,int fa){
    sz[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs(v,u);sz[u]+=sz[v];
    }
    f[u][0].resize(sz[u]+5);
    f[u][1].resize(sz[u]+5);
    return ;
}
void dfs2(int u,int fa){
    sz[u]=1;
    f[u][0][1]=1;
    f[u][1][1]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs2(v,u);
    }
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        for(int j=sz[u];j>=0;j--){
            for(int k=sz[v];k>=0;k--){
                //
                h[j+k][0]=(h[j+k][0]+1ll*f[u][0][j]*f[v][1][k]%mod)%mod;
                h[j+k][1]=(h[j+k][1]+1ll*f[u][1][j]*f[v][1][k]%mod)%mod;
                //
                if(j+k) h[j+k-1][0]=(h[j+k-1][0]+1ll*f[u][0][j]*f[v][0][k]%mod)%mod;
                if(j+k) h[j+k-1][1]=1ll*(h[j+k-1][1]+1ll*f[u][1][j]*f[v][0][k]%mod+1ll*f[u][0][j]*f[v][1][k]%mod)%mod;

            }
        }
        sz[u]+=sz[v];
        for(int j=sz[u];j>=0;j--){
            f[u][0][j]=h[j][0];h[j][0]=0;
            f[u][1][j]=h[j][1];h[j][1]=0;
        }
    }
    return ;
}

int F[N],fac[N],inv[N];
int C(int x,int y){
    if(x<0||y<x) return 0;
    return 1ll*fac[y]*inv[x]%mod*inv[y-x]%mod;
}

int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    fac[0]=inv[0]=inv[1]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    for(int i=2;i<=n;i++) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
    for(int i=1;i<=n;i++) inv[i]=1ll*inv[i-1]*inv[i]%mod;
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int i=2;i<=n;i++) F[n-i]=1ll*f[1][1][i]*qpow(n,i-2)%mod;
    F[n-1]=1;
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=i;j<n;j++){
            int k=(((j^i)&1)?(mod-1):1);
            (ans+=1ll*k*C(i,j)%mod*F[j]%mod)%=mod;
        }
        printf("%d ",ans);
    }
    puts("");
    return 0;
}
/*

prufer  $n$  $n^{n-2}$ 
 prufer 

 $x$ 


$\prod $


 f[i][j][0/1]  i  j  i 


*/