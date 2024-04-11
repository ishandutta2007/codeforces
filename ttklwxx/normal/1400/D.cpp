#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int t[100001],tans[100001],a[100001];
signed main()
{
	int ttt;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)t[j]=0;
		t[a[i]]=1;
		for(int j=i+1;j<=n;j++)
		{
			t[a[j]]++;
			if(a[j]==a[i])
			{
				ans+=(t[a[i]]-2)*(t[a[i]]-3);
			}
			else
			{
				ans+=(t[a[i]]-1)*(t[a[j]]-1);
			}
		}
	}
	tans[n+1]=0;
	tans[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		tans[i]=tans[i+1];
		for(int j=i+1;j<=n;j++)if(a[i]==a[j])tans[i]++;
	}
	for(int i=1;i<=n;i++)t[i]=0;
	for(int i=1;i<=n;i++)
	{
		t[a[i]]++;
		ans-=(t[a[i]]-1)*tans[i+1];
	}
	printf("%lld\n",ans);
    }
	return 0;
}