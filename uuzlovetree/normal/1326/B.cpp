#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n;
int b[maxn],a[maxn];
int solve(int x)
{
	if(x==1)
	{
		a[x]=b[x];
		return a[x];
	}
	int mx=solve(x-1);
	a[x]=mx+b[x];
	if(b[x]>=0)return a[x];
	else return mx;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	solve(n);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
}