#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, m, mi=1000000000, ma=0, mi2=1000000000, ma2=0;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		mi=min(mi, a);
		ma=max(ma, a);
	}
	for(int i=0; i<m; i++)
	{
		int a;
		scanf("%d", &a);
		mi2=min(mi2, a);
		ma2=max(ma2, a);
	}
	int w=max(ma, mi*2);
	if(mi2<=w) printf("-1\n");
	else printf("%d\n", w);
	return 0;
}