#include<cstdio>

using namespace std;

int main()
{
	int ans=0;
	int d,n;
	scanf("%d",&d);
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int in;
		scanf("%d",&in);
		ans+=(d-in);
	}
	printf("%d\n",ans);
	return 0;
}