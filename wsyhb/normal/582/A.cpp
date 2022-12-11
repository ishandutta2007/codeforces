#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=500+5;
int ans[N];
multiset<int> s;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n*n;i++) 
	{
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	for(int i=1;i<=n;i++)
	{
		multiset<int>::iterator it=s.end();
		it--;
		ans[i]=*it;
		s.erase(it);
		for(int j=i-1;j>=1;j--)
		{
			int q=__gcd(ans[i],ans[j]);
			it=s.find(q);
			s.erase(it);
			it=s.find(q);
			s.erase(it);
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]); 
	return 0;
}