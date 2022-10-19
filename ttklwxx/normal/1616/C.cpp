#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[105];
int main()
{
	int t,n,ans=0,now=0;
	double k,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		ans=n;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				k=(double)(a[j]-a[i])/(j-i);
				x=a[i]-i*k;
				//printf("%.6lf %.6lf\n",k,x);
				now=0;
				for(int sth=1;sth<=n;sth++)
				{
					if(fabs(a[sth]-x-sth*k)>1e-9)now++;
				}
				//printf("%d %d %d\n",i,j,now);
				ans=min(ans,now);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}