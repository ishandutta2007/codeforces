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
	if(r[x]==r[y]) r[x],p[y]=x;
}
int x[N],y[N],sol=-1;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<=n;i++) scanf("%i %i",&x[i],&y[i]);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(x[i]==x[j] || y[i]==y[j]) Union(i,j);
	for(i=1;i<=n;i++) if(p[i]==i) sol++;
	printf("%i\n",sol);
	return 0;
}