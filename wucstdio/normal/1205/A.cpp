#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(!(n&1))
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	  printf("%d ",2*i-(i&1));
	for(int i=1;i<=n;i++)
	  printf("%d ",2*i-1+(i&1));
	printf("\n");
	return 0;
}