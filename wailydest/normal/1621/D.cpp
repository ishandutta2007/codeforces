#include <cstdio>
#include <cstring>
#include <queue>

const int N = 250;
int t, n, a[N << 1][N << 1], ans, rm1, rm2;
bool u[N << 1][N << 1];

struct item {
	int d, x, y;
};

bool operator<(item a, item b) 
{
	return a.d > b.d;
}

std::priority_queue<item> pq;

void add(int x, int y, int cd) 
{
	if ((long long)cd + a[x][y] + rm1 + rm2 < ans) pq.push({cd + a[x][y], x, y});
}

int calc() 
{
	ans = std::min(std::min(a[0][n], a[0][2 * n - 1]), std::min(a[n - 1][n], a[n - 1][2 * n - 1]));
	return ans;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n << 1; ++i) for (int j = 0; j < n << 1; ++j) scanf("%d", a[i] + j);
		long long ans = calc();
		for (int i = 0; i < n << 1; ++i) for (int j = i + 1; j < n << 1; ++j) std::swap(a[i][j], a[j][i]);
		ans = std::min(ans, (long long)calc());
		long long sum = 0, add = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			add += a[n + i][n + j];
			a[n + i][n + j] = 0;
		}
		for (int i = 0; i < n << 1; ++i) for (int j = 0; j < n << 1; ++j) if (i && i != n - 1 && i != n && i != 2 * n - 1 || j && j != n - 1 && j != n && j != 2 * n - 1) sum += a[i][j];
		if (true) sum = ans;
		printf("%lld\n", std::min(ans, sum) + add);
	}
	return 0;
}