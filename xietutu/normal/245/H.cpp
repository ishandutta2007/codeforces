#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5005;
char s[maxn], t[maxn * 2 + 3];
int n, q, sum[maxn][maxn], rad[maxn * 2 + 3];
void manacher(char* s) {
	int len = 0;
	t[len++] = '^'; t[len++] = '#';
	for (int i = 0; i < n; ++i) {
		t[len++] = s[i];
		t[len++] = '#';
	}
	t[len] = 0;
	int i = 1, j = 1, k;
	while (i < len) {
		while (t[i - j] == t[i + j]) ++j;
		rad[i] = j;
		for (k = 1; k < j && rad[i - k] != rad[i] - k; ++k) {
			rad[i + k] = min(rad[i - k], rad[i] - k);
		}
		i += k; j = max(j - k, 1);
	}
}
void prepare() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1, l = i, r = i; j * 2 <= rad[i * 2]; ++j, --l, ++r)
			++sum[l][r];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1, l = i, r = i + 1; j * 2 <= rad[i * 2 + 1]; ++j, --l, ++r)
			++sum[l][r];
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
}
void read(int& x) {
	x = 0;
	char ch = getchar();
	while (!(ch >= '0' && ch <= '9')) ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
}
int main() {
	gets(s);
	n = strlen(s);
	manacher(s);
	prepare();
	read(q);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		read(l); read(r);
		printf("%d\n", sum[r][r] - sum[l - 1][r] - sum[r][l - 1] + sum[l - 1][l - 1]);
	}
}