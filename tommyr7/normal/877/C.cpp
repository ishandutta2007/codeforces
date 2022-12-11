#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n,cnt=0;
int ans[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i+=2) ans[++cnt]=i;
	for (int i=1;i<=n;i+=2) ans[++cnt]=i;
	for (int i=2;i<=n;i+=2) ans[++cnt]=i;
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}