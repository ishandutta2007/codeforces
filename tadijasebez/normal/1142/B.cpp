#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int L=18;
int p[N],a[N],pre[N],lst[N],par[N][L],mn[N];
int main()
{
	int n,m,q,i,j;
	scanf("%i %i %i",&n,&m,&q);
    for(i=1;i<=n;i++) scanf("%i",&p[i]);
    for(i=2;i<=n;i++) pre[p[i]]=p[i-1];
    pre[p[1]]=p[n];
    for(i=1;i<=m;i++)
	{
		scanf("%i",&a[i]);
		mn[i]=N;
		lst[a[i]]=i;
		par[i][0]=lst[pre[a[i]]];
		for(j=1;j<L;j++) par[i][j]=par[par[i][j-1]][j-1];
		int k=i;
		for(j=0;j<L;j++) if(n-1>>j&1) k=par[k][j];
        mn[k]=min(mn[k],i);
	}
	for(i=m-1;i;i--) mn[i]=min(mn[i],mn[i+1]);
	while(q--)
	{
		int l,r;
		scanf("%i %i",&l,&r);
		if(mn[l]<=r) printf("1");
		else printf("0");
	}
	return 0;
}