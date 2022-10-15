#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a, b;
int main(int argc, char const *argv[])
{
	scanf("%d%d", &a, &b);
	if (a == b)
	{
		printf("%d %d", a * 10, a * 10 + 1);
		return 0;
	}
	if (b == a + 1)
	{
		printf("%d %d", a, b);
		return 0;
	}
	if (a == 9 && b == 1)
	{
		printf("9 10");
		return 0;
	}
	printf("-1");
	return 0;
}