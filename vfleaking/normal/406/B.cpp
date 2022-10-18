#include <iostream>
#include <cstdio>
using namespace std;

const int S = 1000000;

int main()
{
	int n;
	static bool book[S + 1];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		book[a] = true;
	}

	int res_n = 0;
	static int res[S];

	int d = 0;
	for (int i = 1; i <= S / 2; i++)
	{
		if (book[i] && book[S + 1 - i])
			d++;
		else if (book[i])
			res[res_n++] = S + 1 - i;
		else if (book[S + 1 - i])
			res[res_n++] = i;
	}

	for (int i = 1; i <= S / 2 && d > 0; i++)
	{
		if (!book[i] && !book[S + 1 - i])
			res[res_n++] = i, res[res_n++] = S + 1 - i, d--;
	}

	printf("%d\n", res_n);
	for (int i = 0; i < res_n; i++)
		printf("%d ", res[i]);
	printf("\n");

	return 0;
}