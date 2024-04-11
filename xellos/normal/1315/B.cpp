#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int A, B, P;
		static char s[100100];
		scanf("%d %d %d %s", &A, &B, &P, s);
		int N = 0;
		while(s[N]) N++;
		N -= 2;
		while(N >= 0) {
			if(s[N] == 'A') P -= A;
			if(s[N] == 'B') P -= B;
			if(P < 0) break;
			while(N && s[N] == s[N-1]) N--;
			N--;
		}
		printf("%d\n", N+2);
	}
}