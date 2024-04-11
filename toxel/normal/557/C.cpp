#include<bits/stdc++.h>
#define ll long long
#define pii std::pair <int, int>

const int N = 100010;
const int MAX = 1 << 17;

int n;
int seg[MAX << 1];
ll sum[MAX << 1];
pii p[N];

void add(int sit, int value){
	seg[sit + MAX] += value;
	sum[sit + MAX] += 1ll * value * sit;
	for (sit += MAX, sit >>= 1; sit; sit >>= 1){
		seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
		sum[sit] = sum[sit << 1] + sum[sit << 1 | 1];
	}
}

ll query(int cnt){
	ll ret = 0;
	int now = 0, sit = 1;
	for ( ; sit < MAX; ){
		sit <<= 1;
		now + seg[sit] < cnt ? now += seg[sit], ret += sum[sit], sit |= 1 : 0;
	}
	return ret + 1ll * (cnt - now) * (sit - MAX);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i].first);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i].second);
		add(p[i].second, 1);
	}
	std::sort(p, p + n, std::greater <pii>());
	ll total = 0, ans = LLONG_MAX;
	for (int i = 0, now, cnt; i < n; ){
		now = p[i].first;
		cnt = 0;
		ll aux = 0;
		for ( ; p[i].first == now; ++ i, ++ cnt){
			aux += p[i].second;
			add(p[i].second, -1);
		}
		ans = std::min(query(std::max(n - i - cnt + 1, 0)) + total, ans);
		total += aux;
	}
	return printf("%I64d\n", ans), 0;
}