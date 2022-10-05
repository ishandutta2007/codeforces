#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n,p;
long long ans,a[Maxn],k;
map <int,int> Ma;
int main()
{
	scanf("%d%d%lld",&n,&p,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),Ma[(a[i]*a[i]%p*a[i]%p*a[i]%p-a[i]*k%p+p)%p]++;
	for(map <int,int>::iterator it=Ma.begin();it!=Ma.end();it++)
		ans+=(long long)it->second*(it->second-1)/2;
	printf("%lld",ans);
	return 0;
}