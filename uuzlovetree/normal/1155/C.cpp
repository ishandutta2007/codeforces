#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
using namespace std;
ll gcd(ll a,ll b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int n,m;
ll x[maxn],p[maxn];
ll d[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%I64d",&x[i]);
	for(int i=1;i<=m;++i)scanf("%I64d",&p[i]);
	for(int i=1;i<n;++i)d[i]=x[i+1]-x[i];
	ll g=d[1];
	for(int i=2;i<n;++i)g=gcd(g,d[i]);
	for(int i=1;i<=m;++i)if(g%p[i]==0)
	{
		puts("YES");
		printf("%I64d %d\n",x[1],i);
		return 0;
	}
	puts("NO");
	return 0;
}