#include<bits/stdc++.h>
#define ll long long

const ll N = 100010;
const ll M = 10;
const ll MAX = 1 << 17;

ll seg[MAX << 1][M], lazy[MAX << 1][M];
ll n;
ll a[N];

void push(ll sit){
	static ll aux1[M], aux2[M];
	memset(aux1, 0, sizeof(aux1));
	memset(aux2, 0, sizeof(aux2));
	for (ll i = 0; i < M; ++ i){
		if (lazy[sit][i] != i){
			aux1[i] -= seg[sit << 1][i];
			aux1[lazy[sit][i]] += seg[sit << 1][i];
			aux2[i] -= seg[sit << 1 | 1][i];
			aux2[lazy[sit][i]] += seg[sit << 1 | 1][i];
		}
		if (lazy[sit][lazy[sit << 1][i]]){
			lazy[sit << 1][i] = lazy[sit][lazy[sit << 1][i]];
		}
		if (lazy[sit][lazy[sit << 1 | 1][i]]){
			lazy[sit << 1 | 1][i] = lazy[sit][lazy[sit << 1 | 1][i]];
		}
	}
	for (ll i = 0; i < M; ++ i){
		seg[sit << 1][i] += aux1[i];
		seg[sit << 1 | 1][i] += aux2[i];
	}
	for (ll i = 0; i < M; ++ i){
		lazy[sit][i] = i;
	}
}

void pull(ll sit){
	for (ll i = 0; i < M; ++ i){
		seg[sit][i] = seg[sit << 1][i] + seg[sit << 1 | 1][i];
	}
}

void build(){
	for (ll i = 0; i < n; ++ i){
		for (ll x = a[i], coe = 1; x; x /= 10, coe *= 10){
			seg[i + MAX][x % 10] += coe;
		}
	}
	for (ll i = MAX + n - 1; i; -- i){
		for (ll j = 0; j < M; ++ j){
			lazy[i][j] = j;
		}
		if (i < MAX){
			pull(i);
		}
	}
}

void add(ll sit, ll l, ll r, ll left, ll right, ll x, ll y){
	if (left <= l && right >= r){
		seg[sit][y] += seg[sit][x];
		seg[sit][x] = 0;
		for (ll i = 0; i < M; ++ i){
			if (lazy[sit][i] == x){
				lazy[sit][i] = y;
			}
		}
		return;
	}
	push(sit);
	ll mid = l + r >> 1;
	if (left <= mid){
		add(sit << 1, l, mid, left, right, x, y);
	}
	if (right > mid){
		add(sit << 1 | 1, mid + 1, r, left, right, x, y);
	}
	pull(sit);
}

ll query(ll sit, ll l, ll r, ll left, ll right){
	ll ret = 0;
	if (left <= l && right >= r){
		for (ll i = 0; i < M; ++ i){
			ret += i * seg[sit][i];
		}
		return ret;
	}
	push(sit);
	ll mid = l + r >> 1;
	if (left <= mid){
		ret += query(sit << 1, l, mid, left, right);
	}
	if (right > mid){
		ret += query(sit << 1 | 1, mid + 1, r, left, right);
	}
	pull(sit);
	return ret;
}

int main(){
	ll test;
	scanf("%I64d%I64d", &n, &test);
	for (ll i = 0; i < n; ++ i){
		scanf("%I64d", &a[i]);
	}
	build();
	while (test --){
		ll op, l, r, x, y;
		scanf("%I64d%I64d%I64d", &op, &l, &r);
		-- l, -- r;
		if (op == 1){
			scanf("%I64d%I64d", &x, &y);
			if (x == y){
				continue;
			}
			add(1, 0, MAX - 1, l, r, x, y);
		}
		else{
			printf("%I64d\n", query(1, 0, MAX - 1, l, r));
		}
	}
	return 0;	
}