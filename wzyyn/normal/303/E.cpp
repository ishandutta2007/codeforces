#include<bits/stdc++.h>
using namespace std;
int n,m,now,i,j,k,cnt;
int l[105],r[105],d[205];
double ans[105],f[105][105];
double len,ll,rr,p1,p2,p3;
void calc(int L,int R){
    int i,j,k;
    cnt=1;
    for(i=0;i<=n;++i)
    for(j=0;j<=n;++j)
    f[i][j]=0;
    f[0][0]=1;
    for(i=1;i<=n;++i)
    if(i!=now){
        if(r[i]<=L){++cnt;continue;}
        if(l[i]>=R)continue;
        len=r[i]-l[i];
        p1=(L-l[i])/len;
        p2=(R-L)/len;
        p3=(r[i]-R)/len;
        for(j=i;j>=0;--j)
        for(k=i-j;k>=0;--k){
            f[j+1][k]+=f[j][k]*p1;
            f[j][k+1]+=f[j][k]*p2;
            f[j][k]*=p3;
        }
    }
    for(i=0;i+cnt<=n;++i){
        for(j=n-i-cnt;j>=0;--j)
        ans[i+cnt]+=f[i][j]*(R-L)/(j+1),
        ans[i+j+1+cnt]-=f[i][j]*(R-L)/(j+1);
    }
}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&l[i],&r[i]);
        d[++m]=l[i];d[++m]=r[i];
    }
    sort(d+1,d+m+1);
    for(i=2,k=1;i<=m;++i)
    if(d[i]!=d[i-1]){
        ++k;
        if(k!=i)d[k]=d[i];
    }
    m=k;
    for(i=1;i<=n;++i){
        now=i;
        for(j=1;j<=n;++j)ans[j]=0;
        for(j=1;j<m;++j)
        if(l[i]<=d[j]&&r[i]>=d[j+1])
        calc(d[j],d[j+1]);
        for(j=1;j<=n;++j)ans[j]+=ans[j-1];
        for(j=1;j<=n;++j)printf("%.6lf ",ans[j]/(r[i]-l[i]));printf("\n");
    }
}
//