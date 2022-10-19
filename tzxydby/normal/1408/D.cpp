#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,m,a[N],b[N],c[N],d[N],f[N],ans=1e9;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&c[i],&d[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[j]>=a[i])
				f[c[j]-a[i]]=max(f[c[j]-a[i]],d[j]-b[i]+1);
	for(int i=2000000;i>=0;i--)
	{
		f[i]=max(f[i],f[i+1]);
		ans=min(ans,i+f[i]);
	}
	printf("%d\n",ans);
	return 0;
}