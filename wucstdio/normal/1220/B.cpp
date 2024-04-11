#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define rand() (rand()*65536+rand())
using namespace std;
const ll MOD=1000000000;
int n;
ll a[1005][1005],b[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%lld",&a[i][j]);
	ll res1,res2,res3;
	res1=a[1][2];
	res1=res1*a[2][3];
	res2=res1/1000000000;
	res1%=1000000000;
	res1=res1*a[1][3];
	res2=res2*a[1][3];
	res2+=res1/1000000000;
	res3=res2/1000000000;
	res1%=1000000000;
	res2%=1000000000;
	ll l=1,r=1e18;
	while(l<=r)
	{
		ll v=(l+r)/2;
		ll v1=v%MOD;
		ll v2=v/MOD;
		ll v3=0;
		v3=v2*v2;
		v2=2*v1*v2;
		v1=v1*v1;
		v2+=v1/MOD;
		v3+=v2/MOD;
		v1%=MOD;
		v2%=MOD;
		if(v3>res3||v3==res3&&v2>res2||v3==res3&&v2==res2&&v1>res1)r=v-1;
		else l=v+1;
	}
	ll v=r;
	b[1]=v/a[2][3];
	printf("%lld ",b[1]);
	for(int i=2;i<=n;i++)
	  printf("%lld ",a[1][i]/b[1]);
	printf("\n");
	return 0;
}