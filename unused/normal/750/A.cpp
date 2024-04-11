#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	scanf("%d%d", &a,&b);

	int sum = 0;
	int i;
	for (i = 1; i <= a; i++)
	{
		sum += i * 5;
		if (sum + b > 240) break;
	}
	printf("%d", i - 1);
}