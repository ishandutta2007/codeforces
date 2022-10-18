#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 305
int a[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	bool ok=true;
	if(n%2==0)
	{
		int ans=a[1]*a[n];
		for(int i=1;i<=n/2;i++)
		{
			if(a[i]*a[n-i+1]!=ans)
			{
				cout<<"-1\n";
				return ;
			}
		}
		int res=1;
		int t=ans;
		for(int i=2;i*i<=t;i++)
		{
			int tmp=0;
			while(t%i==0) tmp++,t/=i;
			res*=(tmp+1);
		}
		if(t!=1) res*=2;
		if(res!=n+2) cout<<"-1\n";
		else cout<<ans<<endl;
	}
	else
	{
		int ans=a[1]*a[n];
		for(int i=1;i<=n/2+1;i++)
		{
			if(a[i]*a[n-i+1]!=ans)
			{
				cout<<"-1\n";
				return ;
			}
		}
		int res=1;
		int t=ans;
		for(int i=2;i*i<=t;i++)
		{
			int tmp=0;
			while(t%i==0) tmp++,t/=i;
			res*=(tmp+1);
		}
		if(t!=1) res*=2;
		if(res!=n+2) cout<<"-1\n";
		else cout<<ans<<endl;
	}
}
signed main()
{
	int T;
	cin>>T;
	while(T--) work();
	return 0;
}