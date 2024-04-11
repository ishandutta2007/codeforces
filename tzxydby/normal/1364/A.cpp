#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],n,t,x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		int l=n+1,r=0,s=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
			if(a[i]%x)
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		if(!r)
		{
			puts("-1");
			continue;
		}
		if(s%x)
		{
			printf("%d\n",n);
			continue;
		}
		int len=min(l,n-r+1);
		printf("%d\n",n-len);
	}
	return 0;
}