#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	printf("2\n");
	for (int i = 1; i < n; i++)
	{
		printf("%lld\n", (long long)(i+1)*(i+2)*(i+2)-i);
	}
}