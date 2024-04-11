#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,a,b,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&x,&a,&b);
		int ans=abs(a-b)+x;
		ans=min(ans,n-1);
		printf("%d\n",ans);
	}
	return 0;
}