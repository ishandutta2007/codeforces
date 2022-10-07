#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,x[1005],y[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		if(n&1)printf("1\n");
		else printf("%lld\n",1ll*(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1));
	}
	return 0;
}