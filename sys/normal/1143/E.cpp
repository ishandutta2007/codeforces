#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,m,q,p[Maxn],nex[Maxn][22],a[Maxn],nxt[Maxn],las[Maxn],mini[Maxn][22],bel[Maxn],cnt;
queue <int> Qu[Maxn];
int ask(int l,int r)
{
	int siz=log2(r-l+1);
	return min(mini[l][siz],mini[r-(1<<siz)+1][siz]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	if(m<n)
	{
		for(int i=1;i<=q;i++)
			printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		nxt[p[i]]=p[i%n+1];
	for(int i=m;i>=1;i--)
	{
		nex[i][0]=las[nxt[a[i]]];
		las[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
		if(!nex[i][0]) nex[i][0]=m+1;
	for(int i=1;(1<<i)<=m;i++)
		for(int j=1;j<=m;j++)
			nex[j][i]=nex[j][i-1]>m?m+1:nex[nex[j][i-1]][i-1];
	for(int i=1;i<=m;i++)
	{
		mini[i][0]=i;
		for(int j=21;j>=0;j--)
			if((n-1)&(1<<j))
			{
				mini[i][0]=nex[mini[i][0]][j];
				if(mini[i][0]==m+1) break;
			}
	}
	for(int i=1;(1<<i)<=m;i++)
		for(int j=1;j<=m;j++)
			mini[j][i]=min(mini[j][i-1],mini[min(m-(1<<(i-1)),j+(1<<(i-1)))][i-1]);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d",ask(l,r)<=r);
	}
	return 0;
}