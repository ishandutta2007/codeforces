#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	double ans = 0;
	for(int i = 1; i <= N; i++) ans += 1./i;
	printf("%.10f\n", ans);
}