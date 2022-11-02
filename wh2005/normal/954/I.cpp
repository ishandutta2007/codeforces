#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define ri int
#define ll long long
const int N=262144;
const ll mod=998244353;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t,ll res=1){for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}
vector<int> W[23];
int r[N];
void rev(int limit){
    for(ri i=0;i<limit;i+=2){
        r[i]=r[i>>1]>>1;
        r[i|1]=(r[i>>1]>>1)|(limit>>1);
    }
}
void init(){
    int d=log(N)/log(2)+0.5;
    for(ri i=1;i<=d;++i){
        W[i].resize(1<<i);
        W[i][0]=1,W[i][1]=ksm(3,mod-1>>i);
        for(ri j=2;j<(1<<i);++j) W[i][j]=1ll*W[i][j-1]*W[i][1]%mod;
    }
}
void DFT(int limit,int *f,int flag){
    for(ri i=1;i<limit;++i) if(r[i]>i) swap(f[i],f[r[i]]);
    for(ri l=1,t=1;l<limit;l<<=1,++t) for(ri i=0;i<limit;i+=l<<1) for(ri j=0,*w=&W[t][0];j<l;++j,++w){
        int tmp=1ll*(*w)*f[i+j+l]%mod;
        f[i+j+l]=dec(f[i+j],tmp);
        f[i+j]=add(f[i+j],tmp);
    }
    if(flag==-1){
        reverse(f+1,f+limit);
        ll inv=ksm(limit,mod-2);
        for(ri i=0;i<limit;++i) f[i]=f[i]*inv%mod;
    }
}
const int MAXN=125005;
int dp[6][6][N],f[N],g[N],n,m;
char a[N],b[N],op[6]={'a','b','c','d','e','f'};
int fa[6];
int find(int k){return k==fa[k]?fa[k]:fa[k]=find(fa[k]);}
void merge(int u,int v){
    u=find(u),v=find(v);
    if(u==v) return ;
    fa[v]=u;
}
int main(){
    init();
    scanf("%s%s",a,b);
    n=strlen(a)-1,m=strlen(b)-1;
    int limit=1;for(;limit<=n+m;limit<<=1);
    rev(limit);
    for(ri s=0;s<6;++s) for(ri t=0;t<6;++t){
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
        for(ri i=0;i<=n;++i) if(a[i]==op[s]) f[i]=1;
        for(ri i=0;i<=m;++i) if(b[i]==op[t]) g[m-i]=1;
        DFT(limit,f,1),DFT(limit,g,1);
        for(ri i=0;i<limit;++i) f[i]=1ll*f[i]*g[i]%mod;
        DFT(limit,f,-1);
        for(ri i=0;i<=n;++i) dp[s][t][i]=!!f[i+m];
    }
    for(ri i=0;i<=n-m;++i){
        for(ri j=0;j<6;++j) fa[j]=j;
        for(ri s=0;s<6;++s) for(ri t=0;t<6;++t) if(dp[s][t][i]) merge(s,t);
        int ans=6;
        for(ri s=0;s<6;++s) if(find(s)==s) --ans;
        printf("%d ",ans);
    }
}