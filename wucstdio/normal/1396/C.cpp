#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[1000005],r1,r2,r3,d,f[1000005][4];
int main()
{
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	memset(f,0x3f,sizeof(f));
	f[0][0]=-d;
	for(int i=1;i<=n;i++)
	{
		ll v1=min(r1,r3)*a[i]+r3;
		ll v2=min(r2+min(r1,r3),min(r1,r3)*(a[i]+2));
		f[i][0]=min(f[i-1][0]+d+v1,f[i-1][2]+d+v1);
		f[i][1]=min(min(f[i-1][0],f[i-1][2])+d+min(v1,v2),f[i-1][1]+3*d+min(v1,v2));
		f[i][2]=f[i-1][1]+3*d+min(v1,v2);
		f[i][3]=min(min(f[i-1][0],f[i-1][2])+d+min(v1,v2),f[i-1][3]+2*d+min(v1,v2));
		if(i==n)f[i][3]=f[i-1][3]+2*d+v1;
//		printf("%lld %lld %lld %lld\n",f[i][0],f[i][1],f[i][2],f[i][3]);
	}
	printf("%lld\n",min(min(f[n][0],f[n][2]),f[n][3]));
	return 0;
}