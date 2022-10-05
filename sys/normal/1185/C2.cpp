#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,m,t[Maxn],cnt[105],tot,all;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)
	{
		tot=t[i];
		all=0;
		for(int j=1;j<=100;j++)
		{
			if(tot+cnt[j]*j>m)
			{
				printf("%d ",i-1-(all+(m-tot)/j));
				goto A;
			}
			tot+=cnt[j]*j;
			all+=cnt[j];
		}
		printf("0 ");
		A:cnt[t[i]]++;
	}
	return 0;
}