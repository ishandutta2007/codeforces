#include <bits/stdc++.h>
using namespace std;

vector<int> num;

int main()
{
	int n;
	scanf("%d", &n);

	if (n % 2)
	{
		printf("%d\n3 ", 1 + (n - 3) / 2);
		for (int i = 0; i < (n - 3) / 2; i++) printf("2 ");
		printf("\n");
	}
	else
	{
		printf("%d\n", n / 2);
		for (int i = 0; i < n / 2; i++) printf("2 ");
		printf("\n");
	}
}