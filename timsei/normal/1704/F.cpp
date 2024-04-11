#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m, x, y, dp[2][N], tmp[100];

char s[N]; 

void rmain() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	int tot = 0;
	for(int i = 1; i <= n; ++ i) if(s[i] == 'R') ++ tot; else -- tot;
	int res = 0;
	if(tot > 0) puts("Alice");
	else if(tot < 0) puts("Bob");
	else {
		int len = 1;
		for(int i = 2; i <= n; ++ i) {
			if(s[i] != s[i - 1]) {
				++ len;
			} else {
				if(len == 1) continue;
				else {
					if(len & 1) {
						res = res ^ (dp[1][(len / 2)]);
					} else res = res ^ (dp[0][len / 2]);
				}
				len = 1;
			}
		}
		if(len & 1) {
			res = res ^ (dp[1][(len / 2)]);
		} else res = res ^ (dp[0][len / 2]);
		if(res) puts("Alice");
		else puts("Bob");
	}
}

int main() {
	n = 5000;
	dp[0][0] = dp[0][1] = 0;
	int mx = 0;
	for(int i = 1; i <= n; ++ i) {
		memset(tmp, 0, sizeof(tmp));
		for(int j = 0; j < i; ++ j) {
			++ tmp[dp[0][j] ^ dp[0][i - j - 1]];
		}
		for(int j = 0; j < i - 1; ++ j) {
			++ tmp[dp[1][j] ^ dp[1][i - j - 2]];
		}
		for(int j = 0; j < 100; ++ j) {
			if(!tmp[j]) {
				dp[0][i] = j; break;
			}
		}
		
		memset(tmp, 0, sizeof(tmp));
		
		for(int j = 0; j < i; ++ j) {
			++ tmp[dp[0][j] ^ dp[1][i - j - 1]];
		}
			
		for(int j = 0; j < 100; ++ j) {
			if(!tmp[j]) {
				dp[1][i] = j; break;
			}
		}
		mx = max(mx, dp[0][i]);
		mx = max(mx, dp[1][i]);
	}
	
	for(int i = 5001; i < N; ++ i)
	dp[0][i] = dp[0][i - 17], 
	dp[1][i] = dp[1][i - 17];
	
	int t;
	for(cin >> t; t --;) 
	rmain(); 
//	cerr << mx << endl;
}