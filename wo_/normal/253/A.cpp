#include<cstdio>

using namespace std;

int B,G;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&B,&G);
	if(B<G)
	{
		for(int i=0;i<B;i++)
		{
			printf("GB");
		}
		for(int i=0;i<G-B;i++)
		{
			printf("G");
		}
		printf("\n");
	}
	else
	{
		for(int i=0;i<G;i++)
		{
			printf("BG");
		}
		for(int i=0;i<B-G;i++)
		{
			printf("B");
		}
		printf("\n");
	}
	return 0;
}