#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int ans, sum[210000];
vector <int> ve[210000];

void dfs(int k, int f) {
	sum[k] = 1;
	for (int i = 0; i < (int) ve[k].size(); i++)
		if (ve[k][i] != f)
			dfs(ve[k][i], k), sum[k] += sum[ve[k][i]];
	if (sum[k] % 2 == 0)
		ans += 1;
}

int main() {
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", ans - 1);
}