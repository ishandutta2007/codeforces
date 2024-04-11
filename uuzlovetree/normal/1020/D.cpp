#include<bits/stdc++.h>
using namespace std;
int n;
int ask(int pos)
{
	int x,y;
	printf("? %d\n",pos);
	fflush(stdout);
	scanf("%d",&x);
	printf("? %d\n",pos+n/2);
	fflush(stdout);
	scanf("%d",&y);
	return x-y;
}
int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		printf("! -1\n");
		return 0;
	}
	int l=1,r=n/2;
	int fl=ask(l),fr=ask(r);
	if(fl==0)
	{
		printf("! %d\n",l);
		return 0;
	}
	if(fr==0)
	{
		printf("! %d\n",r);
		return 0;
	}
	if(fl>0&&fr<0)
	{
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int t=ask(mid);
			if(t==0)
			{
				printf("! %d\n",mid);
				return 0;
			}
			if(t>0)l=mid+1;else r=mid-1;
		}
	}
	if(fl<0&&fr>0)
	{
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int t=ask(mid);
			if(t==0)
			{
				printf("! %d\n",mid);
				return 0;
			}
			if(t>0)r=mid-1;else l=mid+1;
		}
	}
	puts("! -1");
	return 0;
}