#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k==n-1&&n==4)
		{
			puts("-1");
			continue;
		}
		vector<int> a(n/2),b(n/2);
		for(int i=0;i<n/2;++i)
			a[i]=i,b[i]=n-1-i;
		if(k==n-1)
		{
			for(int i=0;i<n/2;++i)
			{
				if(a[i]==n-2)
					assert(false);
				if(b[i]==n-2)
				{
					swap(b[i],a[0]);
					swap(b[i],a[3]);
					break;
				}
			}
		}
		else
		{
			for(int i=0;i<n/2;++i)
			{
				if(a[i]==k)
				{
					swap(a[i],a[0]);
					break;
				}
				if(b[i]==k)
				{
					swap(b[i],a[0]);
					break;
				}
			}
		}
		for(int i=0;i<n/2;++i)
			printf("%d %d\n",a[i],b[i]);
	}
	return 0;
}