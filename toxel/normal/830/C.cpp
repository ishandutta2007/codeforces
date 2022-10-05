#include<bits/stdc++.h>

const int N = 110;
typedef long long ll;

int a[N];
int n;
ll k;
std::set <ll> set;

int main(){
	scanf("%d%I64d", &n, &k);
	ll sum = k;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		sum += a[i] --;
		for (int j = 1, k; j <= a[i]; j = k + 1){
			k = a[i] / (a[i] / j);
			set.insert(k);
		}
	}
	set.insert((ll) 1e12);
	ll pre = 1, ans = 0;
	for (auto u : set){
		ll total = n;
		for (int i = 0; i < n; ++ i){
			total += a[i] / pre;
		}
		ll x = sum / total;
		if (x >= pre){
			ans = std::max(ans, std::min(x, u));
		}
		pre = u + 1;
	}
	return printf("%I64d\n", ans), 0;
}