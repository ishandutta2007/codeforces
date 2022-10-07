#include<cstdio>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,now=1;
ll ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>=now)ans+=x-now;
		else ans+=x+n-now;
		now=x;
	}
	printf("%I64d\n",ans);
	return 0;
}