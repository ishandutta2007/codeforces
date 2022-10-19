#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,a[N],b[N],ans,tot;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		tot+=a[i]*b[i];
	ans=tot;
	for(int i=1;i<=n;i++)
	{
		int sum=tot;
		int l=i-1,r=i+1;
		while(l>=1&&r<=n)
		{
			sum-=a[l]*b[l]+a[r]*b[r];
			sum+=a[l]*b[r]+a[r]*b[l];
			ans=max(ans,sum);
			l--,r++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int sum=tot;
		int l=i,r=i+1;
		while(l>=1&&r<=n)
		{
			sum-=a[l]*b[l]+a[r]*b[r];
			sum+=a[l]*b[r]+a[r]*b[l];
			ans=max(ans,sum);
			l--,r++;
		}
	}
	cout<<ans<<endl;
	return 0;
}