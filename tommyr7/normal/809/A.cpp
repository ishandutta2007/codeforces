#include <bits/stdc++.h>
#define modp 1000000007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int bin[300007],x[300007];
int n;
int main()
{
	n=read();
	bin[0]=1;
	for (int i=1;i<=n;i++)
		bin[i]=(2LL*bin[i-1])%modp;
	for (int i=1;i<=n;i++)
		x[i]=read();
	sort(x+1,x+n+1);
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=(ans+modp+(1LL*x[i]*(bin[i-1]-bin[n-i]+modp))%modp)%modp;
	printf("%d\n",ans);
	return 0;
}