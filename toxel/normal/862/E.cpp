#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int n, m, query;
int a[N], b[N];
ll pre[N];

void solve(std::set <ll> &set, ll sum){
	auto u = set.lower_bound(sum);
	ll ans = LLONG_MAX;
	if (u != set.end()){
		ans = std::min(ans, *u - sum);
	}
	if (u != set.begin()){
		ans = std::min(ans, sum - *(-- u));
	}
	printf("%I64d\n", ans);
}

int main(){
	scanf("%d%d%d", &n, &m, &query);
	ll sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += i & 1 ? -a[i] : a[i];
	}
	for (int i = 1; i <= m; ++ i){
		scanf("%d", &b[i]);
		if (i & 1){
			b[i] = -b[i];
		}
		pre[i] = pre[i - 1] + b[i];
	}
	std::set <ll> set;
	for (int i = 0; i <= m - n; ++ i){
		ll x = pre[i + n] - pre[i];
		set.insert(i & 1 ? x : -x);
	}
	solve(set, sum);
    while (query --){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		-- l, -- r;
		if ((l & 1) == (r & 1)){
			sum += l & 1 ? -x : x;
		}
		solve(set, sum);
    }
    return 0;
}