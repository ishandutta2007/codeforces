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
		if((n/2)%2)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n/4;i++)printf("%d ",(i*2));
		for(int i=n/4+1;i<=n/2;i++)printf("%d ",(i*2+2));
		for(int i=1;i<=n/2;i++)printf("%d ",(i*2+1));
		printf("\n");
	}
	return 0;
}