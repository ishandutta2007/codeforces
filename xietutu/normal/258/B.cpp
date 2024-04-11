#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
const int M = 1000000007;
int n, m, K, sum, p[11], inv[11], c[11], f[11][11], num[11];
ll  ans, size[11];
int dfs(int i, int k, bool e) {
	if (i == -1) return k == K;
	if (!e && f[i][k] != -1) return f[i][k];
	int res = 0;
	for (int j = 0, u = e ? num[i] : 9; j <= u; ++j)
		res += dfs(i - 1, k + (j == 4 || j == 7), e && j == u);
	return e ? res : f[i][k] = res;
}
void DFS(int step, int pre) {
	if (sum >= 10) return;
	if (step == 7) {
		ll s = 1;
		for (int i = 0; i <= m; ++i) { 
			for (int j = size[i]; j >= size[i] - c[i] + 1; --j)
					s = s * j % M;
			s = s * inv[c[i]] % M;
		}
		for (int i = sum + 1; i <= m; ++i)
			ans = (ans + s * size[i] % M) % M;
		return;
	}
	for (int i = pre; i <= m; ++i)
		if (c[i] < size[i]) {
			++c[i];
			sum += i;
			DFS(step + 1, i);
			sum -= i;
			--c[i];
		}
}
ll Pow(ll a, int b) {
	ll s = 1;
	while (b) {
		if (b & 1) s = s * a % M;
		a = a * a % M;
		b = b / 2;
	}
	return s;
}
int main() {
	scanf("%d", &n);
	while (n) {
		num[m++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i <= m; ++i) {
		K = i;
		memset(f, 255, sizeof(f));
		size[i] = dfs(m - 1, 0, true);
	}
	--size[0];
	sum = 0;
	p[0] = inv[0] = 1;
	for (int i = 1; i <= 7; ++i) 
		p[i] = p[i - 1] * i, inv[i] = Pow(p[i], M - 2);
	DFS(1, 0);
	cout << ans * 720 % M << endl;
}