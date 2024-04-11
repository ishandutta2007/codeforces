#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int a, b, li=0, wynik=0;
	scanf("%d%d", &a, &b);
	while(a!=0)
	{
		wynik+=a;
		li+=a;
		a=li/b;
		li%=b;
	}
	printf("%d\n", wynik);
	return 0;
}