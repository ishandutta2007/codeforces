#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],b[max_n],c[max_n],d[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=n;++i)
			scanf("%d",b+i);
		int ans=0;
		for(int k=29;k>=0;--k)
		{
			ans|=1<<k;
			for(int i=1;i<=n;++i)
			{
				c[i]=a[i]&ans;
				d[i]=b[i]&ans;
			}
			sort(c+1,c+n+1);
			sort(d+1,d+n+1);
			bool ok=true;
			for(int i=1;i<=n;++i)
			{
				if(c[i]+d[n+1-i]!=ans)
				{
					ok=false;
					break;
				}
			}
			if(!ok)
				ans^=1<<k;
		}
		printf("%d\n",ans);
	}
	return 0;
}