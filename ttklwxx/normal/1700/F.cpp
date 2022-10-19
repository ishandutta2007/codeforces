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
int a[5][200005];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	int ans=0,h1=0,h2=0;
	for(int i=1;i<=n;i++)
	{
		h1+=a[1][i]-a[3][i];
		h2+=a[2][i]-a[4][i];
		while(h1>0&&h2<0)
		{
			ans++;
			h1--;
			h2++;
		}
		while(h1<0&&h2>0)
		{
			ans++;
			h1++;
			h2--;
		}
		ans+=jdz(h1)+jdz(h2);
	}
	if(h1!=0||h2!=0)printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}