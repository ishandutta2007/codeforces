#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
map <int,int> Ma[2];
int n,a[Maxn],sum[Maxn];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i],Ma[i%2][sum[i]]++;
	Ma[0][0]++;
	for(map <int,int> ::iterator it=Ma[0].begin();it!=Ma[0].end();it++)
		ans+=(long long)it->second*(it->second-1)/2;
	 for(map <int,int> ::iterator it=Ma[1].begin();it!=Ma[1].end();it++)
		ans+=(long long)it->second*(it->second-1)/2;
	printf("%lld",ans);
	return 0;
}