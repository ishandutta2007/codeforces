#include<stdio.h>
#define MOD 1000000007

const int MN = 100010;

int N;
int p[MN],l[MN],ans;

int par(int n){
    if(p[n]==-1)return n;
    int pp=par(p[n]);
    l[n]+=l[p[n]];
    l[n]%=MOD;
    return p[n]=pp;
}

int main(){
    int i,j,k,a,b,c;
//    freopen("input","r",stdin);
    scanf("%d",&N);
    for(i=0;i<N;i++)p[i]=-1;
    for(i=0;i<N;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d%d",&a,&b),--a;
            if(b<0)b+=MOD;
            c=par(a);
            p[c]=i;
            l[c]=(l[a]+b)%MOD;
            ans+=l[c];
            ans%=MOD;
        }
    }
    printf("%d",ans);
    return 0;
}