#include <stdio.h>
#include <time.h>

#define MAX_N 200000
#define N_LIM 20
int n, t;

int min(int a, int b) {
	if(a>b)
		return b;
	else
		return a;
}
int main() {
	scanf("%d", &t);

	while(t--) {
		int N;
		char line[N_LIM];
		scanf("%s", line);
		for(int ii = 0; ii < N_LIM; ii++) {
			if(line[ii] == '\0')
			{
				N = ii;
				break;
			}
		}
		int ans = 99;

		for(int ii = 0; ii < N; ii++) {
			for(int jj = ii + 1; jj < N; jj++) {
				int num = 10 * (line[ii] - '0');
				num += (line[jj] - '0');
				if(num % 25 == 0) {
					// printf("num: %d\n", num);
					ans = min(ans, N - ii - 2);
				}
			}
		}

		printf("%d\n", ans);


	}
}