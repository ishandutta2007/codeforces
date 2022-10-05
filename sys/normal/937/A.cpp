#include <bits/stdc++.h>
using namespace std;
int n,a[105],cnt;
bool vis[605];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]&&!vis[a[i]]){cnt++,vis[a[i]]=true;}
	}
	printf("%d",cnt);
	return 0;
}