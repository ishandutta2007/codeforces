#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],cnt1,cnt2,tmp1,tmp2,ans;
int main()
{
//	freopen("A.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) cnt1++;
		else cnt2++;
	}
	for(int i=0;i<k;i++)
	{
		tmp1=cnt1;
		tmp2=cnt2;
		for(int j=1;j<=n;j++)
			if(j%k==i)
			{
				if(a[j]==1) tmp1--;
				else tmp2--;
			}
		ans=max(ans,abs(tmp1-tmp2));
	}
	printf("%d",ans);
	return 0;
}