#include <bits/stdc++.h>
using namespace std;
int n,m,cnt[1005],minn=0x7fffffff;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int num;
		scanf("%d",&num);
		cnt[num]++;
	}
	for(int i=1;i<=n;i++)
		minn=min(cnt[i],minn);
	printf("%d",minn);
	return 0;
}