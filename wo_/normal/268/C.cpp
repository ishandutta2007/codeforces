#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	printf("%d\n",min(N,M)+1);
	int a=min(N,M)+1;
	for(int i=0;i<a;i++)
	{
		printf("%d %d\n",i,a-i-1);
	}
	return 0;
}