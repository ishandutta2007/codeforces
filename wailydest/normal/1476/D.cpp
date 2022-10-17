#include <cstdio>

const int N = 300000;
int t, n, pp[N + 1][2], ss[N + 1][2];
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		pp[0][0] = pp[0][1] = 1;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == 'L') {
				pp[i][0] = pp[i - 1][1] + 1;
				pp[i][1] = 1;
			}
			else {
				pp[i][0] = 1;
				pp[i][1] = pp[i - 1][0] + 1;
			}
		}
		ss[n][0] = ss[n][1] = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == 'R') {
				ss[i][0] = ss[i + 1][1] + 1;
				ss[i][1] = 1;
			}
			else {
				ss[i][0] = 1;
				ss[i][1] = ss[i + 1][0] + 1;
			}
		}
		for (int i = 0; i <= n; ++i) printf("%d ", pp[i][0] + ss[i][0] - 1);
		printf("\n");
	}
	return 0;
}