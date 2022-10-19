#include<bits/stdc++.h>
using namespace std;
const int N=200005;
pair<int,int>a[N];
vector<int>ans;
int main()
{
	int n;
	long long sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
		sum+=a[i].first;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		if(sum-a[i].first==2*a[n].first)
			ans.push_back(a[i].second);
	if(sum-a[n].first==2*a[n-1].first)
		ans.push_back(a[n].second);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}