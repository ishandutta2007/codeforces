#include <cstdio>
#include <algorithm>

const int N = 1000005;
int n;
bool in[N];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		in[x] = 1;
	}
	int ans = 0;
	for (int i = N - 1; i > 0; --i) if (!in[i]) {
		int g = 0;
		for (int j = i * 2; j < N; j += i) if (in[j]) g = std::__gcd(g, j);
		if (g == i) {
			++ans;
			in[i] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}