#include<iostream>
#include<cstdio>
#include<map>
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
int a[200005];
map<int,int>ma;
signed main()
{
	int t,n,het=0,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		ma.clear();
		n=read();
		het=0;
		for(int i=1;i<=n;i++)a[i]=read(),het+=a[i];
		if((2*het)%n!=0)
		{
			printf("0\n");
			continue;
		}
		het=(2*het)/n;
		ans=0;
		for(int i=1;i<=n;i++)ma[a[i]]++;
		for(int i=1;i<=n;i++)ans+=ma[het-a[i]];
		for(int i=1;i<=n;i++)if(2*a[i]==het)ans--;
		printf("%lld\n",ans/2);
	}
	return 0;
}