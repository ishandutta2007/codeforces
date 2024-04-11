#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int d[max_n],a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",d+i);
			a[i]=a[i-1]+d[i];
		}
		bool multi=false;
		for(int i=2;i<=n;++i)
		{
			if(d[i]>0&&a[i-1]-d[i]>=0)
			{
				multi=true;
				break;
			}
		}
		if(multi)
			puts("-1");
		else
		{
			for(int i=1;i<=n;++i)
				printf("%d%c",a[i]," \n"[i==n]);
		}
	}
	return 0;
}