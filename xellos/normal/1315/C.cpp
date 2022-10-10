#include <cstdio>
#include <cstring>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		int A[200], used[200];
		memset(used, 0, sizeof(used));
		for(int i = 0; i < N; i++) {
			scanf("%d", A+2*i+1);
			used[--A[2*i+1]] = 1;
		}
		bool ok = true;
		for(int i = 0; i < N; i++) {
			static int v[200];
			memset(v, 0, sizeof(v));
			for(int j = i+1; j < N; j++) v[A[2*j+1]] = 1;
			for(int j = A[2*i+1]+1; j <= 2*N; j++) {
				if(j == 2*N) {
					ok = false;
					break;
				}
				if(used[j]) continue;
				bool ok_cur = true;
				for(int k = 0, a = 0; k < 2*N; k++) if(k != j && !used[k]) {
					while(!v[a]) a++;
					if(a > k) {
						ok_cur = false;
						break;
					}
				}
				if(!ok_cur) continue;
				used[j] = 1;
				A[2*i] = j;
				break;
			}
			if(!ok) break;
		}
		if(!ok) {
			printf("-1\n");
			continue;
		}
		for(int i = 0; i < N; i++) if(A[2*i] > A[2*i+1]) {
			int tmp = A[2*i];
			A[2*i] = A[2*i+1];
			A[2*i+1] = tmp;
		}
		for(int i = 0; i < 2*N; i++) printf("%d%c", A[i]+1, (i == 2*N-1) ? '\n' : ' ');
	}
}