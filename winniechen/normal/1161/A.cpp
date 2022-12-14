#include <cstdio>

const int MN = 100005;

int N, K;
int q1[MN], q2[MN];
int Ans;

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) q1[i] = q2[i] = -1;
	for (int i = 1, x; i <= K; ++i) {
		scanf("%d", &x);
		if (q1[x] == -1) q1[x] = i;
		q2[x] = i;
	}
	for (int i = 1; i <= N; ++i) if (q1[i] == -1) ++Ans;
	for (int i = 1; i < N; ++i) {
		if (q1[i] != -1 && q1[i + 1] != -1) {
			if (q2[i] < q1[i + 1]) ++Ans;
			if (q2[i + 1] < q1[i]) ++Ans;
		} else Ans += 2;
	}
	printf("%d\n", Ans);
	return 0;
}