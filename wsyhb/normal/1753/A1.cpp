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
		if(n&1)
		{
			puts("-1");
			continue;
		}
		typedef pair<int,int> P;
		vector<P> ans;
		for(int i=1;i<=n;i+=2)
		{
			if(a[i]!=a[i+1])
			{
				ans.push_back(P(i,i));
				ans.push_back(P(i+1,i+1));
			}
			else
				ans.push_back(P(i,i+1));
		}
		printf("%d\n",int(ans.size()));
		for(P res:ans)
			printf("%d %d\n",res.first,res.second);
	}
	return 0;
}