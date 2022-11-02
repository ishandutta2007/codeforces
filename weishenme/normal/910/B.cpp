#include<bits/stdc++.h>
using namespace std;
int f[10][10],n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for (int i=0;i<=4;i++)
	 for (int j=0;j<=2;j++)
	  for (int k=0;k<=i;k++)
	   if (k*a<=n)f[i][j]=min(f[i][j],f[max(i-k,0)][max(j-(n-k*a)/b,0)]+1);
	printf("%d",f[4][2]);   
}