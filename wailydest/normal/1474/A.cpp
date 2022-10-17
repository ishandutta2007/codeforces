#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n;
char s[N + 1], r[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		int pr = s[0] - '0' + 1;
		r[0] = '1';
		for (int i = 1; i < n; ++i) {
			if (!pr) {
				r[i] = '1';
				pr = s[i] - '0' + 1;
			}
			else if (pr == 1) {
				if (s[i] == '0') {
					pr = 0;
					r[i] = '0';
				}
				else {
					pr = 2;
					r[i] = '1';
				}
			}
			else {
				if (s[i] == '0') {
					r[i] = '1';
					pr = 1;
				}
				else {
					r[i] = '0';
					pr = 1;
				}
			}
		}
		r[n] = 0;
		printf("%s\n", r);
	}
	return 0;
}