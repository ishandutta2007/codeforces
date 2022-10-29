#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[1005];
int a[105], b[105];
int len, n, m, maxv, minv;
int main() {
	gets(s);
	len = strlen(s);
	for (int i = len - 1, k = 1; s[i] != ' '; --i, k *= 10)
		n += k * (s[i] - '0');
	
	maxv = n; minv = 1;
	a[1] = n; b[1] = 0; m = 1;
	for (int i = 0; i < len; ++i)
		if (s[i] == '+') { 
			maxv += n; minv += 1;
			a[++m] = n;
			b[m] = 0;
		}
		else if (s[i] == '-') {
			maxv -= 1; minv -= n;
			a[++m] = 1;
			b[m] = 1; 
		}
	if (n < minv || n > maxv) printf("Impossible\n");
	else {
		int m = 1, now = maxv;
		while (now > n) {
			if (b[m] == 0) {
				int t = min(now - n, n - 1);
				a[m] -= t;
				now -= t;	
			}
			else {
				int t = min(now - n, n - 1);
				a[m] += t;
				now -= t;
			}
			++m;
		}
		printf("Possible\n");
		for (int i = 0, j = 1; i < len; ++i)
			if (s[i] == '?') printf("%d", a[j++]);
			else printf("%c", s[i]);
	}	
}