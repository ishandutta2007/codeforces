#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,pa[500005],size[500005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pa[i]=i,size[i]=1;
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		if(k==0)continue;
		k--;
		int x;
		scanf("%d",&x);
		x=find(x);
		while(k--)
		{
			int y;
			scanf("%d",&y);
			y=find(y);
			if(x==y)continue;
			if(size[x]<size[y])swap(x,y);
			pa[y]=x;
			size[x]+=size[y];
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",size[find(i)]);
	printf("\n");
	return 0;
}