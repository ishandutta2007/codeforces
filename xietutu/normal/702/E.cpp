#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100010, DEP = 33;
int n, m[maxn][DEP + 1], f[maxn][DEP + 1];
LL K, s[maxn][DEP + 1];
LL getsum(int x, LL K) {
	LL sum = 0;
	for (int j = DEP; j >= 0; --j)
		if (K - (1LL << j) >= 0) {
			sum += s[x][j];
			x = f[x][j];	
			K -= (1LL << j);
		}
	return sum;
}
int getm(int x, LL K) {
	int ret = 1e9;
	for (int j = DEP; j >= 0; --j)
		if (K - (1LL << j) >= 0) {
			ret = min(ret, m[x][j]);
			x = f[x][j];	
			K -= (1LL << j);
		}
	return ret;
}
int main() {
	scanf("%d%I64d", &n, &K);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &f[i][0]); 
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m[i][0]);
		s[i][0] = m[i][0];
	}
	for (int j = 1; j <= DEP; ++j)
		for (int i = 0; i < n; ++i) {
			int fa = f[i][j - 1];
			f[i][j] = f[fa][j - 1];
			m[i][j] = min(m[i][j - 1], m[fa][j - 1]);
			s[i][j] = s[i][j - 1] + s[fa][j - 1];
		}
	for (int i = 0; i < n; ++i) 
		printf("%I64d %d\n", getsum(i, K), getm(i, K));
}