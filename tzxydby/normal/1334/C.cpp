#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,a[N],b[N],c[N];
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=2;i<=n;i++)
		c[i]=max(a[i]-b[i-1],0LL);
	c[1]=max(a[1]-b[n],0LL);
	int zh=a[1];
	for(int i=2;i<=n;i++)
		zh+=c[i];
	int ans=zh;
	for(int i=2;i<=n;i++)
	{
		zh=zh-a[i-1]+c[i-1]-c[i]+a[i];
		ans=min(ans,zh);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		work();
	return 0;
}