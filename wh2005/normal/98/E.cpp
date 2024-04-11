#include<bits/stdc++.h>
using namespace std;
#define db double
const int N = 1009; 
db f[N][N];
db dfs(int n,int m){
    db x=n,y=m;
    if(f[n][m]>0) return f[n][m];
    if(n==0){return 1.0/(n+m+1);}
    if(m==0){return 1.0;}
    db a=y/(y+1)*(1-dfs(m-1,n));
    db c=1.0/(y+1)+y/(y+1)*(1-dfs(m-1,n));
    db b=1.0;
    db d=1.0-dfs(m,n-1);
    db p=(d-b)/(a-b-c+d);
    f[n][m]=p*a+(1.0-p);
    return f[n][m];
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) f[i][j]=-1.0;
    db ans=dfs(n,m);
    printf("%.9lf %.9lf\n",ans,1-ans);
    return 0;
}