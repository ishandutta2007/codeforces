#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 100010;
int n, p, l, r, ans;
char s[maxn];
int main() {
	scanf("%d%d", &n, &p);
	scanf("%s", s + 1);
	if (p > n / 2) {
		reverse(s + 1, s + n + 1);
		p = n - p + 1;
	}
	
	int l = n + 1, r = 0;
	for (int i = 1; i <= n / 2; ++i) {
		int a = s[i] - 'a', b = s[n - i + 1] - 'a';
		if (a > b) ans += min(a - b, 26 - a + b);
		else ans += min(b - a, 26 - b + a);
		
		if (a != b) l = min(l, i), r = max(r, i);
	}
	if (l != n + 1 || r != 0) {
		if (l >= p && r >= p) 
			ans += r - p;
		else if (l <= p && r <= p) 
			ans += p - l;
		else ans += min(2 * (p - l) + (r - p), 2 * (r - p) + (p - l));
	}
	printf("%d\n", ans);
}