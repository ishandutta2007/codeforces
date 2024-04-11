#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
long long n,m,k,p[Maxn];
int ans,tmp; 
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld",&p[i]);
	ans=1;
	p[0]=p[1];
	for(int i=1;i<=m;i++)
		if((p[i]-tmp-1)/k!=(p[i-1]-tmp-1)/k) tmp=i-1,ans++;
	printf("%d",ans);
	return 0;
}