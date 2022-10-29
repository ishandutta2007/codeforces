#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 1000005;
char s[maxn], a[maxn], b[maxn];
int len, l, r, dot;
void solve() {
	if (dot == -1 && l == len) {
		printf("0\n");
		return;
	}
	if (dot != -1 && r == dot) {
		if (s[l] == '.') {
			printf("0\n");
			return;
		}
	}
	if (dot == -1 || r == dot) {
		if (r == dot) len = r;
		int m = 0;
		printf("%c", s[l]);
		for (int i = l + 1; i < len; ++i)
			a[m++] = s[i];
		while (m > 0 && a[m - 1] == '0') --m;
		/*while (l < len) {
			if (s[l] != '0') flag = false;
			a[m++] = s[l++];
		}*/
		a[m] = 0;
		if (m) printf(".%s", a);
		if (len - l - 1) printf("E%d", len - l - 1);
	}
	else {
		if (l == dot) {
			int st = dot + 1;
			while (s[st] == '0') ++st;
			printf("%c", s[st]);
			if (st < r) {
				printf(".");
				for (int i = st + 1; i <= r; ++i)
					printf("%c", s[i]);
			}
			printf("E-%d", st - dot);
		}
		else {
			printf("%c.", s[l]);
			for (int i = l + 1; i <= r; ++i)
				if (s[i] != '.') printf("%c", s[i]);
			if (dot - l != 1) printf("E%d", dot - l - 1); 
		}
	}
}
int main() {
	scanf("%s", s);
	len = strlen(s);
	while (l < len && s[l] == '0') ++l;
	dot = -1;
	for (int i = 0; i < len; ++i)
		if (s[i] == '.') dot = i;
	r = len - 1;
	while (r > dot && s[r] == '0') --r;
	solve();
}