#include <stdio.h>
#define ll long long
const int N=100050;
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
	if(r[x]>r[y]) p[y]=x;
	if(r[x]<r[y]) p[x]=y;
	if(r[x]==r[y]) r[x]++,p[y]=x;
}
bool Lucky(int x)
{
	for(;x;x/=10) if(x%10!=4 && x%10!=7) return false;
	return true;
}
int sz[N];
ll sol;
int main()
{
	int n,i,u,v,w;
	scanf("%i",&n);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<n;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		if(!Lucky(w)) Union(u,v);
	}
	for(i=1;i<=n;i++) sz[Find(i)]++;
	for(i=1;i<=n;i++)
	{
		sol+=(ll)sz[i]*(n-sz[i])*(n-sz[i]-1);
	}
	printf("%lld\n",sol);
	return 0;
}