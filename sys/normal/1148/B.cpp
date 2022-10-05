#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,m,t1,t2,k,ans,a[Maxn],b[Maxn];
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&t1,&t2,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	if(k>=n||k>=m)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<=k;i++)
	{
		int tmp=k-i,now=a[i+1]+t1;
		int pos=lower_bound(b+1,b+1+m,now)-b;
		if(pos+tmp>m)
		{
			printf("-1");
			return 0;
		}
		ans=max(ans,b[pos+tmp]+t2);
	}
	printf("%d",ans);
	return 0;
}