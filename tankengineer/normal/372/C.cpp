#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 150000, M = 300;
int n, m, d;
long long a[M], b[M], t[M], dp[N];

int qhead, qtail, q[N + 1]; 
long long val[N + 1];

int main() {
	cin >> n >> m >> d;	
	long long last = 0;
	for (int i = 0; i < m; ++i) {
		int a;
		long long b, t;
		cin >> a >> b >> t;
		--a;
		long long len = (t - last) * d;
		last = t;
		qhead = 0, qtail = 0;	
		for (int j = 0; j < n; ++j) {
			while (qhead < qtail && val[qtail] <= dp[j]) {
				--qtail;
			}
			++qtail;
			q[qtail] = j;
			val[qtail] = dp[j];
			while (qhead < qtail && q[qhead + 1] + len < j) {
				++qhead;
			}
			dp[j] = val[qhead + 1];
		}
		qhead = 0, qtail = 0;
		for (int j = n - 1; j >= 0; --j) {
			while (qhead < qtail && val[qtail] <= dp[j]) {
				--qtail;
			}
			++qtail;
			q[qtail] = j;
			val[qtail] = dp[j];
			while (qhead < qtail && q[qhead + 1] - len > j) {
				++qhead;
			}
			dp[j] = val[qhead + 1];
		}
		for (int j = 0; j < n; ++j) {
			dp[j] += b - abs(a - j);
		}
	}
	long long ans = -(1ll << 62);
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}