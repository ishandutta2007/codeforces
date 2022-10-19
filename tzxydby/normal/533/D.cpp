#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,x[N],d[N],l[N],r[N],s1[N],s2[N],t,ans;
inline void upd(int v){if(ans>v)ans=v;}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<=n+1;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		d[i]*=2;
	}
	ans=x[n+1];
	t=1,s1[t]=0,s2[t]=1e18;
	for(int i=1;i<=n;i++)
	{
		while(s2[t]<x[i]-s1[t])
			t--;
		r[i]=d[i]-x[i]+s1[t];
		if(r[i]>0)
		{
			t++;
			s1[t]=x[i];
			s2[t]=r[i];
		}
	}
	t=1,s1[t]=x[n+1],s2[t]=1e18;
	for(int i=n;i>=1;i--)
	{
		while(s2[t]<s1[t]-x[i])
			t--;
		l[i]=d[i]-s1[t]+x[i];
		if(l[i]>0)
		{
			t++;
			s1[t]=x[i];
			s2[t]=l[i];
		}
	}
	t=0;
	for(int i=1;i<=n;i++)
	{
		if(l[i]>=x[i]) upd(0);
		else if(l[i]>0) upd(x[i]);
		if(r[i]>=x[n+1]-x[i]) upd(0);
		else if(r[i]>0) upd(x[n+1]-x[i]);
		if(l[i]>0)
		{
			int w=upper_bound(s1+1,s1+t+1,-(x[i]-l[i]))-s1-1;
			if(w)
			{
				int p=s2[w];
				int d=x[i]-x[p];
				if(r[p]>=d&&l[i]>=d)
					upd(0);
				if(r[p]+l[i]>=d)
					upd(d);
			}
		}
		if(r[i]>0)
		{
			while(t&&s1[t]>=-(x[i]+r[i]))
				t--;
			t++;
			s1[t]=-(x[i]+r[i]);
			s2[t]=i;
		}
	}
	if(ans<0)
		ans=0;
	cout<<ans/2.0<<endl;
	return 0;
}