#include <bits/stdc++.h>
#define Maxn 5007
#define modp 1000000007
#define int long long
using namespace std;
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
int f[Maxn][Maxn],n,k;
signed main()
{
	scanf("%lld%lld",&n,&k);
	f[0][0]=1;
	for (int i=1;i<=k;i++)
		for (int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j-1]+(1LL*f[i-1][j]*j)%modp)%modp;
	int ans=0;
	int now1=1,now2=power(2,n),inv=(modp+1)/2,t=1;
	for (int i=0;i<=k;i++)
	{
		ans=(ans+(1LL*now1*((1LL*now2*f[k][i])%modp))%modp)%modp;
		now1=(1LL*now1*(n-i))%modp;
		now2=(1LL*now2*inv)%modp;
	}
	printf("%lld\n",ans%modp);
	return 0;
}