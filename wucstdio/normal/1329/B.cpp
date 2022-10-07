#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int d;
ll MOD,f[32];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&d,&MOD);
		if(MOD==1)
		{
			printf("0\n");
			continue;
		}
		if(d==1)
		{
			printf("1\n");
			continue;
		}
		f[0]=1;
		ll ans=1;
		for(int i=1,v=2;i<31;i++,v<<=1)
		{
			f[i]=0;
			for(int j=i-1;j>=0;j--)f[i]+=f[j];
			f[i]++;
			if((v<<1ll)>d)
			{
				f[i]=f[i]%MOD*(d-v+1)%MOD;
				ans+=f[i];
				break;
			}
			f[i]=f[i]%MOD*(1ll<<i)%MOD;
			ans+=f[i];
		}
		ans%=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}