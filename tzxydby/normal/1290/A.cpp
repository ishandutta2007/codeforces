#include<bits/stdc++.h>
using namespace std;
const int N=3505;
int a[N],n,m,k,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		k=min(k,m-1);
		int ans=0,res=m-k-1;
		for(int i=0;i<=k;i++)
		{
			int l=i+1,r=n-(k-i)-res,mi=max(a[l],a[r]);
			for(int j=1;j<=res;j++)
			{
				l++;
				r++;
				mi=min(mi,max(a[l],a[r]));
			}
			ans=max(ans,mi);
		}
		printf("%d\n",ans);
	}
	return 0;
}