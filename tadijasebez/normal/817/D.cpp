#include <stdio.h>
#include <stack>
using namespace std;
long long a[1000050];
long long LeftMax[1000050];
long long RightMax[1000050];
long long LeftMin[1000050];
long long RightMin[1000050];
stack<pair<long long,long long> > s;
const long long inf=1000000000;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	s.push(make_pair(inf,-1));
	a[n]=inf-1;
	for(i=0;i<=n;i++)
	{
		while(s.top().first<a[i])
		{
			RightMax[s.top().second]=i;
			s.pop();
		}
		LeftMax[i]=s.top().second;
		s.push(make_pair(a[i],i));
	}
	while(!s.empty()) s.pop();
	s.push(make_pair(-2,-1));
	a[n]=-1;
	for(i=0;i<=n;i++)
	{
		while(s.top().first>a[i])
		{
			RightMin[s.top().second]=i;
			s.pop();
		}
		LeftMin[i]=s.top().second;
		s.push(make_pair(a[i],i));
	}
	long long sol=0;
	for(i=0;i<n;i++)
	{
		sol+=(i-LeftMax[i])*(RightMax[i]-i)*a[i];
		sol-=(i-LeftMin[i])*(RightMin[i]-i)*a[i];
	}
	printf("%lld\n",sol);
	return 0;
}
/*
3
1 4 5
*/