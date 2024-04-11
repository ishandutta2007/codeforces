#include <bits/stdc++.h>
#define Maxn 200007
#define modp 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int a[Maxn],f[Maxn];
int sum;
int power(int a,int b)
{
	int res=1,now=a,left=b;
	while (left>0)
	{
		if (left%2==1) res=(1LL*res*now)%modp;
		left/=2;
		now=(1LL*now*now)%modp;
	}
	return res;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	f[0]=0;
	f[1]=(1LL*power(sum,modp-2)*((1LL*(sum-1)*(sum-1))%modp))%modp;
	for (int i=1;i<=100005;i++)
	{
		f[i+1]=(2LL*f[i]-f[i-1]-((1LL*(sum-1)*power(sum-i,modp-2)))%modp)%modp;
		f[i+1]=(f[i+1]+modp)%modp;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=(ans+f[a[i]])%modp;
	printf("%d\n",ans);
	return 0;
}