#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	set<long long> S;
	map<long long,long long> ans;
	while(q--)
	{
		char op[5];
		long long k;
		scanf("%s%lld",op,&k);
		if(op[0]=='+')
			S.insert(k);
		else
		{
			if(S.find(k)==S.end())
			{
				printf("%lld\n",k);
				continue;
			}
			long long now=k<<1;
			if(ans.count(k))
				now=ans[k];
			while(S.find(now)!=S.end())
				now+=k;
			printf("%lld\n",now);
			ans[k]=now;
		}
	}
	return 0;
}