#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int f[220][40020][2];
int s[220];
int h[220];
int n,a,b,z;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	scanf("%d %d",&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",h+i);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+h[i];
	memset(f,0x3f,sizeof f);
	z=0x3f3f3f3f;
	f[0][0][0]=0;
	f[0][0][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=max(s[i]-b,h[i]);j<=min(a,s[i]);j++)
			f[i][j][0]=min(f[i-1][j-h[i]][0],f[i-1][j-h[i]][1]+min(h[i],h[i-1]));
		for(int j=s[i]-b;j<=min(a,s[i]);j++)
			f[i][j][1]=min(f[i-1][j][1],f[i-1][j][0]+min(h[i],h[i-1]));
	}
	for(int i=max(s[n]-b,0);i<=a;i++)
		z=min(z,min(f[n][i][0],f[n][i][1]));
	if(z==0x3f3f3f3f)
		puts("-1");
	else
		printf("%d",z);
	return 0;
}