#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=300005;
pair<int,int>a[N];
priority_queue<int,vector<int>,greater<int>>pq;
main()
{
	int n,k;
	scanf("%I64d%I64dd",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d%I64d",&a[i].second,&a[i].first);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=0,len=0;
	for(int i=1;i<=n;i++)
	{
		pq.push(a[i].second);
		len+=a[i].second;
		if(i>k)
		{
			len-=pq.top();
			pq.pop();
		}
		ans=max(ans,len*a[i].first);
	}
	printf("%I64d\n",ans);
	return 0;
}