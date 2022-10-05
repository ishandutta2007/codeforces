#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x) & (-x))

const int N = 100010;

ll c1[N], c2[N], a[N], rev[N];
int n;

void add(ll *c, int sit, ll value){
	while (sit <= n){
		c[sit] += value;
		sit += lowbit(sit);
	}
}

ll query(ll *c, int sit){
	ll ret = 0;
	while (sit){
		ret += c[sit];
		sit -= lowbit(sit);
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		rev[a[i]] = i;
	}
	double ans = 0;
	ll cnt = 0;
	for (int i = n; i; -- i){
		add(c1, rev[i], rev[i]);
		add(c2, rev[i], 1);
		ans -= query(c1, rev[i] - 1) * (n - rev[i] + 1);
		cnt += query(c2, rev[i] - 1);
	}
	ans /= 1ll * n * (n + 1) / 2;
	ans += cnt;
	ans += (1.0 * n * (n + 1) * (n + 2) * (2 * n + 1) / 6 - 1.0 * n * n * (n + 1) * (n + 1) / 4 - 1.0 * (n + 1) * n * (n + 1) / 2) / 2 / (n + 1) / n;
	return printf("%.10lf", ans), 0;
}