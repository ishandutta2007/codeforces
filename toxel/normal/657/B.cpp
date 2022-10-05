#include<bits/stdc++.h>

const int N = 400010;
typedef long long ll;

int a[N], b[N];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; ++ i){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for (int i = 0; (i <= n || a[i]) && i < N - 1; ++ i){
		a[i + 1] += a[i] >> 1;
		a[i] &= 1;
	}
	if (a[N - 1] == -1){
		for (int i = 0; i < N; ++ i){
			a[i] = -b[i];
			b[i] = -b[i];
		}
		for (int i = 0; (i <= n || a[i]) && i < N - 1; ++ i){
			a[i + 1] += a[i] >> 1;
			a[i] &= 1;
		}
	}
	int begin, end;
	for (int i = 0; i < N; ++ i){
		if (a[i]){
			begin = i;
			break;
		}
	}
	for (int i = N - 1; i >= 0; -- i){
		if (a[i]){
			end = i;
			break;
		}
	}
	if (end - begin >= 32){
		puts("0");
		return 0;
	}
	ll x = 0;
	for (int i = end; i >= begin; -- i){
		x = x << 1 | a[i];
	}
	int cnt = 0;
	for (int i = begin; i >= 0 && x < 1e14; x <<= 1, -- i){
		if (i == n && x == b[n]) continue;
		if (i <= n && std::abs(b[i] - x) <= k){
			++ cnt;
		}
	}
	printf("%d\n", cnt);
	return 0;
}