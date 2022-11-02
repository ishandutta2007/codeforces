#include<bits/stdc++.h>
using namespace std;
#define re register
const int N = 100009;
const int M = 409;
int n,m,unit,bl[N],a[N];
int pre[M][M],bon[M][M],jump[M][M];
void renew(int x){
    for(re int i=min(n,x*unit);i>=(x-1)*unit+1;--i){
        int t=i-(x-1)*unit;
        if(i+a[i]>n) pre[x][t]=-1,bon[x][t]=1,jump[x][t]=i;
        else if(i+a[i]>x*unit) pre[x][t]=i+a[i],bon[x][t]=1,jump[x][t]=i+a[i];
        else pre[x][t]=pre[x][t+a[i]],bon[x][t]=bon[x][t+a[i]]+1,jump[x][t]=jump[x][t+a[i]];
    }
}
void query(int x){
    int ans=0,pos=x;
    while(x!=-1){
        int t=x-(bl[x]-1)*unit;
        if(pre[bl[x]][t]==-1) pos=jump[bl[x]][t];
        ans+=bon[bl[x]][t];x=pre[bl[x]][t];
    }
    printf("%d %d\n",pos,ans);
}
int main(){
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=n;++i) scanf("%d",&a[i]);
    unit=sqrt(n);for(int i=1;i<=n;++i) bl[i]=(i-1)/unit+1;
    for(re int i=1;i<=bl[n];++i) renew(i);
    for(re int i=1;i<=m;++i){
        int opt,x,y;scanf("%d",&opt);
        if(opt==0){scanf("%d%d",&x,&y);a[x]=y;renew(bl[x]);}
        else{scanf("%d",&x);query(x);}
    }
    return 0;
}