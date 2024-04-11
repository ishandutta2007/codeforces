#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int r,n,t[100005],x[100005],y[100005],f[100005];
int main()
{
	scanf("%d%d",&r,&n);
	f[0]=0;
	x[0]=y[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		f[i]=-2147483647;
		for(int j=max(0,i-r*4);j<i;j++)
		{
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
			  f[i]=max(f[i],f[j]+1);
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}