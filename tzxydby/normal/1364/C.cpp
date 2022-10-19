#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],b[N],v[N],zh[N];
set<int>s;
int main()
{
	for(int i=0;i<=100000;i++)
		s.insert(i);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(!v[a[i]])
		{
			v[a[i]]=1;
			zh[i]=1;
			s.erase(a[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=(*s.begin());
		s.erase(s.begin());
		if(zh[i])
			s.insert(a[i]);
	}
	s.clear();
	for(int i=0;i<=100000;i++)
		s.insert(i);
	for(int i=1;i<=n;i++)
	{
		if(s.count(b[i]))
			s.erase(b[i]);
		if(a[i]!=(*s.begin()))
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	return 0;
}