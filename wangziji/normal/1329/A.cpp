#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],b[100005];
int ans[100005],cf[100005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	long long s=0;
	int mx=0;
	for(int i=1;i<=m;i++)
	{
		cin >> a[i];
		b[i]=a[i];
		s+=a[i];
	}
	if(s<n)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;i++)
		ans[i]=i,mx=max(mx,ans[i]+a[i]-1);
	int now=1;
	int x=0;
	while(mx+x<n)
	{
		while(b[now]<=1)
		{
			cf[now+1]+=cf[now];
			++now;
		}
		--b[now];
		++cf[now+1],++x;
	}
	for(int i=now+1;i<=m;i++) cf[i]+=cf[i-1];
	int flag=0;
	for(int i=1;i<=m;i++)
	{
		ans[i]+=cf[i];
		if(a[i]+ans[i]-1>n)
		{
			puts("-1");
			return 0;
		}
		if(a[i]+ans[i]-1==n) flag=1;
	}
		if(!flag)
		{
			puts("-1");
			return 0;
		}
	for(int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}
/*
25 5
5 5 5 5 5
*/