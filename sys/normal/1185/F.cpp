#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,m,mini[Maxn],price[Maxn],pnt[Maxn],P1,P2,ans=-1,ans2,cnt[Maxn];
int main()
{
	memset(mini,0x3f,sizeof(mini));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			int a;
			scanf("%d",&a);
			tmp+=1<<(a-1);
		}
		cnt[tmp]++;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&price[i]);
		int tmp=0;
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			int a;
			scanf("%d",&a);
			tmp+=1<<(a-1);
		}
		if(mini[tmp]>price[i])
			mini[tmp]=price[i],pnt[tmp]=i;
	}
	int maxi=(1<<9)-1;
	for(int i=0;i<=maxi;i++)
		if(mini[i]!=0x3f3f3f3f)
			for(int j=i+1;j<=maxi;j++)
				if(mini[j]!=0x3f3f3f3f)
				{
					int tmp=0;
					for(int k=0;k<=maxi;k++)
						if((k&(i|j))==k) tmp+=cnt[k];
					if(tmp>ans) ans=tmp,ans2=mini[i]+mini[j],P1=pnt[i],P2=pnt[j];
					if(tmp==ans)
						if(ans2>mini[i]+mini[j])
							P1=pnt[i],P2=pnt[j],ans2=mini[i]+mini[j];
				}
	if(!P1)
		P1=1,P2=2;
	printf("%d %d",P1,P2);
	return 0;
}