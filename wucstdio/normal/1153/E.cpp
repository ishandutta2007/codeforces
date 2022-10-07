#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,res1[1005],res2[1005],px1,px2,py1,py2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("? %d 1 %d %d\n",i,i,n);
		fflush(stdout);
		scanf("%d",&res1[i]);
		if(res1[i]&1)
		{
			if(!px1)px1=i;
			px2=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("? 1 %d %d %d\n",i,n,i);
		fflush(stdout);
		scanf("%d",&res2[i]);
		if(res2[i]&1)
		{
			if(!py1)py1=i;
			py2=i;
		}
	}
	if(px1&&py1)
	{
		printf("? %d %d %d %d\n",px1,py1,px1,py1);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x&1)printf("! %d %d %d %d\n",px1,py1,px2,py2);
		else printf("! %d %d %d %d\n",px1,py2,px2,py1);
		return 0;
	}
	if(px1)
	{
		int l=1,r=n;
		while(l!=r)
		{
			int mid=(l+r)>>1;
			printf("? %d %d %d %d\n",px1,l,px1,mid);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x&1)r=mid;
			else l=mid+1;
		}
		printf("! %d %d %d %d\n",px1,l,px2,l);
		return 0;
	}
	else
	{
		int l=1,r=n;
		while(l!=r)
		{
			int mid=(l+r)>>1;
			printf("? %d %d %d %d\n",l,py1,mid,py1);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x&1)r=mid;
			else l=mid+1;
		}
		printf("! %d %d %d %d\n",l,py1,l,py2);
		return 0;
	}
	return 0;
}