#include<bits/stdc++.h>
using namespace std;
const int N=1000005,mod=998244353;
int n,m,s,a[N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	s=1;
	rotate(a,a+n-m,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]>0&&a[i]+m>i)
		{
			puts("0");
			return;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==-1)
			s=1ll*s*(i+1)%mod;
		if(a[i]==0)
			s=1ll*s*(min(i,m)+1)%mod;
	}
	printf("%d\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}