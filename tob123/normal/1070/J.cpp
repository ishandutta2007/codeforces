#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 10;

long long n, m, k;
long long c[26];
char dp[MAXN];

/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void* operator new(size_t n) {
	char* res = mem + mpos;
	mpos += n;
	return (void*)res;
}
inline void operator delete(void*) {}
*/

int main() {
	ios_base::sync_with_stdio(false);
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> m >> k;
		for (int i = 0; i < 26; i++)
			c[i] = 0;
		string tmp;
		cin >> tmp;
		for (int i = 0; i < k; i++)
			c[tmp[i] - 'A']++;

		if (n > m) 
			swap(n, m);
		long long ans = n*m;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j <= n; j++)
				dp[j] = 0;
			dp[0] = 1;
			for (int j = 0; j < 26; j++) {
				if (i == j)
					continue;
				for (int k = n; k >= 0; k--)
					if (dp[k] && k + c[j] <= n)
						dp[k + c[j]] = 1;
			}
			/*
			cout << i << ' ' << c[i] << " : ";
			for (int i = 0; i <= n; i++)
				cout << dp[i] << ' ';
			cout << endl;
			*/
			for (long long j = 0; j < c[i]; j++) {
				if (j <= n && dp[n - j]) {
					// cout << j << ' ' << min(max(0ll, m - k + (n - j) + c[i]), c[i] - j) << endl;
					ans = min(ans, j * min(max(0ll, m - k + (n - j) + c[i]), c[i] - j));
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}