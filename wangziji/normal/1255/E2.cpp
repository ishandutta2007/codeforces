#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int a[1000005],n,b[1000005],cnt,c[1000005];
inline int cal(int x)
{
	cnt=0;
	int rtn=0,now=0;
	for(int i=1;i<=n;i++)
		now+=a[i],now%=x,rtn+=min(now,x-now);
	return rtn;
}
signed main(int argc, char** argv) {
	int sum=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	int ans=5e18;
	for(int i=2;i*i<=sum;i++)
	{
		if(sum%i==0) ans=min(ans,cal(i));
		while(sum%i==0) sum/=i;
	}
	if(sum>1) ans=min(ans,cal(sum));
	if(ans>2e18) cout << -1;
	else cout << ans;
	return 0;
}