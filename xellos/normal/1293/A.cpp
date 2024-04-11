#include <cstdio>
#include <cstring>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, S, K;
		scanf("%d %d %d", &N, &S, &K);
		static char cl[2100];
		memset(cl, 0, sizeof(cl));
		for(int i = 0; i < K; i++) {
			int a;
			scanf("%d", &a);
			if(a > K+S || a < S-K) continue;
			cl[a-S+1000] = 1;
		}
		int l = 0, r = 0;
		while(cl[1000-l]) l++;
		while(cl[r+1000]) r++;
		if(S-l < 1) l = N;
		if(S+r > N) r = N;
		printf("%d\n", (r > l) ? l : r);
	}
}