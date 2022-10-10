#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		char buf[110];
		scanf("%d %s", &N, buf);
		int ans = 0;
		for(int i = 0, n = -1000; i < N; i++) {
			if(buf[i] == 'A') n = 0;
			else n++;
			if(n > ans) ans = n;
		}
		printf("%d\n", ans);
	}
}