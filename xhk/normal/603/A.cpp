#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,ans;
int f[200010][5][5],b[200010];
char a[200010];

int main()
{int i,j,x1,x2;
 
 scanf("%d",&n);
 scanf("%s",a+1);
 for(i=1;i<=n;i++)
 	b[i]=a[i]-48;
 
 f[1][b[1]][0]=1;
 f[1][b[1]^1][1]=1;
 for(i=2;i<=n;i++)
 {	f[i][b[i]][0]=max(f[i-1][b[i]][0],f[i-1][b[i]^1][0]+1);
 	f[i][b[i]^1][0]=f[i-1][b[i]^1][0];
 	
	x1=max(f[i-1][b[i]][1]+1,f[i-1][b[i]^1][1]);
	x2=max(f[i-1][b[i]][0]+1,f[i-1][b[i]^1][0]);
	f[i][b[i]^1][1]=max(x1,x2);
	f[i][b[i]][1]=max(f[i-1][b[i]][1],f[i-1][b[i]][0]);
	
	x1=max(f[i-1][b[i]^1][2]+1,f[i-1][b[i]^1][1]+1); 	 	
  	x2=max(f[i-1][b[i]][2],f[i-1][b[i]][1]);
  	f[i][b[i]][2]=max(x1,x2);
  	f[i][b[i]^1][2]=max(f[i-1][b[i]^1][1],f[i-1][b[i]^1][2]);
 }
 x1=max(f[n][0][1],f[n][0][2]);
 x2=max(f[n][1][1],f[n][1][2]);
 ans=max(x1,x2);
 cout<<ans<<endl;
 
 return 0;
}