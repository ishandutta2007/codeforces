#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200000;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[N + 1];
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		int first = 0;
		while (first < n && s[first] == '0') ++first;
		if (first == n) {
			printf("%d\n", (n - 1) / (k + 1) + 1);
			continue;
		}
		int ans = (first && first - k > 0) ? max((first - k - 1), 0) / (k + 1) + 1 : 0;
		int pr = first + 1;
		int i = first + 1;
		while (i < n) {
			while (i < n && s[i] == '0') ++i;
			int r;
			if (i != n) r = i - pr - 2 * k;
			else r = i - pr - k;
			if (r > 0) ans += (r - 1) / (k + 1) + 1;
			pr = i = i + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}