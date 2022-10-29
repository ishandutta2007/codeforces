#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int a[500005],pos[500005],b[500005];
int n,k;
inline int cal(int x)
{
	int cnt=0;
//	cout << x << "****\n";
	if(x-1<(n-x)/k) return -1e18;
	for(int i=0;i<(n-x)/k;i++)
		for(int j=0;j<=k;j++) b[++cnt]=i;
	for(int i=1;i<=(n-x)%k;i++) b[++cnt]=(n-x)/k;
	for(int i=(n-x)/k;i<x;i++) b[++cnt]=i;
//	for(int i=1;i<=cnt;i++) cout << b[i] << " ";
//	puts("");
	int ans=0;
//	for(int i=1;i<=n;i++)
//		cout << a[i] << " ";
//	puts("");
	for(int i=1;i<=n;i++) ans+=a[i]*b[i];
//	cout << ans << "****\n";
	return ans;
}
signed main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int now=0,ans=0,s=0,Cnt=0;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			ans+=now*a[i];
			++now;
		}
		cout << ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)
		{
			ans+=now*a[i];
			++now,++Cnt;
			s+=a[i];
		}
	}
	now=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			pos[i]=now;
			ans+=a[i]*pos[i];
			++cnt;
			if(cnt==k) ++now,cnt=0;
		}
	}
	//for(int i=1;i<=n;i++)
	//	cout << cal(i) << " ";
	//puts("");
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int x=cal(mid),y=cal(mid-1);
		if(x>=y) ans=max(ans,x),l=mid+1;
		else ans=max(ans,y),r=mid-2;
	}
	cout << ans;
	return 0;
}