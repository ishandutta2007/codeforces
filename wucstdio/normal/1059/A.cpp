#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,l,a,ans;
int main()
{
	scanf("%d%d%d",&n,&l,&a);
	int last=0;
	for(int i=1;i<=n;i++)
	{
		int t,l;
		scanf("%d%d",&t,&l);
		ans+=(t-last)/a;
		last=t+l;
	}
	ans+=(l-last)/a;
	printf("%d\n",ans);
	return 0;
}