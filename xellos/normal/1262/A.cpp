#include <cstdio>

int main() {
	int T;
	scanf("%d\n", &T);
	while(T--) {
		int N;
		scanf("%d\n", &N);
		int max_l = -2e9, min_r = 2e9;
		for(int i = 0; i < N; i++) {
			int l, r;
			scanf("%d %d\n", &l, &r);
			max_l = (l > max_l) ? l : max_l;
			min_r = (r < min_r) ? r : min_r;
		}
		if(max_l <= min_r) printf("0\n");
		else printf("%d\n", max_l - min_r);
	}
}