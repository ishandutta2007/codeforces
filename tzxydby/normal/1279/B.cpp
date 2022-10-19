#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int a[N],sum[N],n,s,t;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		int mx=0,k=0;
		for(int i=0;i<=n;i++)
		{
			int p=upper_bound(sum+1,sum+n+1,s+a[i])-sum;
			if(sum[i-1]>s)
				continue;
			if(p>mx)
				mx=p,k=i;
		}
		cout<<k<<endl;
	}
	return 0;
}