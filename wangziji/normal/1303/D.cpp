#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int a[100];
inline int LOG(int x)
{
	int rtn=0;
	while(x)
	{
		x>>=1;
		++rtn;
	}
	return rtn-1;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int m,n;
		cin >> m >> n;
		memset(a,0,sizeof a);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int t;
			scanf("%lld",&t);
			sum+=t;
			++a[LOG(t)];
		}
		if(sum<m)
		{
			puts("-1");
			continue;
		}
		int ans=0;
		n=m;
		for(int i=0;i<=62;i++)
		{
			if(n&1)
			{
				if(a[i]) --a[i];
				else
				{
					for(int j=i+1;j<=62;j++)
					{
						if(a[j])
						{
							a[i]=1;
							for(int k=i+1;k<=j;k++)
								++ans,a[k]+=1;
							a[j]-=2;
							break;
						}
					}
				}
			}
			n>>=1;
			a[i+1]+=a[i]/2;
			a[i]&=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}