#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
long long a[max_n]; 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%lld",a+i);
		for(int i=1;i<=n-1;++i)
		{
			if(a[i]<=0)
				break;
			a[i+1]+=a[i],a[i]=0;
		}
		bool ans=true;
		for(int i=1;i<=n;++i)
		{
			if(a[i])
			{
				ans=false;
				break;
			}
		}
		puts(ans?"Yes":"No");
	}
	return 0;
}