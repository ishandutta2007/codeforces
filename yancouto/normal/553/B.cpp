#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull fib[60];

void solve(int s, int *v, ull k) {
	if(s <= 1) return;
	ull m = fib[s];
	if(k <= fib[s - 1]) solve(s - 1, v + 1, k);
	else {
		swap(v[0], v[1]);
		solve(s - 2, v + 2, k - fib[s - 1]);
	}
}

int main() {
	int i;
	fib[0] = fib[1] = 1;
	for(i = 2; i <= 53; i++) fib[i] = fib[i - 1] + fib[i - 2];
	int vv[55];
	int n; ull k;
	scanf("%d %I64u", &n, &k);
	for(i = 0; i < n; i++)
		vv[i] = i + 1;
	solve(n, vv, k);
	printf("%d", vv[0]);
	for(i = 1; i < n; i++)
		printf(" %d", vv[i]);
	printf("\n");
	return 0;
}