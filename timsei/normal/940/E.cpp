#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

int a[N] , n , m ,x , y , dp[N] , c, S[N];

multiset <int> SS;

main(void) {
	cin >> n >> c;
	for(int i = 1;i <= n;++ i) cin >> a[i] , S[i] = a[i] + S[i - 1];
	for(int i = 1;i <= n;++ i) {
		dp[i] = dp[i - 1] + a[i];
		SS.insert(a[i]);
		if(i >= c) {
			if(i != c) SS.erase(SS.find(a[i - c]));
			dp[i] = min(dp[i] , dp[i - c] + S[i] - S[i - c] - (*SS.begin()));
		}
	}
	cout << dp[n] << endl;
}