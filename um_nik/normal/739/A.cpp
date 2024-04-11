#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n, m;
int k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	k = n;
	while(m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		k = min(k, r - l + 1);
	}
	printf("%d\n", k);
	for (int i = 0; i < n; i++)
		printf("%d ", i % k);
	printf("\n");

	return 0;
}