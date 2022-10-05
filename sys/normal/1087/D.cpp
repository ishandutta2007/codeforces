#include <bits/stdc++.h>
using namespace std;
int n,s,cnt,vis[200005];
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		vis[a]++,vis[b]++;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==1) cnt++;
	printf("%.10lf",s/(double)cnt*2);
	return 0;
}