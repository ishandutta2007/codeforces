#include<stdio.h>
#include<iostream>
using namespace std;
int n,a[500020],w[500020],f[500020][20],g[500020][20];
long long z;
int mn(int x,int y)
{
	return w[x]<w[y]?x:y;
}
int qy(int x,int y)
{
	if(x<0)
		return 0;
	int p=__lg(y-x+1);
	return mn(f[x][p],f[y+1-(1<<p)][p]);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",a+i),a[n+i]=a[i];
	for(int i=0;i<2*n;i++)
		w[i]=i-a[i],f[i][0]=i;
	for(int j=1;j<20;j++)
		for(int i=0;i+(1<<j)<=2*n;i++)
			f[i][j]=mn(f[i][j-1],f[i+(1<<j-1)][j-1]);
	for(int i=0;i<2*n;i++)
		g[i][0]=qy(w[i],i);
	for(int j=1;j<20;j++)
		for(int i=0;i<2*n;i++)
			g[i][j]=g[g[i][j-1]][j-1];
	for(int i=n;i<2*n;i++)
	{
		if(i==2*n-1)
			i=2*n-1;
		z+=1+(w[i]>i-n+1);
		for(int j=20,p=i;j--;)
			if(w[g[p][j]]>i-n+1)
				p=g[p][j],z+=1<<j;
	}
	cout<<z;
}