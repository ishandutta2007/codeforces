#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,x;
ll a[300005],f[300005][5],ans;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		f[i][0]=max(f[i-1][0]+a[i],a[i]);
		f[i][1]=max(max(f[i-1][0],f[i-1][1])+a[i]*x,a[i]*x);
		f[i][2]=max(max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+a[i],a[i]);
		ans=max(ans,f[i][2]);
		ans=max(ans,f[i][0]);
		ans=max(ans,f[i][1]);
	}
	printf("%I64d\n",ans);
	return 0;
}