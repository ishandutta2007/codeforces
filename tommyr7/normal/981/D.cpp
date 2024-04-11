#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long ans=0;
int n,k;
long long w[57],s[57];
bool f[57][57];
bool check(long long val)
{
	memset(f,false,sizeof(f));
	f[0][0]=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k&&j<=i;j++)
			for (int t=0;t<i;t++)
				if (f[t][j-1]&&((val&(s[i]-s[t]))==val)) f[i][j]=true;
	return f[n][k];
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++)
		s[i]=s[i-1]+w[i];
	for (int i=57;i>=0;i--)
		if (check(ans+(1LL<<i))) ans+=(1LL<<i);
	printf("%lld\n",ans);
	return 0;
}