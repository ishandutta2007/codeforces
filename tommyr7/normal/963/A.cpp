#include <bits/stdc++.h>
#define modp 1000000009
#define Maxn 200007
using namespace std;
int n,a,b,k;
int s[Maxn];
long long power(long long a,long long b)
{
	long long res=1,now=a,left=b;
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
	scanf("%d%d%d%d",&n,&a,&b,&k);
	for (int i=0;i<k;i++)
	{
		char ch=getchar();
		while (ch!='-'&&ch!='+') ch=getchar();
		if (ch=='-') s[i]=-1; else s[i]=1;
	}
	long long now1=power(a,k),now2=power(b,k);
	if (now1!=now2)
	{
		long long ans=0;
		for (int i=0;i<k&&i<=n;i++)
		{
			int x=(n-i)%k;
			int m=(n-i-x)/k;
			long long val=(1LL*power(a,x)*power(b,i))%modp;
			long long val1=power(a,k),val2=power(b,k);
			long long t1=power(val1,m+1),t2=power(val2,m+1);
			long long del1=(val1-val2+modp)%modp;
			long long del2=(t1-t2+modp)%modp;
			del1=(1LL*del2*power(del1,modp-2))%modp;
			val=(1LL*val*del1)%modp;
			if (s[i]==1) ans=(ans+val)%modp; else ans=(ans-val+modp)%modp;
		}
		printf("%lld\n",ans);
	} else
	{
		long long ans=0;
		for (int i=0;i<k&&i<=n;i++)
		{
			long long val1=power(a,n-i),val2=power(b,i);
			long long val=(1LL*val1*val2)%modp;
			if (s[i]==-1) val=(modp-val)%modp;
			long long t;
			if (i==0) t=(n/k)+1; else t=(k+n-i)/k;
			ans=(ans+(1LL*t*val)%modp)%modp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}