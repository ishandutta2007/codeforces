#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int b,k;
int main()
{
	scanf("%d%d",&b,&k);
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		ans=ans*b+x&1;
	}
	if(ans)printf("odd\n");
	else printf("even\n");
	return 0;
}