#include<bits/stdc++.h>
using namespace std;
vector<long long>s;
int main()
{
	long long n,m,a,b,sum=0,ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		sum+=a;
		s.push_back(a-b);
	}
	sort(s.begin(),s.end());
	while(sum>m)
	{
		ans++;
		if(ans>n)
		{
			printf("-1\n");
			return 0;
		}
		sum-=s[n-ans];
	}
	printf("%lld\n",ans);
	return 0;
}