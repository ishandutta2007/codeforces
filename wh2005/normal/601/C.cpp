#include<bits/stdc++.h>
using namespace std;
#define db double
const int N = 109;
const int M = 1009;
int n,m,a[N],s;
db f[N][M*N],sum[N*M];
int min(int x,int y){
    return x<y?x:y;
}
int main(){
    scanf("%d%d",&n,&m);s=0;db d=1.0/(m-1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
    memset(f,0,sizeof(f));
    memset(sum,0,sizeof(sum));
    f[0][0]=1.0;sum[0]=1.0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i*m;j++){
            int l=max(i-1,j-m),r=min((i-1)*m,j-1);
            f[i][j]=sum[r]*d;
            if(l) f[i][j]-=sum[l-1]*d;
            if(j-a[i]>=l&&j-a[i]<=r)
                f[i][j]-=f[i-1][j-a[i]]*d;
        }
        sum[0]=0;
        for(int j=1;j<=min(i*m,s);j++) sum[j]=sum[j-1]+f[i][j]; 
    }
    db p=0;            
    for(int j=n;j<=s-1;j++) p+=f[n][j];
    printf("%.12lf",p*(m-1)+1);
    return 0;
}