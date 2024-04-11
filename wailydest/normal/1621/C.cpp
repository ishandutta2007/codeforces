#include <cstdio>
#include <cassert>
#include <cstring>

const int N = 10000;
int t, n, p[N], amt;
bool u[N];

int query(int i) 
{
	++amt;
	assert(amt <= 2 * n);
	printf("? %d\n", i + 1);
	fflush(stdout);
	int re;
	scanf("%d", &re);
	return re - 1;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		amt = 0;
		scanf("%d", &n);
		memset(u, 0, n);
		for (int i = 0; i < n; ++i) if (!u[i]) {
			while (query(i) != i);
			int cur = i;
			do {
				u[cur] = 1;
				p[cur] = query(i);
				cur = p[cur];
			} while (cur != i);
		}
		printf("! ");
		for (int i = 0; i < n; ++i) printf("%d ", p[i] + 1);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}