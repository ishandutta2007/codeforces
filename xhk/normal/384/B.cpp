#include<cstdio>
#include<iostream>
using namespace std;

int n,m,k,p,g[1100][11];

int main()
{int i,j,ans=0;
 
 scanf("%d%d%d",&n,&m,&k);
 
 for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
     scanf("%d",&g[i][j]);
 
 ans=m*(m-1)/2;
 
 printf("%d\n",ans);
 
 for(i=1;i<=m;i++)
   for(j=i+1;j<=m;j++)
   {if(k==0)
      printf("%d %d\n",i,j);
    else
      printf("%d %d\n",j,i);
   }
   
 return 0;
}