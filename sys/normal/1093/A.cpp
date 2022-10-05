#include <bits/stdc++.h>
using namespace std;
int t,x;
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&x);
		int ans=0;
		ans=x/7;
		x%=7;
		if(x) ans++;
		printf("%d\n",ans);
	}
	return 0;
}