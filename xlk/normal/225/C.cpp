#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char s[1020][1020];
int f[1020];
int g[1020];
int c[1020];
int d[1020];
int n,m,x,y;
int main()
{
	cin>>n>>m>>x>>y;
	for(int i=0;i<n;i++)
		scanf("%s",s[i]+1);
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')
				d[j]++;
			else
				c[j]++;
	for(int j=1;j<=m;j++)
		c[j]+=c[j-1],d[j]+=d[j-1];
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	f[0]=0;
	g[0]=0;
	for(int j=1;j<=m;j++)
	{
		for(int i=x;i<=y&&i<=j;i++)
			f[j]=min(f[j],g[j-i]+d[j]-d[j-i]);
		for(int i=x;i<=y&&i<=j;i++)
			g[j]=min(g[j],f[j-i]+c[j]-c[j-i]);
	}
	printf("%d",min(f[m],g[m]));
	return 0;
}