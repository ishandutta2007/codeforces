#include <bits/stdc++.h>
using namespace std;
int n;
char ch;
int a[200007],b[200007];
int cnt0=0,cnt1=0,now1=0,now2=0;
long long ans=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		ch=getchar();
		while (ch!='0'&&ch!='1') ch=getchar();
		a[i]=ch-'0';
	}
	for (int i=1;i<=n;i++)
	{
		ch=getchar();
		while (ch!='0'&&ch!='1') ch=getchar();
		b[i]=ch-'0';
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0) ++cnt0; else ++cnt1;
		if (a[i]==0&&b[i]==1) ++now1;
		if (a[i]==1&&b[i]==1) ++now2;
	}
	ans=1LL*cnt0*cnt1-1LL*now1*now2;
	printf("%lld\n",ans);
	return 0;
}