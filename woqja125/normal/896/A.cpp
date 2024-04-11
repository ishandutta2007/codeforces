#include<cstdio>
#include<cstring>
using namespace std;
long long l[100001];
long long big = 1000000000000000010;
char *a0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
char *a10 = "What are you doing while sending \"";
char *a11 = "\"? Are you busy? Will you send \"";
char *a12 = "\"?";
int main() {
	int q;
	l[0] = strlen(a0);
	int x0 = strlen(a10);
	int x1 = strlen(a11);
	int x2 = strlen(a12);
	int b = x0 + x1 + x2;
	for (int i = 1; i <= 100000; i++) {
		l[i] = b + 2 * l[i - 1];
		if (l[i] > big) l[i] = big;
	}
	scanf("%d", &q);
	for (int j = 1; j <= q; j++) {
		long long n, k;
		scanf("%lld%lld", &n, &k); k--;
		char ans = '.';
		int i;
		for (i = n; i > 0; i--) {
			if (k < x0) {
				ans = a10[k];
				break;
			}
			k -= x0;
			if (k < l[i - 1]) continue;
			k -= l[i - 1];
			if (k < x1) {
				ans = a11[k];
				break;
			}
			k -= x1;
			if (k < l[i - 1]) continue;
			k -= l[i - 1];
			if (k < x2) {
				ans = a12[k];
				break;
			}
			ans = '.';
			break;
		}

		if (i == 0 && k < l[0]) ans = a0[k];

		printf("%c", ans);
	}
	return 0;
}