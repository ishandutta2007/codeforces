#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int t,n,a[N],sum[N],x;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i];
			if(sum[i]>=i*x)
				ans=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}