#include <cstdio>
#include <algorithm>

using namespace std;

int n, L, len;
char S[500000];
int w[500000], to[500000], st[500000];

bool cmp(int x, int y) {
	return w[x] < w[y];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
		to[i] = i;
	sort(to + 1, to + n + 1, cmp);
	L = 1;
	len = 0;
	scanf("%s", S + 1);
	for (int i = 1; i <= 2 * n; i++) {
		int ans;
		if (S[i] == '0') {
			ans = to[L++];
			st[++len] = ans;
		}else {
			ans = st[len--];
		}
		printf("%d ", ans);
	}
}