#include<bits/stdc++.h>
using namespace std;
int n,x=1;
vector<pair<int,int>>a;
void sol(int l,int r)
{
	if(l==r)
		return;
	int m=l+r>>1,v=(r-l+1)/2;
	sol(l,m);
	sol(m+1,r);
	for(int i=l;i<=m;i++)
		a.emplace_back(i,i+v);
}
int main()
{
	scanf("%d",&n);
	while(1)
	{
		if(x*2>n)
			break;
		x*=2;
	}
	if(x==n)
		sol(1,x);
	else
	{
		sol(1,x);
		sol(n-x+1,n);
	}
	printf("%d\n",a.size());
	for(auto i:a)
		printf("%d %d\n",i.first,i.second);
	return 0;
}