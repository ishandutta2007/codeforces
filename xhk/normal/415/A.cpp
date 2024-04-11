#include<cstdio>
#include<iostream>
using namespace std;

int n,m,a[110];

int main()
{int i,j,x;
 
 scanf("%d%d",&n,&m);
 
 for(i=1;i<=m;i++)
 {scanf("%d",&x);
  for(j=x;j<=n;j++)
    if(a[j]==0) a[j]=x;
 }
 
 for(i=1;i<=n;i++)
   cout<<a[i]<<" ";
 
 cout<<endl;
 
 return 0;
}