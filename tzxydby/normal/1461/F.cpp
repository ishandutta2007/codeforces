#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
string st;
int n,a[N],ans[N],f1,f2,f3;
void sol(int l,int r)
{
	if(l>r)
		return;
	if(a[l]==1)
	{
		ans[l]=2;
		sol(l+1,r);
		return;
	}
	if(a[r]==1)
	{
		ans[r-1]=2;
		sol(l,r-1);
		return;
	}
	int ml=1;
	for(int i=l;i<=r;i++)
	{
		ml*=a[i];
		if(ml>=1e5)
		{
			for(int j=l;j<r;j++)
				ans[j]=1;
			return;
		}
	}
	int m=0,x[20],y[20],dp[20],p[20];
	x[0]=0,y[0]=1;
	for(int i=l;i<=r;i++)
	{
		if(a[i]!=1)
		{
			m++;
			x[m]=i;
			y[m]=y[m-1]*a[i];
		}
	}
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		dp[i]=0;
		for(int j=0;j<i;j++)
		{
			int c=dp[j]+x[j+1]-x[j]-1+y[i]/y[j];
			if(dp[i]<c)
			{
				dp[i]=c;
				p[i]=j;
			}
		}
	}
	int w=m;
	for(int i=l;i<r;i++)
		ans[i]=2;
	while(w)
	{
		for(int i=x[w]-1;i>=x[p[w]+1];i--)
			ans[i]=1;
		w=p[w];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>st;
	if(st.size()==1)
	{
		for(int i=1;i<n;i++)
			cout<<a[i]<<st[0];
		cout<<a[n];
		return 0;
	}
	for(int i=0;i<st.size();i++)
	{
		if(st[i]=='*')
			f1=1;
		if(st[i]=='+')
			f2=1;
		if(st[i]=='-')
			f3=1;
	}
	if(!f1)
	{
		for(int i=1;i<n;i++)
			cout<<a[i]<<'+';
		cout<<a[n];
		return 0;
	}
	if(!f2)
	{
		int p=0;
		for(int i=1;i<=n;i++)
		{
			if(!a[i])
			{
				p=i;
				break;
			}
		}
		if(!p)
		{
			for(int i=1;i<n;i++)
				cout<<a[i]<<'*';
			cout<<a[n];
		}
		else
		{
			if(p==1)
			{
				for(int i=1;i<n;i++)
					cout<<a[i]<<'*';
				cout<<a[n];
			}
			else
			{
				cout<<a[1];
				for(int i=2;i<p;i++)
					cout<<"*"<<a[i];
				cout<<"-"<<a[p];
				for(int i=p+1;i<=n;i++)
					cout<<"*"<<a[i];
			}
		}
		return 0;
	}
	int las=1;
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			sol(las,i-1);
			ans[i-1]=ans[i]=2;
			las=i+1;
		}
	}
	sol(las,n);
	for(int i=1;i<n;i++)
		cout<<a[i]<<(ans[i]==1?'*':'+');
	cout<<a[n];
	return 0;
}