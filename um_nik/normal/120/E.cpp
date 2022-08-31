#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int t;
int n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", (n + 1) & 1);
	}

	return 0;
}