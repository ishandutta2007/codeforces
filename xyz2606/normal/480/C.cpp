#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[5555][5555], s[5555];
int modulo(1e9 + 7);
int main() {
	int n, a, b, k;
	scanf("%d%d%d%d", &n, &a, &b, &k);
	if(a > b) {
		a = n - a + 1;
		b = n - b + 1;
	}
	dp[a][0] = 1;
	fill(s + a, s + b, 1);
	for(int j(1); j <= k; j++) {
		for(int i(1); i < b; i++) {
			dp[i][j] = (s[(i + b - 1) / 2] - dp[i][j - 1] + modulo) % modulo;
		}
		s[0] = 0;
		for(int i(1); i < b; i++) {
			s[i] = (s[i - 1] + dp[i][j]) % modulo;
		}
	}
	int ans(0);
	for(int i(1); i < b; i++) {
		ans = (ans + dp[i][k]) % modulo;
	}
	printf("%d\n", ans);
}