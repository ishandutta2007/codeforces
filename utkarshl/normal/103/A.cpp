#include"cstdio"
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	unsigned long long ans=0;
	for(int x=1;x<=n;x++)
	{
		int ai;
		scanf("%d",&ai);
		ans+=1+((long long)x)*(ai-1);
	}
	printf("%I64u",ans);
}