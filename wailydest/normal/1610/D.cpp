#include <cstdio>
#include <algorithm>

const int md = 1000000007;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}

inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += md;
	return a;
}

const int N = 200005;
const int LG = 60;
int n, cnt[LG], pwr[N];

int main() 
{
	pwr[0] = 1;
	for (int i = 1; i < N; ++i) pwr[i] = add(pwr[i - 1], pwr[i - 1]);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[__builtin_ctz(x)];
	}
	int ans = 0;
	for (int i = 1; i < LG; ++i) if (cnt[i]) {
		int sm = 0;
		for (int j = i + 1; j < LG; ++j) sm += cnt[j];
		ans = add(ans, pwr[sm + cnt[i] - 1]);
	}
	printf("%d\n", sub(sub(pwr[n], 1), ans));
	return 0;
}