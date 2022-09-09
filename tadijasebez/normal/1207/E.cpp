#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	printf("? ");
	for(int i=1;i<=100;i++)
	{
		printf("%i ",i);
	}
	printf("\n");
	fflush(stdout);
	int x;scanf("%i",&x);
	printf("? ");
	for(int i=1;i<=100;i++)
	{
		printf("%i ",i<<7);
	}
	printf("\n");
	fflush(stdout);
	int y;scanf("%i",&y);
	int ans=(y&((1<<7)-1))+((x>>7)<<7);
	printf("! %i\n",ans);
	fflush(stdout);
	return 0;
}