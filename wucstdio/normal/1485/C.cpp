#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,x,y;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		y=min(y,x-1);
		ll ans=0;
		int b=1;
		for(b=1;b<=y&&(b+1)*(b-1)<=x;b++)
		{
//			printf("%d %d\n",b,b-1);
			ans+=b-1;
		}
		for(;b<=y;)
		{
			int k=x/(b+1);
			int bb=x/k;
			bb=min(bb,y+1);
//			printf(" %d %d\n",k,bb);
			ans+=1ll*(bb-b)*k;
			b=bb;
		}
		printf("%lld\n",ans);
	}
	return 0;
}