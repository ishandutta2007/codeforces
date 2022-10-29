#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll l,r;
int K,len,a[70],num[70];
ll ans[66][66],f[66];
ll dfs(int i, bool e) {
	if (i == -1) return 1;
	if (!e && f[i] != -1) return f[i];
	ll res = 0;
	for (int j = 0, u = e ? num[i] : 1; j <= u; ++j)
		if (i > len - 1){
			if (j == 0) res += dfs(i - 1, e && j == u);
		}
		else if (!(i == len - 1 && j == 0)){
			a[i] = j;
			if (i > len - 1 - K) 
				res += dfs(i - 1, e && j == u);
			else if (j == a[i + K])
				res += dfs(i - 1, e && j == u);
		}
	return e ? res : f[i] = res;
}
ll calc(ll n) {
	int m = 0;
	while (n) {
		num[m++] = n % 2;
		n /= 2;
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= m; ++i) {
		len = i;
		for (int j = 1; j < i; ++j)
			if (i % j == 0) {
				K = j;
				memset(f, 255, sizeof(f));
				ans[i][j] = dfs(m - 1, true);
			}
	}
	ll sum = 0;
	for (int i = 1; i <= m; ++i) 
		for (int j = 1; j < i; ++j) 
			if (i % j == 0) {
				sum += ans[i][j];
				for (int k = j * 2; k < i; k += j)
					ans[i][k] -= ans[i][j];
			}
	return sum;
}
int main() {
	cin >> l >> r;
	cout << calc(r) - calc(l - 1) << endl;
}