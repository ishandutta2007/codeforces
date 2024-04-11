#include <cstdio>
int N, cnt[101], K, O;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		if (x == K)
			O++;
		else if (x < K)
			cnt[x] = 1;
	}
	for (int i = 0; i < K; i++)
		if (!cnt[i])
			O++;
	printf("%d\n", O);
}