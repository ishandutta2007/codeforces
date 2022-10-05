#include<bits/stdc++.h>
#define ll long long

const int N = 50;

int a[N], b[N];
ll pw[N];

int main(){
	ll l, r, k;
	scanf("%I64d%I64d%I64d", &l, &r, &k);
	if (r - l + 1 < 5){
		ll min = LLONG_MAX;
		std::set <ll> set;
		for (int i = 1, sz = r - l + 1; i < 1 << sz; ++ i){
			ll cnt = 0, ans = 0;
			for (int j = 0; j < sz; ++ j){
				if (i >> j & 1){
					++ cnt;
					ans ^= l + j;
				}
			}
			if (cnt <= k && min > ans){
				set.clear();
				for (int j = 0; j < sz; ++ j){
					if (i >> j & 1){
						set.insert(l + j);
					}
				}
				min = ans;
			}
		}
		printf("%I64d\n%d\n", min, set.size());
		for (auto u : set){
			printf("%I64d ", u);
		}
		return printf("\n"), 0;
	}
	if (k == 1){
		return printf("%I64d\n1\n%I64d\n", l, l), 0;
	}
	if (k == 2){
		printf("1\n2\n");
		if (l & 1){
			return printf("%I64d %I64d\n", l + 1, l + 2), 0;
		}
		return printf("%I64d %I64d\n", l, l + 1), 0;
	}
	if (k >= 4){
		printf("0\n4\n");
		if (l & 1){
			return printf("%I64d %I64d %I64d %I64d\n", l + 1, l + 2, l + 3, l + 4), 0;
		}
		return printf("%I64d %I64d %I64d %I64d\n", l, l + 1, l + 2, l + 3), 0;
	}
	int len1 = 0, len2 = 0;
	ll x1 = l, x2 = r;
	while (x1){
		a[len1 ++] = x1 & 1;
		x1 >>= 1;
	}
	while (x2){
		b[len2 ++] = x2 & 1;
		x2 >>= 1;
	}
	if (len1 == len2){
		printf("1\n2\n");
		if (l & 1){
			return printf("%I64d %I64d\n", l + 1, l + 2), 0;
		}
		return printf("%I64d %I64d\n", l, l + 1), 0;
	}
	pw[0] = 1;
	for (int i = 1; i < N; ++ i){
		pw[i] = pw[i - 1] << 1;
	}
	if (len1 < len2 - 1){
		printf("0\n3\n");
		return printf("%I64d %I64d %I64d\n", pw[len1] - 1, pw[len1], pw[len1 + 1] - 1), 0;
	}
	if (b[len2 - 2]){
		printf("0\n3\n");
		return printf("%I64d %I64d %I64d\n", pw[len1] - 1, pw[len1] + pw[len1 - 1] - 1, pw[len1] + pw[len1 - 1]), 0;
	}
	printf("1\n2\n");
	if (l & 1){
		return printf("%I64d %I64d\n", l + 1, l + 2), 0;
	}
	return printf("%I64d %I64d\n", l, l + 1), 0;
}