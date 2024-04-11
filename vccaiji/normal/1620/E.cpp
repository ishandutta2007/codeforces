#include<bits/stdc++.h>
using namespace std;
int k=0;
int fa[510000];
int val[510000];
int rv[510000]={};
int find(int i)
{
	if(fa[i]==i) return i;
	return fa[i]=find(fa[i]);
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int o=0;o<q;o++)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			int x;
			scanf("%d",&x);
			k++;
			if(rv[x]==0)
			{
				fa[k]=k;
				val[k]=x;
				rv[x]=k;
			}
			else
			{
				fa[k]=rv[x];
			}
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==y) continue;
			if(rv[x])
			{
				if(rv[y])
				{
					fa[rv[x]]=rv[y];
					rv[x]=0;
				}
				else
				{
					rv[y]=rv[x];
					val[rv[x]]=y;
					rv[x]=0;
				}
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d",val[find(i)]);
		if(i<k) printf(" ");
	}
	return 0;
}