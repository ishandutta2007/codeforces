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
		vector<int> val[2];
		long long sum=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",b+i);
			val[a[i]].push_back(b[i]);
			sum+=b[i];
		}
		if(val[0].size()<val[1].size())
			swap(val[0],val[1]);
		int x=val[0].size(),y=val[1].size();
		long long delta=0;
		if(x==y)
		{
			int mn=1e9;
			for(int i=1;i<=n;++i)
				mn=min(mn,b[i]);
			delta=sum-mn;
		}
		else
		{
			sort(val[0].begin(),val[0].end(),greater<int>());
			for(int i=0;i<y;++i)
				delta+=val[1][i]+val[0][i];
		}
		printf("%lld\n",sum+delta);
	}
	return 0;
}