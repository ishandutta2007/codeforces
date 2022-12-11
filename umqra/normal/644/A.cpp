#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 200;
int n, a, b;
int table[N][N];

bool trySit(int t)
{
	int odd = 1, even = 2;
	for (int i = 0; i < a; i++)
	{
		for (int s = 0; s < b; s++)
		{
			if ((i + s) % 2 == t && odd <= n)
			{
				table[i][s] = odd;
				odd += 2;
			}
			else if ((i + s) % 2 != t && even <= n)
			{
				table[i][s] = even;
				even += 2;
			}
		}
	}
	return odd > n && even > n;
}

void printAns()
{
	for (int i = 0; i < a; i++)
	{
		for (int s = 0; s < b; s++)
			printf("%d ", table[i][s]);
		puts("");
	}
}

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	if (trySit(0))
		printAns();
	else if (trySit(1))
		printAns();
	else
		puts("-1");
	return 0;
}