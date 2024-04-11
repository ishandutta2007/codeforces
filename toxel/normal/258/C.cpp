#include<bits/stdc++.h>

const int N = 100010;
const int moder = 1e9 + 7;

int n;
int a[N];
std::vector <int> fact[N];

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int cnt[N];

int main(){
	for (int i = 1; i < N; ++ i){
		for (int j = i; j < N; j += i){
			fact[j].push_back(i);
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	int ans = 0;
	for (int i = 1; i < N; ++ i){
		int pre = 0, sz = fact[i].size();
		for (int j = 0; j < sz; ++ j){
			int sit = std::lower_bound(a, a + n, fact[i][j]) - a;
			cnt[j] = sit - pre;
			pre = sit;
		}
		cnt[sz] = n - pre;
		int prod1 = 1, prod2 = 1;
		for (int j = 1; j <= sz; ++ j){
			prod1 = 1ll * prod1 * powermod(j, cnt[j]) % moder;
			prod2 = 1ll * prod2 * powermod(j == sz ? sz - 1 : j, cnt[j]) % moder;
		}
		ans += prod1;
		ans -= ans >= moder ? moder : 0;
		ans -= prod2;
		ans += ans < 0 ? moder : 0;
	}
	printf("%d\n", ans);
	return 0;
}