#include <stdio.h>
const int N=100050;
int a[N];
int main()
{
	int n,l,x,y,i;
	bool ok1=0,ok2=0,ok3=0,ok4=0,ok5=0;
	scanf("%i %i %i %i",&n,&l,&x,&y);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		int top=n,bot=i+1,mid;
		while(top>=bot)
		{
			int mid=top+bot>>1;
			if(a[mid]-a[i]==x) ok1=1;
			if(a[mid]-a[i]<=x) bot=mid+1;
			else top=mid-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		int top=n,bot=i+1,mid;
		while(top>=bot)
		{
			int mid=top+bot>>1;
			if(a[mid]-a[i]==y) ok2=1;
			if(a[mid]-a[i]<=y) bot=mid+1;
			else top=mid-1;
		}
	}
	int ans3=0;
	for(i=1;i<=n;i++)
	{
		int top=n,bot=i+1,mid;
		if(a[n]-a[i]>=y)
		{
			while(top>=bot)
			{
				int mid=top+bot>>1;
				if(a[mid]-a[i]==y-x) ok3=1,ans3=a[i];
				if(a[mid]-a[i]<=y-x) bot=mid+1;
				else top=mid-1;
			}
		}
	}
	int ans4=0;
	for(i=1;i<=n;i++)
	{
		int top=n,bot=i+1,mid;
		while(top>=bot)
		{
			int mid=top+bot>>1;
			if(a[mid]-a[i]==y+x) ok4=1,ans4=a[i];
			if(a[mid]-a[i]<=y+x) bot=mid+1;
			else top=mid-1;
		}
	}
	int ans5=0;
	for(i=1;i<=n;i++)
	{
		int top=n,bot=i+1,mid;
		if(a[i]-a[1]>=x)
		{
			while(top>=bot)
			{
				int mid=top+bot>>1;
				if(a[mid]-a[i]==y-x) ok5=1,ans5=a[mid];
				if(a[mid]-a[i]<=y-x) bot=mid+1;
				else top=mid-1;
			}
		}
	}
	if(ok1 && ok2) printf("0\n");
	else if(ok1) printf("1\n%i\n",y);
	else if(ok2) printf("1\n%i\n",x);
	else if(ok3) printf("1\n%i\n",ans3+y);
	else if(ok4) printf("1\n%i\n",ans4+y);
	else if(ok5) printf("1\n%i\n",ans5-y);
	else printf("2\n%i %i\n",x,y);
	return 0;
}