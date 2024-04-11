#include <cstdio>

const int N = 100000;
const int A = 20;
char s[N + 1], t[N + 1];
int n;

int main() 
{
	int t_;
	scanf("%d", &t_);
	while (t_--) {
		scanf("%d%s%s", &n, s, t);
		bool f = true;
		int ans = 0;
		bool ok = true;
		for (int i = 0; i < A && ok; ++i) {
			int amt = 0;
			bool c[A] = {0};
			for (int j = 0; j < n; ++j) if (t[j] - 'a' == i) {
				if (s[j] > t[j]) ok = false;
				else if (s[j] != t[j]) {
					if (!c[s[j] - 'a']) ++amt;
					c[s[j] - 'a'] = true;
				}
			}
			for (int j = 0; j < n; ++j) if (c[s[j] - 'a']) s[j] = 'a' + i;
			ans += amt;
		}
		if (ok) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}