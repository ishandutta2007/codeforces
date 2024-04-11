#include <stdio.h>
int a[100005];
int b[100005];
bool mark[100005];
int cnt,tmp,first,last;
int main()
{
	int n,i;
	scanf("%i",&n);
	mark[0]=false;
	a[0]=-1;
	first=2;
	last=1;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(!mark[i-1] && a[i]<a[i-1])
		{
			if(cnt==1)
			{
				printf("no\n");
				return 0;
			}
			first=i;
			cnt=1;
			last=i;
			tmp=a[i-1];
			mark[i]=true;
		}
		if(mark[i-1] && a[i]<a[i-1])
		{
			last=i;
			mark[i]=true;
		}
		if(!mark[i-1] && a[i]>=a[i-1])
		{
			mark[i]=false;
		}
		if(mark[i-1] && a[i]>=a[i-1])
		{
			if(a[i]<tmp)
			{
				printf("no\n");
				return 0;
			}
			mark[i]=false;
		}
	}
	for(i=1;i<=n;i++)
	{
		b[i]=a[i];
	}
	first--;
	for(i=last;i>=first;i--)
	{
		b[first+last-i]=a[i];
	}
	b[0]=0;
	for(i=1;i<=n;i++)
	{
		if(b[i-1]>b[i])
		{
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n%i %i\n",first,last);
	return 0;
}