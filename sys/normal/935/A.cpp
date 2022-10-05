#include <bits/stdc++.h>
using namespace std;
int n,ans;
bool vis[100006];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if((n/((double)i))==n/i&&(!vis[i]))
			ans++;
	}
	printf("%d",ans-1);
	return 0;
}