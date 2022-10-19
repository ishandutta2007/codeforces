#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[100005],sl[100005];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	int t,n,m,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=0;i<=m;i++)sl[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),sl[a[i]%m]++;
		ans=0;
		for(int i=0;i<=m/2;i++)
		{
			if(sl[i]==0&&sl[m-i]==0)continue;
			if(i==0)
			{
				ans++;
				continue;
			}
			if(m%2==0&&i==m/2)
			{
				ans++;
				continue;
			}
			ans+=max(abs(sl[i]-sl[m-i]),1);
		}
		printf("%d\n",ans);
	} 
	return 0;
}