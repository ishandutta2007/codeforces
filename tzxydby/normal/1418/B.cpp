#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n,a[N],b[N];
multiset<int>s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			if(!b[i])
				s.insert(-a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(!b[i])
			{
				a[i]=-(*s.begin());
				s.erase(s.begin());
			}
			printf("%d ",a[i]);
		}
		puts("");
	}
	return 0;
}