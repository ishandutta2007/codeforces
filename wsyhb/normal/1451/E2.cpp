#include<bits/stdc++.h>
using namespace std;
const int max_n=1<<16|5;
int a[max_n],val[max_n],pos[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",val+i);
	}
	int x=-1,y=-1;
	for(int i=2;i<=n;++i)
	{
		if(!val[i])
		{
			x=1,y=i;
			break;
		}
		if(pos[val[i]]!=0)
		{
			x=pos[val[i]],y=i;
			break;
		}
		pos[val[i]]=i;
	}
	if(x!=-1&&y!=-1)
	{
		printf("AND %d %d\n",x,y);
		fflush(stdout);
		scanf("%d",a+x);
		if(x!=1)
			a[1]=a[x]^val[x];
		for(int i=2;i<=n;++i)
			a[i]=a[1]^val[i];
	}
	else
	{
		printf("AND 1 %d\n",pos[1]);
		fflush(stdout);
		scanf("%d",a+1);
		a[1]&=n-2;
		printf("AND 1 %d\n",pos[2]);
		fflush(stdout);
		int v;
		scanf("%d",&v);
		a[1]|=v&1;
		for(int i=2;i<=n;++i)
			a[i]=a[1]^val[i];
	}
	printf("!");
	for(int i=1;i<=n;++i)
		printf(" %d",a[i]);
	puts("");
	fflush(stdout);
	return 0;
}