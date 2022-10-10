#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		static int A[200010];
		int N, pos_0 = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; i++) {
			scanf("%d", A+i);
			if(!(--A[i])) pos_0 = i;
		}
		static char ans[200010];
		ans[0] = '1';
		int l = pos_0, r = pos_0;
		for(int i = 0, m = 0; i < N-1; i++) {
			int v = (!l || (r != N-1 && A[r+1] < A[l-1])) ? A[++r] : A[--l];
			if(v > m) m = v;
			ans[i+1] = (m == r-l) ? '1' : '0';
		}
		ans[N] = 0;
		printf("%s\n", ans);
	}
}