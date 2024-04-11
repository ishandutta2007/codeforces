#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
pair<int,int>a[N];
long long s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
		s+=a[i].second;
		a[i].second+=a[i].first;
	}
	sort(a+1,a+n+1);
	m=a[1].first;
	for(int i=1;i<=n;i++)
	{
		while(i<=n&&a[i].first<=m)
		{
			m=max(m,a[i].second);
			i++;
		}
		if(i<=n)
		{
			s+=a[i].first-m;
			m=max(m,a[i].second);
		}
	}
	printf("%lld\n",s);
	return 0;
}