#include<cstdio>
char in[1010];
int c[1010];
const int MOD = 1000000007;
int nCr[1010][1010];
int main() {
	int n, k;
	scanf("%s%d", in, &k);
	for (n = 0; in[n]; n++);
	c[1] = 1;
	if(k==1){
	    printf("%d\n", n-1);
	    return 0;
	}
	for (int i = 2; i <= 1000; i++) {
		int k = 0, x = i;
		while (x) {
			k++;
			x ^= (-x) & x;
		}
		c[i] = c[k] + 1;
	}
	nCr[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		nCr[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
		}
	}

	int ans = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (in[i] == '1') {
			for (int j = 0; j <= 1000; j++) {
				if (c[j] != k) continue;
				if (j - cnt < 0) continue;
				ans = (ans + nCr[n - i - 1][j - cnt]) % MOD;
			}
			cnt++;
		}
	}
	if (c[cnt] == k) ++ans%=MOD;
	printf("%d\n", ans);
	return 0;
}