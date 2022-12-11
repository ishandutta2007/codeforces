#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
long long a[max_n];
int main()
{
	int n;
	long long k,x;
	scanf("%d%lld%lld",&n,&k,&x);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int cnt=1;
	vector<long long> val;
	for(int i=1;i+1<=n;++i)
	{
		if(a[i+1]-a[i]>x)
		{
			++cnt;
			val.push_back((a[i+1]-a[i]+x-1)/x-1);
		}
	}
	sort(val.begin(),val.end());
	for(int i=0;i<int(val.size());++i)
	{
		if(k>=val[i])
			k-=val[i],--cnt;
		else
			break;
	}
	printf("%d\n",cnt);
	return 0;
}