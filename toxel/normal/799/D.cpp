#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

ll a, b, h, w, n;
int mult[N];
std::map <int, int> Hash;

ll power(ll a, ll exp){
	ll ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret *= a;
		}
		a *= a;
	}
	return ret;
}

bool dfs(std::map <int, int>::iterator it){
	if (it == Hash.end()){
		return a <= h && b <= w || a <= w && b <= h;
	}
	for (int i = 0; i <= it -> second; ++ i){
		ll mult1 = power(it -> first, i), mult2 = power(it -> first, it -> second - i);
		w *= mult1, h *= mult2;
		if (dfs(++ it)){
			return true;
		}
		-- it;
		w /= mult1, h /= mult2;
	}
	return false;
}

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d", &a, &b, &h, &w, &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &mult[i]);
	}
	if (a <= h && b <= w || a <= w && b <= h){
		return printf("0\n"), 0;
	}
	std::sort(mult, mult + n);
	for (int i = n - 1; i >= 0; -- i){
		++ Hash[mult[i]];
		if (dfs(Hash.begin())){
			return printf("%d\n", n - i), 0;
		}
	}
	return printf("-1\n"), 0;
}