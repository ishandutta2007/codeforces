#include<bits/stdc++.h>
#define ll long long

const int N = 500010;

int n;
ll a[N], b[N], c[N];

int main(){
	scanf("%d", &n);
	ll s = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%I64d%I64d", &a[i], &b[i]);
		c[i] = a[i] ^ b[i];
		s ^= a[i];
	}
	for (int i = n - 1; ; -- i){
		for (int j = 0; j < i; ++ j){
			if (c[j] > c[j + 1]){
				std::swap(c[j], c[j + 1]);
			}
		}
		if (!c[i]){
			break;
		}
		for (int j = 0; j < i; ++ j){
			if ((c[j] ^ c[i]) < c[j]){
				c[j] ^= c[i];
			}
		}
	}
	int cnt = 0;
	for (int i = n - 1; ~i; -- i){
		if ((s ^ c[i]) < s){
			s ^= c[i];
		}
		if (c[i]){
			++ cnt;
		}
	}
	if (s){
		return printf("1/1\n"), 0;
	}
	ll ans = 1;
	for (int i = 0; i < cnt; ++ i, ans <<= 1);
	return printf("%I64d/%I64d\n", ans - 1, ans), 0;
}