#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef pair<int, int> pii;
int n, k, sum;
pii p[maxn];
char s[maxn];
int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		p[i].first = max('z' - s[i], s[i] - 'a');
		sum += p[i].first;
		p[i].second = i;
	}
	if (sum < k) printf("-1\n");
	else {
		sort(p + 1, p + n + 1);
		reverse(p + 1, p + n + 1);
		for (int i = 1; i <= n && k; ++i) {
			int t = min(k, p[i].first), index = p[i].second;
			if (s[index] + t <= 'z') s[index] += t;
			else s[index] -= t;
			k -= t;
		}
		printf("%s\n", s + 1);
	}
}