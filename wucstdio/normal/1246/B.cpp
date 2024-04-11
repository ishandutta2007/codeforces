#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,k,a[100005],c[100005];
ll ans=0;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int v=a[i];
		ll val=1;
		for(int j=2;j*j<=v;j++)
		{
			int cnt=0;
			while(v%j==0)
			{
				cnt++;
				v/=j;
			}
			if(cnt>=k)
			{
				int d=1;
				for(int l=1;l<=k;l++)d=d*j;
				while(a[i]%d==0)a[i]/=d;
			}
			cnt%=k;
			cnt=(k-cnt)%k;
			while(cnt--)
			{
				val=val*j;
				if(val>100000)val=100001;
			}
		}
		if(v!=1)
		{
			for(int j=1;j<k;j++)
			{
				val=val*v;
				if(val>100000)
				{
					val=100001;
					break;
				}
			}
		}
		ans+=c[val];
		c[a[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}