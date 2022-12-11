#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int ans1=a<c?1:-1;
		int ans2=1ll*a*b>c?b:-1;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}