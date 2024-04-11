#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[105];
bool check12()
{
	int x;
	scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%s",s);
	return x==2;
}
bool check()
{
	int x;
	scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%s",s);
	return x==1;
}
int main()
{
	printf("next 0 1\n");
	fflush(stdout);
	check12();
	printf("next 1\n");
	fflush(stdout);
	while(!check12())
	{
		printf("next 0 1\n");
		fflush(stdout);
		check12();
		printf("next 1\n");
		fflush(stdout);
	}
	printf("next 0 1 2 3 4 5 6 7 8 9\n");
	fflush(stdout);
	while(!check())
	{
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		fflush(stdout);
	}
	printf("done\n");
	return 0;
}