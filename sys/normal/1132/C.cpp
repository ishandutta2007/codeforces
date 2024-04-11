#include <bits/stdc++.h>
using namespace std;
const int Maxn=5005;
int n,q,a[Maxn],cnt[Maxn],tot,now,ans,sum[Maxn],sum2[Maxn],l[Maxn],r[Maxn];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		for(int j=l[i];j<=r[i];j++)
			cnt[j]++;
	}
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+(cnt[i]==1),
		sum2[i]=sum2[i-1]+(cnt[i]==2),tot+=(bool)cnt[i];
	for(int i=1;i<=q;i++)
		for(int j=i+1;j<=q;j++)
		{
			now=tot-(sum[r[i]]-sum[l[i]-1])-(sum[r[j]]-sum[l[j]-1]);
			int lt=max(l[i],l[j]),rt=min(r[i],r[j]);
			if(lt<=rt) now-=sum2[rt]-sum2[lt-1];
			ans=max(ans,now);
		}
	printf("%d",ans);
	return 0;
}