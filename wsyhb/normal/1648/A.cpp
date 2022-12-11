#include<bits/stdc++.h>
using namespace std;
const int max_R=1e5+5;
vector<int> x[max_R],y[max_R];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int c;
			scanf("%d",&c);
			x[c].push_back(i);
			y[c].push_back(j);
		}
	int R=1e5;
	long long ans=0;
	for(int k=1;k<=R;++k)
	{
		sort(x[k].begin(),x[k].end());
		for(int i=0;i<int(x[k].size());++i)
			ans+=(i-(int(x[k].size())-1ll-i))*x[k][i];
		sort(y[k].begin(),y[k].end());
		for(int i=0;i<int(y[k].size());++i)
			ans+=(i-(int(y[k].size())-1ll-i))*y[k][i];
	}
	printf("%lld\n",ans);
	return 0;
}