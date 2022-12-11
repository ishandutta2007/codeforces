#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
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
		int sum=0;
		for(int i=1;i<=n;++i)
			sum+=max(a[i],-a[i]);
		if(sum&1)
		{
			puts("-1");
			continue;
		}
		typedef pair<int,int> P;
		vector<P> ans;
		for(int i=1;i<=n;++i)
		{
			int j=i;
			while(j<=n&&!a[j])
				++j;
			if(j>n)
			{
				ans.push_back(P(i,n));
				break;
			}
			if(j>i)
				ans.push_back(P(i,j-1));
			int k=j+1;
			while(k<=n&&!a[k])
				++k;
			assert(k<=n);
			if(a[j]!=a[k])
			{
				ans.push_back(P(j,k-1));
				ans.push_back(P(k,k));
			}
			else
			{
				if(k==j+1)
					ans.push_back(P(j,k));
				else
				{
					ans.push_back(P(j,k-2));
					ans.push_back(P(k-1,k));
				}
			}
			i=k;
		}
		printf("%d\n",int(ans.size()));
		for(P res:ans)
			printf("%d %d\n",res.first,res.second);
	}
	return 0;
}