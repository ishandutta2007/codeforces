#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,d[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==2)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}