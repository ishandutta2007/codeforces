#include <stdio.h>
const int N=100050;
int a[N],sol=1;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j=-1;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	int t1=1,t2=-1;
	for(i=2;i<=n;i++)
	{
		if(t2>-1 && a[i]>j)
		{
			t2++;
			sol=max(sol,t2);
			j=a[i];
		}
		else if(t2>-1 && a[i]<=j)
		{
			t2=-1;
		}
		if(a[i]>a[i-1])
		{
			t1++;
			sol=max(sol,t1);
		}
		else
		{
			if(t2==-1)
			{
				t2=t1+1;
				j=a[i-1]+1;
			}
			sol=max(sol,t2);
			t1=1;
		}
	}
	t1=1;
	t2=-1;
	for(i=n-1;i>=1;i--)
	{
		if(t2>-1 && a[i]<j)
		{
			t2++;
			sol=max(sol,t2);
			j=a[i];
		}
		else if(t2>-1 && a[i]>=j)
		{
			t2=-1;
		}
		if(a[i]<a[i+1])
		{
			t1++;
			sol=max(sol,t1);
		}
		else
		{
			if(t2==-1)
			{
				t2=t1+1;
				j=a[i+1]-1;
			}
			sol=max(sol,t2);
			t1=1;
		}
	}
	printf("%i\n",sol);
	return 0;
}