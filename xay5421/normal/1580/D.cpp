// author: xay5421
// created: Sat Sep  4 16:48:03 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=4005;
LL f[N][N],g[N];
int a[N];
int n,m,tot;
int dp(int l,int r){
    int u=++tot,pos=l;
    if(l==r){
        f[u][0]=0;
        f[u][1]=1ll*(m-1)*a[l];
        return u;
    }
    for(int i=l+1;i<=r;i++){
        if(a[i]<a[pos]){
            pos=i;
        }
    }
    f[u][0]=0;f[u][1]=1ll*(m-1)*a[pos];
    int len=1;
    if(pos!=l){
        memset(g,-0x3f,sizeof(g));
        int x=dp(l,pos-1);
        for(int i=0;i<=pos-l;i++){
            for(int j=0;j<=len;j++){
                g[i+j]=max(g[i+j],f[x][i]+f[u][j]-2ll*a[pos]*i*j);
            }
        }
        memcpy(f[u],g,sizeof(f[u]));
        len+=pos-l;
    }
    if(pos!=r){
        memset(g,-0x3f,sizeof(g));
        int x=dp(pos+1,r);
        for(int i=0;i<=r-pos;i++){
            for(int j=0;j<=len;j++){
                g[i+j]=max(g[i+j],f[x][i]+f[u][j]-2ll*a[pos]*i*j);
            }
        }
        memcpy(f[u],g,sizeof(f[u]));
    }
    return u;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d",&a[i]);
    int u=dp(1,n);
    printf("%lld\n",f[u][m]);
    return 0;
}