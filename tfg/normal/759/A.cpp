#include <cstdio>
#include <algorithm>

const int ms=200200;

int groups;

int par[ms];

int get_par(int x)
{
	if(x==par[x])
		return x;
	else
		return par[x]=get_par(par[x]);
}

void make_union(int a, int b)
{
	//printf("union of %i and %i\n",a,b);
	a=get_par(a);
	b=get_par(b);
	if(a==b)
		return;
	//printf("ok\n");
	groups--;
	par[a]=b;
}

int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
		par[i]=i;
	groups=n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%i", &temp);
		make_union(i, temp);
	}
	int change=0;
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%i", &temp);
		change+=temp;
		//printf("(%i, %i)\n",i,temp);
	}
	if(change%2==0)
		ans++;
	int need_change=groups-1;
	if(need_change)
		ans+=need_change+1;
	printf("%i\n",ans);

}