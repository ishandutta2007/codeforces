#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = (int)1e9;
const int N = 1010;
const int K = 10;
int ans[N];
int n;

int main()
{
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		ans[i] = INF;
	for (int i = 0; i < K; i++)
		for (int x = 0; x < 2; x++)
		{
			vector<int> t;
			for (int j = 0; j < n; j++)
			{
				if (((j >> i) & 1) == x)
					t.push_back(j + 1);
			}
			if (t.empty()) continue;
			printf("%d\n", (int)t.size());
			for (int y : t)
				printf("%d ", y);
			printf("\n");
			fflush(stdout);
			for (int j = 0; j < n; j++)
			{
				int y;
				scanf("%d", &y);
				if (((j >> i) & 1) != x)
					ans[j] = min(ans[j], y);
			}
		}
	printf("-1\n");
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	fflush(stdout);
//	scanf("%d", &n);

	return 0;
}