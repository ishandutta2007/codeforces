#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int maxl=2147483647,minr=0;
		while(n--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			maxl=min(maxl,r);
			minr=max(minr,l);
		}
		printf("%d\n",max(0,minr-maxl));
	}
	return 0;
}