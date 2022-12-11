#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],b[max_n];
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
		if(n&1)
		{
			puts("NO");
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=1,j=1;i<=n/2;++i,j+=2)
			b[j]=a[i];
		for(int i=n/2+1,j=2;i<=n;++i,j+=2)
			b[j]=a[i];
		b[0]=b[n],b[n+1]=b[1];
		bool ans=true;
		for(int i=1;i<=n;++i)
		{
			if(b[i]>b[i-1]&&b[i]>b[i+1])
				continue;
			if(b[i]<b[i-1]&&b[i]<b[i+1])
				continue;
			ans=false;
			break;
		}
		if(ans)
		{
			puts("YES");
			for(int i=1;i<=n;++i)
				printf("%d%c",b[i],i<n?' ':'\n');
		}
		else
			puts("NO");
	}
	return 0;
}