#include <bits/stdc++.h>
#define modp 1000000007
#define Maxn 1007
using namespace std;
int k,p,q;
long long now1,now2;
long long f[Maxn][Maxn];
bool vis[Maxn][Maxn];
long long power(long long a,long long b)
{
	long long ans=1,now=a,left=b;
	while (left>0)
	{
		if (left%2==1) ans=(1LL*ans*now)%modp;
		left/=2;
		now=(1LL*now*now)%modp;
	}
	return ans%modp;
}
int calc(int x,int y)
{
	if (y>=k) return 0;
	if (x>=k) return (x+1LL*now1*power(now2,modp-2)%modp)%modp;
	if (vis[x][y]) return f[x][y];
	vis[x][y]=true;
	int res=(1LL*now1*calc(x+1,y))%modp;
	res=(res+1LL*now2*(x+calc(x,x+y))%modp)%modp;
	f[x][y]=res;
	return res;
}
int main()
{
	scanf("%d%d%d",&k,&p,&q);
	int now=power(p+q,modp-2);
	now1=(1LL*p*now)%modp;
	now2=(1LL*q*now)%modp;
	memset(f,0,sizeof(f));
	memset(vis,false,sizeof(vis));
	printf("%d\n",calc(1,0)%modp);
	return 0;
}