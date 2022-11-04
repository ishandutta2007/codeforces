#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,k,s,m,ans,inf=1000000000;
int a[200],f[160][12010];

int main()
{int i,j,p;
 
 scanf("%d%d%d",&n,&k,&s);
 
 for(i=1;i<=n;i++)
 	scanf("%d",&a[i]);
 
 m=min(n*(n+1)/2,k*(k+1)/2+s);
 
 memset(f,-1,sizeof(f));
 
 f[0][0]=0;
 for(i=1;i<=n;i++)
 	for(j=i;j>=1;j--)
 		for(p=0;p<=m-i;p++)
 			if(f[j-1][p]>=0 && (f[j][p+i]==-1 || f[j-1][p]+a[i]<f[j][p+i]))
 			{	f[j][p+i]=f[j-1][p]+a[i];
 				//cout<<j<<" "<<p+i<<" "<<f[j-1][p]<<" "<<a[i]<<" "<<f[j][p+i]<<endl;
 			}
 
 ans=inf;
 for(i=1;i<=m;i++)
 	if(f[k][i]>=0)
 	{	//cout<<f[k][i]<<endl;
	 	ans=min(ans,f[k][i]);
	}
	
 cout<<ans<<endl;
 
 return 0;
}