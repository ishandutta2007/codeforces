#include<bits/stdc++.h>

const int N = 100010;
const int moder = 1e9 + 7;
const int MAX = 1 << 19;

int l0[N], r0[N], l1[N], r1[N], c[N << 2], max0[N << 2], max1[N << 2];
int seg[2][MAX << 1], lazy[2][MAX << 1];

void push(int type, int sit, int l, int r){
	if (lazy[type][sit] != -1){
		lazy[type][sit << 1] = lazy[type][sit << 1 | 1] = lazy[type][sit];
		seg[type][sit << 1] = seg[type][sit << 1 | 1] = 1ll * lazy[type][sit] * (r - l + 1 >> 1) % moder;
		lazy[type][sit] = -1;
	}
}

void pull(int type, int sit){
	seg[type][sit] = seg[type][sit << 1] + seg[type][sit << 1 | 1];
	seg[type][sit] -= seg[type][sit] >= moder ? moder : 0;
}

void add(int type, int sit, int l, int r, int ql, int qr, int value){
	if (ql > qr) return;
	if (ql <= l && qr >= r){
		seg[type][sit] = 1ll * (r - l + 1) * value % moder;
		lazy[type][sit] = value;
		return;
	}
	push(type, sit, l, r);
	int mid = l + r >> 1;
	if (ql <= mid){
		add(type, sit << 1, l, mid, ql, qr, value);
	}
	if (qr > mid){
		add(type, sit << 1 | 1, mid + 1, r, ql, qr, value);
	}
	pull(type, sit);
}

int query(int type, int sit, int l, int r, int ql, int qr){
	if (ql > qr) return 0;
	if (ql <= l && qr >= r){
		return seg[type][sit];
	}
	push(type, sit, l, r);
	int mid = l + r >> 1;
	int ret = 0;
	if (ql <= mid){
		ret = query(type, sit << 1, l, mid, ql, qr);
	}
	if (qr > mid){
		ret += query(type, sit << 1 | 1, mid + 1, r, ql, qr);
		ret -= ret >= moder ? moder : 0;
	}
	return ret;
}

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1) ret = 1ll * ret * a % moder;
		a = 1ll * a * a % moder;
	}
	return ret;
}

int main(){
	int k, n, m;
	scanf("%d%d%d", &k, &n, &m);
	int cnt = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &l0[i], &r0[i]);
		-- l0[i];
		c[cnt ++] = l0[i];
		c[cnt ++] = r0[i];
	}
	for (int i = 0; i < m; ++ i){
		scanf("%d%d", &l1[i], &r1[i]);
		-- l1[i];
		c[cnt ++] = l1[i];
		c[cnt ++] = r1[i];
	}
	c[cnt ++] = 0;
	c[cnt ++] = k;
	std::sort(c, c + cnt);
	cnt = std::unique(c, c + cnt) - c;
	memset(max0, -1, sizeof(max0));
	memset(max1, -1, sizeof(max1));
	for (int i = 0; i < n; ++ i){
		l0[i] = std::lower_bound(c, c + cnt, l0[i]) - c;
		r0[i] = std::lower_bound(c, c + cnt, r0[i]) - c;
		max0[r0[i]] = std::max(max0[r0[i]], l0[i]);
	}
	for (int i = 0; i < m; ++ i){
		l1[i] = std::lower_bound(c, c + cnt, l1[i]) - c;
		r1[i] = std::lower_bound(c, c + cnt, r1[i]) - c;
		max1[r1[i]] = std::max(max1[r1[i]], l1[i]);
	}
	int same = 1;
	memset(lazy, -1, sizeof(-1));
	for (int i = 1; i < cnt; ++ i){
		int value0, value1;
		if (max0[i] == i - 1){
			value0 = 0;
		}
		else{
			value0 = query(1, 1, 0, MAX - 1, 0, MAX - 1) + same;
			value0 -= value0 >= moder ? moder : 0;
		}
		if (max1[i] == i - 1){
			value1 = 0;
		}
		else{
			value1 = query(0, 1, 0, MAX - 1, 0, MAX - 1) + same;
			value1 -= value1 >= moder ? moder : 0;
		}
		int valuesame = query(0, 1, 0, MAX - 1, 0, MAX - 1) + query(1, 1, 0, MAX - 1, 0, MAX - 1);
		valuesame -= valuesame >= moder ? moder : 0;
		valuesame += same;
		valuesame -= valuesame >= moder ? moder : 0;
		add(0, 1, 0, MAX - 1, 0, max0[i], 0);
		add(0, 1, 0, MAX - 1, i - 1, i - 1, value0);
		add(1, 1, 0, MAX - 1, 0, max1[i], 0);
		add(1, 1, 0, MAX - 1, i - 1, i - 1, value1);
		int coe = powermod(2, c[i] - c[i - 1]) - 2;
		coe += coe < 0 ? moder : 0;
		same = 1ll * valuesame * coe % moder;
	}
	int ans = query(0, 1, 0, MAX - 1, 0, MAX - 1) + query(1, 1, 0, MAX - 1, 0, MAX - 1);
	ans -= ans >= moder ? moder : 0;
	ans += same;
	ans -= ans >= moder ? moder : 0;
	printf("%d\n", ans);
	return 0;
}