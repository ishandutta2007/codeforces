#include <stdio.h>
const int N=25;
int a[N][N],p[N],n,m;
bool Check()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		int bad=0;
		for(j=1;j<=m;j++) if(a[i][j]!=p[j]) bad++;
		if(bad>2) return 0;
	}
	return 1;
}
void Swap(int &a, int &b){ a^=b,b^=a,a^=b;}
int main()
{
	int i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&a[i][j]);
	for(i=1;i<=m;i++) p[i]=i;
	if(Check()) return printf("YES\n"),0;
	for(i=1;i<=m;i++)
	{
		for(j=i+1;j<=m;j++)
		{
			Swap(p[i],p[j]);
			if(Check()) return printf("YES\n"),0;
			Swap(p[i],p[j]);
		}
	}
	printf("NO\n");
	return 0;
}