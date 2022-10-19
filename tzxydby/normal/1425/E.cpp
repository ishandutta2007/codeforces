#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,k,a[N],d[N],s[N],mx[N],ans,m1=1e18,m2=1e18;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--)
		mx[i]=max(mx[i+1],s[n]-s[i-1]-d[i]);
	if(k==0)
		cout<<mx[1]<<endl;
	else if(k==1)
	{
		for(int i=1;i<n;i++)
		{
			m1=min(m1,d[i]);
			if(i!=1)
				m2=min(m2,min(a[i],d[i]));
			ans=max(ans,mx[i+1]+max(s[i]-m1,0LL));
		}
		ans=max(ans,s[n]-d[1]-m2);
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<n;i++)
			m1=min(m1,d[i]);
		ans=max(ans,s[n]-m1);
		ans=max(ans,a[n]-d[n]);
		cout<<ans<<endl;
	}
	return 0;
}