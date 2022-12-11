#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
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
		for(int i=1;i<=n;++i)
			scanf("%d",b+i);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			if(b[i]!=a[i]&&b[i]!=a[i]+1)
			{
				flag=false;
				break;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}