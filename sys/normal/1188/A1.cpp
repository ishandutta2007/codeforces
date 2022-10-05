#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,cnt[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cnt[x]++,cnt[y]++;
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]==2)
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}