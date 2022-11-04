#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long ans=0,f[2010][2010];
int n,k;


int main()
{int i,j,p;
 
 scanf("%d%d",&k,&n);
 
 for(i=1;i<=k;i++) f[1][i]=1;
 
 for(i=1;i<=n;i++)
   for(j=1;j<=k;j++)
   {p=j;
    while(p<=k)
    {f[i+1][p]+=f[i][j];
     f[i+1][p]%=1000000007;
     p+=j;
    }
   }
 
 ans=0;
 for(i=1;i<=k;i++)
 {ans+=f[n][i];
  ans%=1000000007;
 }
 
 cout<<ans<<endl;
 
 return 0;
}