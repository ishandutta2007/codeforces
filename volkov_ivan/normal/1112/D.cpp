#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5e3 + 7, INF = 1e9 + 7;
int z[MAX_N];
int dp[MAX_N];

int calc_z(string s, int pos) {
	int n = (int) s.length();
	z[0] = n;
	int l = -1, r = -1;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int len = 0;
		if (r > i) {
			len = min(z[i - l], r - i);
		}
		while (i + len < n && s[len] == s[i + len]) len++;
		z[i] = len;
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
		if (i >= pos) ans = max(ans, z[i]);
	}
	return min(ans, pos);
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) dp[i] = INF;
	for (int i = 0; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + a);
		string t = "";
		for (int j = i; j < n; j++) t += s[j];
		int pos = t.length();
		for (int j = 0; j < i; j++) t += s[j];
		int maxi = calc_z(t, pos);
		for (int j = i + 1; j <= i + maxi; j++) {
			dp[j] = min(dp[j], dp[i] + b);	
		}
	}
	cout << dp[n] << endl;
	return 0;
}