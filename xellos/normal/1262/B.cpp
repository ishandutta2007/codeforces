#include <cstdio>
#include <cstring>

int main() {
	int T;
	scanf("%d\n", &T);
	while(T--) {
		int N;
		scanf("%d\n", &N);
		static char used[100010];
		static int P[100010];
		memset(used, 0, N);
		bool ok = true;
		for(int i = 0, last = -1, pos = 0; i < N; i++) {
			int q;
			scanf("%d", &q);
			q--;
			if(!ok) continue;
			if(q < last) ok = false;
			else if(q > last) {
				P[i] = q+1;
				used[q] = 1;
				last = q;
			}
			else {
				while(pos < last && used[pos]) pos++;
				if(pos == last) ok = false;
				else P[i] = pos+1;
				used[pos] = 1;
			}
		}
		if(!ok) printf("-1\n");
		else for(int i = 0; i < N; i++) printf("%d%c", P[i], (i == N-1) ? '\n' : ' ');
	}
}