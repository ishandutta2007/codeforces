#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,u,v;
		scanf("%d%d%d",&n,&u,&v);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		bool flag=false;
		for(int i=2;i<=n;++i)
		{
			if(abs(a[i]-a[i-1])>1)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			puts("0");
			continue;
		}
		bool flag_same=true;
		for(int i=2;i<=n;++i)
		{
			if(a[i]!=a[i-1])
			{
				flag_same=false;
				break;
			}
		}
		if(flag_same)
			printf("%d\n",v+min(u,v));
		else
			printf("%d\n",min(u,v));
	}
    return 0;
}