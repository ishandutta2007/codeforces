#include<bits/stdc++.h>
using namespace std;
inline int Abs(int x)
{
	return x>=0?x:-x;
}
int n,x;
const int max_n=2e5+5;
int a[max_n];
inline int calc(int L,int R)
{
	int res=1e9; 
	for(int i=1;i+1<=n;++i)
	{
		res=min(res,Abs(L-a[i])+Abs(R-a[i+1])-Abs(a[i]-a[i+1]));
		res=min(res,Abs(L-a[i+1])+Abs(R-a[i])-Abs(a[i]-a[i+1]));
	}
	res=min(res,Abs(L-a[1]));
	res=min(res,Abs(L-a[n]));
	res=min(res,Abs(R-a[1]));
	res=min(res,Abs(R-a[n]));
	return res+R-L;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		int mx=0,mn=1e9;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		long long ans=0;
		for(int i=1;i+1<=n;++i)
			ans+=a[i]>=a[i+1]?a[i]-a[i+1]:a[i+1]-a[i];
		if(mn>1)
			ans+=calc(1,mn-1);
		if(mx<x)
			ans+=calc(mx+1,x);
		printf("%lld\n",ans);
	}
	return 0;
}