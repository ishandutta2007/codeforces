#include<stdio.h>
int a[10020];
int b[10020];
int c,n;
int F(int x)
{
	int l=0,r=1<<30;
	for(;l<r-1;)
	{
		int m=l+r>>1;
		long long s=0;
		for(int i=0;i<n;i++)
		{
			s+=1+(long long)a[i]*m/b[i];
			if(s>=x)
			{
				r=m;
				goto end;
			}
		}
		l=m;
		end:;
	}
	return r;
}
int main()
{
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++)
		scanf("%d %d",a+i,b+i);
	printf("%d\n",F(c+1)-F(c));
	return 0;
}