#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n],b[max_n];
bool ok[max_n];
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
		{
			scanf("%d",b+i);
			assert(a[i]<=b[i]);
		}
		for(int i=1;i<=n;++i)
			printf("%d%c",*lower_bound(b+1,b+n+1,a[i])-a[i]," \n"[i==n]);
		for(int i=2;i<=n;++i)
			ok[i]=(a[i]<=b[i-1]);
		for(int i=1;i<=n;++i)
		{
			int j=i;
			while(j+1<=n&&ok[j+1])
				++j;
			for(int k=i;k<=j;++k)
				printf("%d%c",b[j]-a[k]," \n"[k==n]);
			i=j;
		}
	}
	return 0;
}