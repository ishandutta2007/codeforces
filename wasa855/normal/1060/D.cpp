#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d %I64d",&a[i],&a[i+n]);
	}
	ll ans=n;
	sort(a+1,a+n+1);
	sort(a+n+1,a+n+n+1);
	for(int i=1;i<=n;i++)
	{
		ans+=max(a[i],a[i+n]);
	}
	cout<<ans<<endl;
	return 0;
}
//asdoiuhepoisatjpoi0xujtersygbtr