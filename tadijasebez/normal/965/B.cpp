#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=105;
int a[N][N],b[N][N],c[N][N],n,m;
char s[N][N];
void Add(int d[N][N]){ for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];}
int Get(int d[N][N], int x1, int y1, int x2, int y2)
{
	x1--;y1--;
	if(x1<0) x1=0;
	if(y1<0) y1=0;
	if(x2>n) x2=n;
	if(y2>m) y2=m;
	return d[x2][y2]+d[x1][y1]-d[x2][y1]-d[x1][y2];
}
int main()
{
	int i,j,k;
	scanf("%i %i",&n,&k);m=n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
		{
			if(s[i][j]=='.') a[i][j]=1;
		}
	}
	Add(a);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(Get(a,i,j,i+k-1,j)==k) b[i][j]=1;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(Get(a,i,j,i,j+k-1)==k) c[i][j]=1;
	Add(b);Add(c);
	int sol=0,taj=0;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(s[i][j]=='.')
	{
		int ans=Get(b,i-k+1,j,i,j)+Get(c,i,j-k+1,i,j);
		if(ans>=sol) sol=ans,taj=i*N+j;
	}
	if(!sol) return printf("1 1\n"),0;
	printf("%i %i\n",taj/N,taj%N);
	return 0;
}