#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[100007],b[100007],m;
long long ans;
int main()
{
	n=read();
	m=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (a[i]>0&&a[i]%2==0) ans+=a[i];
		if (a[i]%2) b[++m]=a[i];
	}
	sort(b+1,b+m+1);
	int tot=0;
	for (int i=m;i;i--) if (b[i]>0)
	{
		ans+=b[i];
		++tot;
	} else break;
	if (tot%2==0)
	{
		long long ans1,ans2;
		ans1=-inf,ans2=-inf;
		if (tot>0&&b[m-tot+1]>0) ans1=ans-b[m-tot+1];
		if (tot<m&&b[m-tot]<0) ans2=ans+b[m-tot];
		ans=max(ans1,ans2);
	}
	cout << ans << endl;
	return 0;
}