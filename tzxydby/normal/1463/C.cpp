#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,t[N],x[N];
void sol()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>x[i];
	t[n+1]=1e10;
	int l=0,p=0,d,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(t[i]>=l)
		{
			if(p<x[i])
			{
				l=t[i]+x[i]-p;
				d=1;
			}
			else
			{
				l=t[i]+p-x[i];
				d=-1;
			}
			p=x[i];
			if(l<=t[i+1])
				ans++;
		}
		else
		{
			if(d==1)
			{
				int a=p-d*(l-t[i]),b=p-d*max(l-t[i+1],0LL);
				if(a<=x[i]&&x[i]<=b)
					ans++;
			}
			else
			{
				int a=p-d*max(l-t[i+1],0LL),b=p-d*(l-t[i]);
				if(a<=x[i]&&x[i]<=b)
					ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
		sol();
	return 0;
}