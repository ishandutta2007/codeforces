#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using namespace std;
const int Maxn=200005;
int n,k,cnt;
long long a[Maxn],b[Maxn];
int need[Maxn];
bool check(long long now)
{
	memset(need,0,sizeof(need));
	int ct=k;
	for(int i=1;i<=n;i++)
	{
		long long sum=a[i];
		need[min(sum/b[i]+1,(long long)k+1)]++;
		while(sum<b[i]*k)
		{
			if(!ct) break;
			sum+=now;
			need[min(sum/b[i]+1,(long long)k+1)]++;
			ct--;
		}
	}
	for(int i=1;i<=k;i++)
	{
		need[i]+=need[i-1];
		if(need[i]>i) return false;
	}
	return true;
}
int main()
{
//	freopen("D.in","r",stdin);
	scanf("%d%d",&n,&k);
	k--; 
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		if(!(a[i]/b[i])) cnt++;
	if(cnt>1)
	{
		printf("-1");
		return 0;
	}
	long long l=0,r=2e12;
	while(l+1<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld",l==2e12?-1:l);
	return 0;
}