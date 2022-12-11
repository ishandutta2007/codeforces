#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		long long y;
		scanf("%d%d%lld",&n,&x,&y);
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			x^=a;
		}
		puts((x&1)==(y&1)?"Alice":"Bob");
	}
	return 0;
}