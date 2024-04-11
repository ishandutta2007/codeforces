#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;
const int mod = 1e9 + 7;

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret;
}

lint fact[222222], invf[222222];
int n, m, k, s;
lint dp[26][2005];
pi a[2222];

lint bino(int x, int y){
	if(x < y) return 0;
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

lint poss(int x, int y){
	if(a[x].first > a[y].first || a[x].second > a[y].second) return 0;
	return bino(a[y].first - a[x].first + a[y].second - a[x].second, a[y].first - a[x].first);
}

int main(){
	cin >> n >> m >> k >> s;
	a[0] = pi(1, 1);
	for(int i=1; i<=k; i++){
		cin >> a[i].first >> a[i].second;
	}
	a[k+1] = pi(n, m);
	sort(a, a+k+2);
	fact[0] = invf[0] = 1;
	for(int i=1; i<=n+m; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod-2);
	}
	dp[0][k+1] = 1;
	for(int j=k; j>=0; j--){
	    for(int i=0; i<=20; i++){
		    if(i > 0) dp[i][j] = dp[i-1][k+1] * poss(j, k+1);   
	    }
		for(int l=j+1; l<=k; l++){
	        for(int i=0; i<=20; i++){
	            auto tmp = poss(j, l);
    			if(i > 0) dp[i][j] += dp[i-1][l] * tmp % mod;
    			dp[i][j] -= dp[i][l] * tmp % mod;
	        }
		}
	    for(int i=0; i<=20; i++){
    		dp[i][j] %= mod;
    		dp[i][j] += mod;
    		dp[i][j] %= mod;
	    }
	}
	lint ret = bino(n+m-2, n-1);
	for(int i=0; i<25; i++){
		ret += 1ll * (s - 1) * dp[i+1][0];
		s++;
		s /= 2;
		ret %= mod;
	}
	ret *= ipow(bino(n+m-2, n-1), mod-2);
	ret %= mod;
	cout << ret;
}