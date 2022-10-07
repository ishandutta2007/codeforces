#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m,k,num[2005];
ll f[2005],a[200005],s[2005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=k;
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<=n)num[x]=max(num[x],y);
	}
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i;j++)
		f[i]=min(f[i],f[i-j]+s[i]-s[i-(j-num[j])]);
	printf("%I64d\n",f[n]);
	return 0;
}