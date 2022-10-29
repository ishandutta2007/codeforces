#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[100005],mx[100005],q[300005],head,tail,dp[100005];
signed main(int argc, char** argv) {
	int n,k,ans=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ans+=a[i];
	}
	head=1,tail=0;
	for(int i=1;i<k;i++)
	{
		while(a[q[tail]]>=a[i]&&tail-head+1) --tail;
		q[++tail]=i;
	}
	for(int i=k;i<=n;i++)
	{
		while(a[q[tail]]>=a[i]&&tail-head+1) --tail;
		while(q[head]<=i-k&&tail-head+1) ++head;
		q[++tail]=i;
		mx[i]=a[q[head]];
	}
	for(int i=k;i<=n;i++)
	{
		dp[i]=dp[i-k]+mx[i];
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout << ans-dp[n];
	return 0;
}//