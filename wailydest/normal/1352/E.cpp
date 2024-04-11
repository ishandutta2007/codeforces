#include <cstdio>
#include <cstring>
using namespace std;

const int N = 8000;

int cnt[N];
bool usd[N];
int psum[N];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(cnt, 0, 4 * n);
		memset(usd, false, 4 * n);
		int val;
		scanf("%d", &val);
		psum[0] = val;
		cnt[val - 1] = 1;
		for (int i = 1; i < n; ++i) {
			scanf("%d", &val);
			++cnt[val - 1];
			psum[i] = val + psum[i - 1];
		}
		for (int i = 1; i < n; ++i) {
			if (psum[i] <= n) usd[psum[i] - 1] = true;
			for (int j = i - 2; j >= 0 && psum[i] - psum[j] <= n; --j) usd[psum[i] - psum[j] - 1] = true;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) ans += usd[i] * cnt[i];
		printf("%d\n", ans);
	}
	return 0;
}