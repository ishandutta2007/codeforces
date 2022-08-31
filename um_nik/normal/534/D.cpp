#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = (int)2e5 + 200;
int n;
vector<int> a[N];
int ans[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x].push_back(i + 1);
	}
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		while(x >= 0 && a[x].empty()) x -= 3;
		if (x < 0)
		{
			printf("Impossible\n");
			return 0;
		}
		ans[i] = a[x].back();
		a[x].pop_back();
		x++;
	}
	printf("Possible\n");
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}