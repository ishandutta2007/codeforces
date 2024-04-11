#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>
const int M = 1e9+7;
const int maxn = 5005;
using namespace std;
typedef long long ll;
int f[maxn][maxn], sum[maxn][maxn];
int g[maxn][maxn];
int tmp[maxn], nt[maxn];
char s[maxn];
int n;
inline int calc(char a, char b) {
	if (a == b) return 0;
	return a < b ? 1 : 2;
}
void prepare() {
	for (int len = 1; len <= n; ++len) {
		for (int i = 1; i <= n - len; ++i)
			tmp[i] = calc(s[i], s[i + len]);
		nt[n - len + 1] = 0;
		for (int i = n - len; i >= 1; --i) {
			if (tmp[i] == 0) nt[i] = nt[i + 1];
			else nt[i] = i;
		}
		
		for (int i = 1; i <= n - len; ++i) {
			g[len][i] = tmp[i];
			if (!tmp[i] && nt[i] && nt[i] - i + 1 <= len)
				g[len][i] = tmp[nt[i]]; 
		}
	}
}
bool check(int a, int b, int len) {
	return g[len][a] == 1;
}
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	prepare();
	
	for (int i = 1; i <= n; ++i) {
		f[i][1] = 1;
		for (int j = 2; j <= i; ++j) {
			f[i][j] = 0;
			if (s[j] != '0') {
				int k = j - 1 - (i - j) + 1;
				if (i - j > 0)
					f[i][j] = sum[j - 1][max(0, k)];
				if (k > 1 && s[k - 1] != '0' && check(k - 1, j, i - j + 1))
					f[i][j] = (f[i][j] + f[j - 1][k - 1]) % M;
			}
		}
		for (int j = i; j >= 0; --j)
			sum[i][j] = (sum[i][j + 1] + f[i][j]) % M;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + f[n][i]) % M;
	printf("%d\n", ans);
}