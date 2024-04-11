#include<cstdio>

using namespace std;

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	if(N*(N-1)/2<=K)
	{
		printf("no solution\n");
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		printf("%d %d\n",0,i*2);
	}
	return 0;
}