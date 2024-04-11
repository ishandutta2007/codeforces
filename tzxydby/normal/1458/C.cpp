#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=100005;
int n,m,a[N][N][3],b[N][N],f[3],g[3],p[3];
char s[M];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j][2]);
			a[i][j][2]--,a[i][j][0]=i,a[i][j][1]=j;
		}
	}
	for(int i=0;i<3;i++)
		f[i]=0,g[i]=i;
	scanf("%s",s);
	for(int i=0;i<m;i++)
	{
		if(s[i]=='R') f[1]++;
		if(s[i]=='L') f[1]--;
		if(s[i]=='D') f[0]++;
		if(s[i]=='U') f[0]--;
		if(s[i]=='I') swap(f[1],f[2]),swap(g[1],g[2]);
		if(s[i]=='C') swap(f[0],f[2]),swap(g[0],g[2]);
	}
	for(int i=0;i<3;i++)
		f[i]=(f[i]%n+n)%n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<3;k++)
				p[k]=(a[i][j][g[k]]+f[k])%n;
			b[p[0]][p[1]]=p[2];
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			printf("%d%c",b[i][j]+1," \n"[j==n-1]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}