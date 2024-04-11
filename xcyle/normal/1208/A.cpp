#include <iostream>
#include <cstdio>
using namespace std;
int T, a, b, n;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &a, &b, &n);
		if(n % 3 == 0) printf("%d\n", a);
		if(n % 3 == 1) printf("%d\n", b);
		if(n % 3 == 2) printf("%d\n", (a ^ b));
	}
	return 0;
}