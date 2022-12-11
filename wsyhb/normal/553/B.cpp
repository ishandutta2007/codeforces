#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[55];
int ans[55];
int cnt;
void work(int n,ll k)
{
	if(n==0) return;
	if(k<=f[n-1]) ans[++cnt]=1;
	else ans[++cnt]=2;
	work(n-ans[cnt],k>f[n-1]?k-f[n-1]:k);
}
int main()
{
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++) f[i]=f[i-1]+f[i-2];
	work(n,k);
	int now=1;
	for(int i=1;i<=cnt;i++)
	{
		for(int j=now+ans[i]-1;j>=now;j--) printf("%d ",j);
		now+=ans[i];
	}
	return 0;
}