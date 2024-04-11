#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 105;

int t, n, m, dp[N][2][2][2], A[N], B[N];

void rmain() {
	scanf("%lld%lld", &n, &m);
	
	// dp[i][a][b][c][d]
	// i : 
	// a : xor
	// b : limit
	// c:  
	memset(dp, 0, sizeof(dp));
	
	for(int i = 63; i >= 0; -- i) A[i] = ((m - 1) >> i) & 1, B[i] = (n >> i) & 1;
	dp[64][0][1][0] = 1;
	
	for(int i = 64; i >= 1; -- i) {
		for(int a = 0; a < 2; ++ a) {
			for(int b = 0; b < 2; ++ b) {
				for(int c = 0; c < 2; ++ c) {
					if(dp[i][a][b][c]) {
						
//						cerr << i <<' ' << a <<' ' << b <<" " << c <<" " << dp[i][a][b][c] << endl;
						
						int ele = dp[i][a][b][c];
						
						for(int cur = 0; cur <= ((b) ? A[i - 1] : 1); ++ cur) {
							for(int ano = 0; ano < 2; ++ ano) {
								int na = 0, nb = 0, nc = 0;
								nc = (cur ^ B[i - 1] ^ ano);
								if(nc + cur + B[i - 1] >= 2 && !c) continue;
								if(nc + cur + B[i - 1] <= 1 && c) continue;
								na = (a ^ (cur ^ ano));
//								cerr << i <<' ' << nb <<' ' << b <<' ' << cur <<' ' << A[i - 1] << endl;
								nb = (b && cur == A[i - 1]);
								dp[i - 1][na][nb][nc] += dp[i][a][b][c];
							}
						}
						
					}
				}
			}
		}
	}
	
	cout << dp[0][1][0][0] + dp[0][1][1][0] << endl;
}

main() {
	for(cin >> t; t --;) {
		rmain();
	}
}