#include <cstdio>
#include <cstring>

const int N = 105;
const int A = 26;
int t, n, m, k, amt[2][A], l[2];
char a[N], b[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(amt, 0, sizeof amt);
		scanf("%d%d%d", &n, &m, &k);
		scanf("%s%s", a, b);
		l[0] = strlen(a);
		l[1] = strlen(b);
		for (int i = 0; a[i]; ++i) ++amt[0][a[i] - 'a'];
		for (int i = 0; b[i]; ++i) ++amt[1][b[i] - 'a'];
		int last = -1, cnt = 0;
		while (l[0] && l[1]) {
			int i;
			for (i = 0; i < A && !amt[0][i] && !amt[1][i]; ++i);
			int t = amt[0][i] ? 0 : 1;
			while (last == t && cnt == k) {
				for (++i; !amt[0][i] && !amt[1][i]; ++i);
				t = amt[0][i] ? 0 : 1;
			}
			--amt[t][i];
			printf("%c", 'a' + i);
			if (last == t) ++cnt;
			else {
				last = t;
				cnt = 1;
			}
			--l[t];
		}
		printf("\n");
	}
	return 0;
}