#include <bits/stdc++.h>
using namespace std;
int x[100005],y[100005],ans,n; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		ans=max(ans,x[i]+y[i]);
	}
	printf("%d",ans);
	return 0;
}