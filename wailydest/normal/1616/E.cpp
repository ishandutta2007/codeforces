#include <cstdio>
#include <cstring>
#include <algorithm>

const int A = 26;
const int N = 100000;
int T, n, next[N], fi[A], b[N];
char s[N + 1], t[N + 1];

void add(int i, int d) 
{
	while (i < n) {
		b[i] += d;
		i |= i + 1;
	}
}

int get(int i) 
{
	int s = 0;
	while (i >= 0) {
		s += b[i];
		i = (i & i + 1) - 1;
	}
	return s;
}

int main() 
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s%s", &n, s, t);
		memset(fi, 0x3f, A << 2);
		for (int i = n - 1; i >= 0; --i) {
			next[i] = fi[s[i] - 'a'];
			fi[s[i] - 'a'] = i;
		}
		memset(b, 0, n << 2);
		long long ans = ~((long long)1 << 63), res = 0;
		for (int i = 0; i < n; ++i) add(i, 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < t[i] - 'a'; ++j) if (fi[j] < n) ans = std::min(ans, get(fi[j] - 1) + res);
			if (fi[t[i] - 'a'] >= n) break;
			add(fi[t[i] - 'a'], -1);
			res += get(fi[t[i] - 'a']);
			fi[t[i] - 'a'] = next[fi[t[i] - 'a']];
		}
		if (ans == ~((long long)1 << 63)) printf("-1\n");
		else printf("%lld\n", ans);
	}
	return 0;
}