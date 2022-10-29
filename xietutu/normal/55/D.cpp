#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int M = 2520;
ll A,B,f[19][256][2520];
int y[19],num[19];
ll dfs(int i, int s, int mod, bool e) {
	if (i == -1) {
		bool bo = true;
		for (int j = 2; j <= 9; ++j)
			if ((s & (1 << (j - 2))) && (mod % j != 0)) {
				bo = false; break;
			}
		return bo;
	}
	if (!e && f[i][s][mod] != -1) return f[i][s][mod];
	ll res = 0;
	for (int j = 0, u = e ? num[i] : 9; j <= u; ++j)
		res += dfs(i - 1, s | (j <= 1 ? 0 : (1 << (j - 2))), (mod + j * y[i]) % M, e && num[i] == j);
	return e ? res : f[i][s][mod] = res;
}
ll calc(ll n) {
	int m = 0;
	while (n) {
		num[m++] = n % 10;
		n /= 10;
	}
	return dfs(m - 1, 0, 0, true);
}
int main() {
	memset(f, 255, sizeof(f));
	y[0] = 1;
	for (int i = 1; i < 19; ++i)
		y[i] = y[i - 1] * 10 % M;
	int T = 0; scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		cin >> A >> B;
		cout << calc(B) - calc(A - 1) << endl;
	}
}