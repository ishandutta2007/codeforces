#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
char str[max_n];
int val[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,str+1);
		for(int i=1;i<=n;++i)
			val[i]=i;
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			if(str[i]=='1')
				continue;
			ans+=val[i];
			for(int j=i<<1;j<=n;j+=i)
			{
				if(str[j]=='1')
					break;
				val[j]=min(val[j],i);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}