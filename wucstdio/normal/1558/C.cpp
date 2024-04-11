#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[10005],res[10005],top;
void rev(int p,int&x,int&y)
{
	if(x<=p)x=p-x+1;
	if(y<=p)y=p-y+1;
	for(int i=1;i*2<=p;i++)swap(a[i],a[p-i+1]);
	res[++top]=p;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if((a[i]+i)&1)flag=1;
		}
		if(flag)
		{
			printf("-1\n");
			continue;
		}
		top=0;
		while(n!=1)
		{
			int x,y;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==n)x=i;
				if(a[i]==n-1)y=i;
			}
			rev(x,x,y);
			rev(y-1,x,y);
			rev(n,x,y);
			rev(x,x,y);
			rev(n,x,y);
			n-=2;
		}
		printf("%d\n",top);
		for(int i=1;i<=top;i++)printf("%d ",res[i]);
		printf("\n");
	}
	return 0;
}