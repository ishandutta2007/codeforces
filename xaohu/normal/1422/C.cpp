#include <bits/stdc++.h>
#define pb push_back
#define sz(x)(int)x.size()
 
using ll = long long;
using namespace std;

const int MOD = 1e9 + 7;

string s;
int n;
ll d[200005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	d[0] = 1;
	for (int i = 1; i <= 100000; ++i)
		d[i] = (1 + 10 * d[i - 1]) % MOD;
	
	cin >> s;
	n = sz(s);
	
	ll ans = 0, sum = 0, pw = 1;
	
	for (int i = 0; i + 1 < n; ++i) {
		sum = (10 * sum + (s[i] - '0')) % MOD;
		ans = (ans + sum * d[n - i - 2]) % MOD;
	}
	sum = 0;
	for (int i = n - 1; 1 <= i; --i) {
		sum = (sum + (s[i] - '0') * pw) % MOD;
		pw = 10 * pw % MOD;
		ans = (ans + sum * i) % MOD;
	}
	cout << ans << endl;
	return 0;
}