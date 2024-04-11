#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	ll ans=1;
	for(int i=1;i<=n+m;i++)ans=ans*2%MOD;
	printf("%I64d\n",ans);
	return 0;
}