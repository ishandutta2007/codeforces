#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,P=998244353,gen=3,igen=(P+1)/gen;
inline int add(int x,int y){
    return x+y>=P?x+y-P:x+y;
}
inline int sub(int x,int y){
    return x-y<0?x-y+P:x-y;
}
inline int fpow(int x,int y){
    int ret=1; for (x%=P;y;y>>=1,x=1ll*x*x%P)
        if (y&1) ret=1ll*ret*x%P;
    return ret;
}
inline int sqr(int x){
    return 1ll*x*x%P;
}
namespace Poly{
    int rev[N];
    void init(int n){
        for (int i=0;i<n;i++)
            rev[i]=rev[i>>1]>>1|((i&1)?n>>1:0);
    }
    void ntt(int *f,int n,int flg){
        for (int i=0;i<n;i++) if (rev[i]<i) swap(f[i],f[rev[i]]);
        for (int k=1,len=2;len<=n;len<<=1,k<<=1){
            int wn=fpow(flg==1?gen:igen,(P-1)/len);
            for (int i=0;i<n;i+=len){
                for (int w=1,j=i;j<i+k;j++,w=1ll*w*wn%P){
                    int tmp=1ll*w*f[j+k]%P;
                    f[j+k]=sub(f[j],tmp),f[j]=add(f[j],tmp);
                }
            }
        }
        if (flg==-1){
            int inv=fpow(n,P-2);
            for (int i=0;i<n;i++) f[i]=1ll*f[i]*inv%P;
        }
    }
    void getinv(int *f,int n,int *G){
        if (n==1){G[0]=fpow(f[0],P-2);return;}
        getinv(f,(n+1)>>1,G); static int F[N];
        int limit=1; while(limit<=2*n)limit<<=1; init(limit);
        for (int i=0;i<limit;i++) F[i]=i>=n?0:f[i],G[i]=i>=n?0:G[i];
        ntt(F,limit,1),ntt(G,limit,1);
        for (int i=0;i<limit;i++) G[i]=1ll*G[i]*sub(2,1ll*F[i]*G[i]%P)%P;
        ntt(G,limit,-1);
        for (int i=n;i<limit;i++) G[i]=0;		
    }
    void getsqrt(int *f,int n,int *G){
        if (n==1){G[0]=1;return;}
        getsqrt(f,(n+1)>>1,G);
        int limit=1; while(limit<=n*2)limit<<=1; init(limit);
        static int F[N],H[N],iH[N];
        for (int i=0;i<limit;i++)
            G[i]=i>=n?0:G[i],F[i]=i>=n?0:f[i],H[i]=i>=n?0:2ll*G[i]%P;
        getinv(H,n,iH);
        ntt(F,limit,1),ntt(iH,limit,1),ntt(G,limit,1);
        for (int i=0;i<limit;i++) G[i]=1ll*add(F[i],sqr(G[i]))*iH[i]%P;
        ntt(G,limit,-1);
        for (int i=n;i<limit;i++) G[i]=0;		
    }
}
int n,m,g[N],f[N],sqg[N];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0,c;i<n;i++) scanf("%d",&c),g[c]=1;
    for (int i=1;i<=m;i++) g[i]=sub(P,4ll*g[i]%P);
    g[0]=1;
    Poly::getsqrt(g,m+1,sqg);
    sqg[0]++;
    Poly::getinv(sqg,m+1,f);
    for (int i=1;i<=m;i++) printf("%d\n",2ll*f[i]%P);
    return 0;
}