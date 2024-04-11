#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 2010;
int n;
int a[N];
int ans[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int x = 1;
	for (int z = N; z >= 0; z--)
	{
		int y = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != z) continue;
			ans[i] = x;
			y++;
		}
		x += y;
	}
	for (int i =0 ; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}