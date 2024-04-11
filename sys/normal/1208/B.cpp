#include <bits/stdc++.h>
using namespace std;
const int Maxn=2005;
int n,a[Maxn],ans=0x3f3f3f3f,cnt,tmpcnt;
map <int,int> Ma,tmp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]),tmp[a[i]]++;
		if(tmp[a[i]]==2) tmpcnt++;
	}
	if(!tmpcnt)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		Ma=tmp;
		cnt=tmpcnt;
		for(int j=i;j<=n;j++)
		{
			Ma[a[j]]--;
			if(Ma[a[j]]==1) cnt--;
			if(!cnt)
			{
				ans=min(ans,j-i+1);
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}