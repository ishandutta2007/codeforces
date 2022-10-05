#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,m,ans,cnt[Maxn],p,val[Maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(!cnt[x]) ans++;
		cnt[x]++;
		if(ans==n)
		{
			for(int i=1;i<=n;i++)
			{
				cnt[i]--;
				if(!cnt[i]) ans--;
			}
			printf("1");
		}
		else printf("0");
	}
	return 0;
}