#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,q,p[200005],pre[200005],a[200005],last[200005],pa[200005],anc[26][200005];
int findnth(int x)
{
	int ans=x;
	for(int i=0;i<20;i++)
	  if((1<<i)&(n-1))ans=anc[i][ans];
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		pre[p[i%n+1]]=p[i];
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		last[a[i]]=i;
		pa[i]=last[pre[a[i]]];
	}
	for(int i=1;i<=m;i++)anc[0][i]=pa[i];
	for(int i=1;i<=25;i++)
	  for(int j=1;j<=m;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
	for(int i=1;i<=m;i++)
	{
		p[i]=findnth(i);
		p[i]=max(p[i],p[i-1]);
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(p[r]>=l)putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}