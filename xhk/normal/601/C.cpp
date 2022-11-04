#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int a[1010];
double ans;
double f[110][110010],g[110][110010];

int main()
{int i,j,s=0;
 
 scanf("%d%d",&n,&m);
 
 for(i=1;i<=n;i++)
 {  scanf("%d",&a[i]);
    a[i]=m-a[i]+1;
 }
 
 f[0][0]=m-1;
 g[0][0]=m-1;
 for(i=1;i<=m;i++)
    g[0][i]=m-1;
 for(i=1;i<=n;i++)
 {  g[i][0]=0;
    for(j=1;j<=i*m;j++)
    {   f[i][j]=g[i-1][j-1]-(j>=m+1?g[i-1][j-m-1]:0);
        if(j>=a[i]) f[i][j]-=f[i-1][j-a[i]];
        f[i][j]=f[i][j]/(double)(m-1);
        //printf("%d %d %.5lf\n",i,j,f[i][j]);
        g[i][j]=g[i][j-1]+f[i][j];
    }
    for(j=i*m+1;j<=i*m+m;j++)
        g[i][j]=g[i][j-1];
 }
 
 for(i=1;i<=n;i++)
    s+=a[i];
 
 //cout<<s<<endl;   
    
 ans=1;
 for(i=s+1;i<=n*m;i++)
    ans+=f[n][i];
 
 //for(i=0;i<=n*m;i++)
 // printf("%d %.5lf\n",i,g[n][i]);
 
 printf("%.15lf\n",ans);
 
 return 0;
}