#include <bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005][5005],q,l,r,maxn[5005][5005];
void init(void)
{
	for(int j=1;j<n;j++)
		for(int i=1;i+j<=n;i++)
			f[i][i+j]=(f[i][i+j-1]^f[i+1][i+j]);
	for(int i=1;i<=n;i++) maxn[i][i]=a[i];
	for(int j=1;j<n;j++)
		for(int i=1;i+j<=n;i++)
			maxn[i][i+j]=max(f[i][i+j],max(maxn[i][i+j-1],maxn[i+1][i+j]));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i][i]=a[i];
	init();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",maxn[l][r]);
	}
	return 0;
}