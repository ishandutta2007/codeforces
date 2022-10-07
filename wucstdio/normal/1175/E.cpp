#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,f[500005],anc[26][500005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		f[l]=max(f[l],r);
	}
	for(int i=1;i<=500000;i++)
	{
		f[i]=max(f[i],i);
		f[i]=max(f[i],f[i-1]);
		anc[0][i]=f[i];
	}
	anc[0][0]=f[0];
	for(int i=1;i<=20;i++)
	  for(int j=0;j<=500000;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int i=20;i>=0;i--)
		  if(anc[i][l]<r)
		    l=anc[i][l],ans+=1<<i;
		ans++;
		if(ans<=n)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}