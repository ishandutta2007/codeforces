#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n;
long long x[Maxn],sum;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i+=2)
		scanf("%d",&x[i]);
	for(int i=2;i<=n;i+=2)
	{
		int maxi=sqrt(x[i]);
		if(!(x[i]%2)&&x[i]/2%2)
		{
			printf("No");
			return 0;
		}
		for(int j=maxi;j>=1;j--)
		{
			if(x[i]%j==0&&(!((j%2)^((x[i]/j)%2))))
			{
				long long tmp=(x[i]/j-j)/2;
				x[i-1]=tmp*(long long)tmp-sum;
				if(x[i-1]<=0) continue;
				break;
			}
		}
		sum+=x[i-1]+x[i];
	}
	for(int i=1;i<=n;i++)
		if(x[i]<=0)
		{
			printf("No");
			return 0;
		}
	printf("Yes\n");
	for(int i=1;i<=n;i++)
		printf("%lld ",x[i]);
	return 0;
}