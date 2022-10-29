#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[200005];
int n,k;
inline bool pd(int x)
{
	int rtn=0;
	for(int i=n/2+1;i<=n;i++)
		rtn+=max((int)0,x-a[i]);
	return rtn<=k;
}
signed main(int argc, char** argv) {
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int l=0,r=1e12,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(pd(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout << ans;
	return 0;
}