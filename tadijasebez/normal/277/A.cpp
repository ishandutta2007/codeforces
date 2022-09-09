#include <stdio.h>
const int N=105;
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x) p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y) return;
	if(r[x]>r[y]) p[y]=x;
	if(r[x]<r[y]) p[x]=y;
	if(r[x]==r[y]) r[x]++,p[y]=x;
}
bool Know[N][N];
int sol=-1;
int main()
{
	int n,m,i,j,k,x;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) p[i]=i;
	bool DumbPeople=true;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&k);
		if(k>0) DumbPeople=false;
		for(j=0;j<k;j++)
		{
			scanf("%i",&x);
			Know[i][x]=true;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			{
				if(Know[i][k] && Know[j][k]) Union(i,j);
			}
		}
	}
	for(i=1;i<=n;i++) if(p[i]==i) sol++;
	if(DumbPeople) sol++;
	printf("%i\n",sol);
	return 0;
}