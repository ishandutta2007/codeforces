#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve(){
	int n; scanf("%d", &n);
	long long ans = 1;
	for(int i = 3;i <= n * 2;i++) ans = (ans * i) % MOD;
	printf("%lld\n", ans);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}