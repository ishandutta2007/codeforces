#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 24;

int dp[1 << N] , n , m , x , y;

char s[N];

main(void) {
	scanf("%d" , &n);
	
	for(int i = 1;i <= n;++ i) {
		scanf("%s" , s + 1);
		int a = s[1] - 'a' , b = s[2] - 'a' , c = s[3] - 'a';
		a = 1 << a; b = 1 << b; c = 1 << c;
		++ dp[a]; ++ dp[b]; ++ dp[c];
		-- dp[a | b]; -- dp[b | c]; -- dp[a | c];
		++ dp[a | b | c];
	}
	
	for(int i = 1;i < (1 << 24);i <<= 1) {
		for(int j = 0;j < (1 << 24);++ j) {
			if(!(i & j)) {
				dp[i | j] += dp[j];
			}
		}
	}
	
	int ans = 0;
	for(int i = 0;i < (1 << 24);++ i) 
	ans ^= dp[i] * dp[i];
	
	cout << ans << endl;
}