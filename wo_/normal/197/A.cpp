#include<cstdio>

using namespace std;

int main()
{
	int a,b,r;
	scanf("%d%d%d",&a,&b,&r);
	if(a>=2*r&&b>=2*r) printf("First\n");
	else printf("Second\n");
	return 0;
}