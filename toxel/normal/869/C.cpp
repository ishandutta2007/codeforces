#include<bits/stdc++.h>

const int N = 5010;
const int moder = 998244353;

int comb[N][N], fac[N];

int solve(int a, int b){
	int ret = 0;
	for (int i = 0, sz = std::min(a, b); i <= sz; ++ i){
		ret = (ret + 1ll * comb[a][i] * comb[b][i] % moder * fac[i]) % moder;
	}
	return ret;
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	for (int i = 0; i < N; ++ i){
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++ j){
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
		}
	}
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	return printf("%I64d\n", 1ll * solve(a, b) * solve(b, c) % moder * solve(a, c) % moder), 0;
}