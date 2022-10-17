#include <cstdio>
#include <algorithm>

const int N = 500;
int n, m;
bool cur[N];
std::pair<int, int> a[N];

int query() {
	printf("? ");
	for (int i = 0; i < m; ++i) printf("%d", (int)cur[i]);
	printf("\n");
	fflush(stdout);
	int re;
	scanf("%d", &re);
	return re;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		cur[i] = 1;
		a[i].first = query();
		cur[i] = 0;
		a[i].second = i;
	}
	std::sort(a, a + m);
	int sum = 0;
	for (int i = 0; i < m; ++i) {
		cur[a[i].second] = 1;
		if (sum + a[i].first != query()) cur[a[i].second] = 0;
		else sum += a[i].first;
	}
	printf("! %d\n", sum);
	return 0;
}