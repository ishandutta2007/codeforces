#include<bits/stdc++.h>
using namespace std;
const int N(333333);
typedef long long LL;
int a[N], pw[N];
const int mod(1e9 + 7);
int main() {
	int n;
	scanf("%d", &n);
	for(int i(0); i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans(0);
	pw[0] = 1;
	for(int i(1); i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
	for(int i(0); i + 1 < n; i++) {
		//cout << a[i + 1] - a[i] << endl;
		ans += (LL)(a[i + 1] - a[i]) * (pw[i + 1] - 1) % mod * (pw[n - 1 - i] - 1) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}