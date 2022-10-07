#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,k,x[100005];
int m;
int main()
{
	scanf("%lld%d%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld",&x[i]);
	int d=0,ans=0,now=1;
	while(now<=m)
	{
		ans++;
		int i=now;
		while(now<=m&&(x[now]-d-1)/k==(x[i]-d-1)/k)now++;
		d+=now-i;
	}
	printf("%d\n",ans);
	return 0;
}