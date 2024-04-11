#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	bool nega=false;
	if(ch==45)
	{
		nega=true;
	}
	while(!isdigit(ch))
	{
		ch=getchar();
		if(ch==45)
		{
			nega=true;
		}
	}
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	if(nega==true)
	{
		return -ans;
	}
	return ans;
}
int a[200005];
signed main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		a[i]=read();
	}
	int minn=a[1];
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		sum+=a[i];
		if(sum<minn)
		{
			minn=sum;
		}
	}
	if(minn<=k)
	{
		int tmp=0;
		for(int i=1;i<=k;i++)
		{
			tmp+=a[i];
			if(n+tmp<=0)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	if(sum>=0)
	{
		cout<<"-1\n";
		return 0;
	}
	int ans=k*((n+minn-sum-1)/(-sum));
//	cout<<ans<<endl;
	int tmp=0;
	int m=n-(((n+minn-sum-1)/(-sum)))*(-sum);
	for(int i=1;i<=k;i++)
	{
		tmp+=a[i];
		if(m+tmp<=0)
		{
			cout<<i+ans<<endl;
			return 0;
		}
	}
	return 0;
}