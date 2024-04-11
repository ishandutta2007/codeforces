#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (n == 4) printf("-1\n");
	else if (k <= n || k > n * (n - 1) / 2 - 2) printf("-1\n");
	else
	{
		vector<int> vis;
		int idx = 1;
		vis.push_back(a);
		vis.push_back(c);
		while (idx == a || idx == b || idx == c || idx == d) idx++;
		vis.push_back(idx);
		vis.push_back(d);
		while (++idx <= n)
		{
			if (idx == a || idx == b || idx == c || idx == d) continue;
			vis.push_back(idx);
		}
		vis.push_back(b);

		for (int i : vis)
		{
			printf("%d ", i);
		}
		printf("\n");
		printf("%d ", vis[1]);
		printf("%d ", vis[0]);
		printf("%d ", vis[2]);
		for (int i = vis.size() - 1; i >= 3; i--) printf("%d ", vis[i]);
		printf("\n");
	}
}