#include<bits/stdc++.h>
#define ll long long
#define pii std::pair <int, int>

const int N = 500010;
const int MAX = 1 << 19;

std::pair <pii, int> pp[N];
int n, p, q, r;
ll seg[MAX << 1];
int lazy[MAX << 1], min[MAX << 1];

void push(int sit, int l, int r){
	if (lazy[sit]){
		seg[sit << 1] = seg[sit << 1 | 1] = 1ll * lazy[sit] * (r - l + 1) >> 1;
		min[sit << 1] = min[sit << 1 | 1] = lazy[sit];
		lazy[sit << 1] = lazy[sit << 1 | 1] = lazy[sit];
		lazy[sit] = 0;
	}
}

void pull(int sit){
	seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
	min[sit] = std::min(min[sit << 1], min[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
	if (l >= ql && r <= qr){
		seg[sit] = 1ll * value * (r - l + 1);
		min[sit] = lazy[sit] = value;
		return;
	}
	push(sit, l, r);
	int mid = l +  r >> 1;
	if (ql <= mid){
		add(sit << 1, l, mid, ql, qr, value);
	}
	if (qr > mid){
		add(sit << 1 | 1, mid + 1, r, ql, qr, value);
	}
	pull(sit);
}

ll querysum(int sit, int l, int r, int ql, int qr){
	if (l >= ql && r <= qr){
		return seg[sit];
	}
	push(sit, l, r);
	int mid = l + r >> 1;
	ll ret = 0;
	if (ql <= mid){
		ret += querysum(sit << 1, l, mid, ql, qr);
	}
	if (qr > mid){
		ret += querysum(sit << 1 | 1, mid + 1, r, ql, qr);
	}
	return ret;
}

int query(int sit, int l, int r, int value){
	if (l == r){
		return sit - MAX;
	}
	push(sit, l, r);
	int mid = l + r >> 1, ret;
	if (min[sit << 1] >= value){
		return query(sit << 1 | 1, mid + 1, r, value);
	}
	return query(sit << 1, l, mid, value);
}

int suf1[N], suf2[N];

int main(){
	scanf("%d%d%d%d", &n, &p, &q, &r);
	for (int i = 0, a, b, c; i < n; ++ i){
		scanf("%d%d%d", &a, &b, &c);
		pp[i] = {{a, b}, c};
	}
	std::sort(pp, pp + n);
	for (int i = n - 1; ~i; -- i){
		suf1[i] = std::max(suf1[i + 1], pp[i].first.second);
		suf2[i] = std::max(suf2[i + 1], pp[i].second);
	}
	ll ans = 0;
	for (int i = 1, j = 0; i <= p; ++ i){
		ans += 1ll * (q - suf1[j]) * r;
		int left = std::max(suf1[j] + 1, query(1, 0, MAX - 1, suf2[j] + 1));
		ans -= querysum(1, 0, MAX - 1, suf1[j] + 1, left - 1);
		ans -= 1ll * (q - left + 1) * suf2[j];
		for ( ; pp[j].first.first == i; ++ j){
			int x = querysum(1, 0, MAX - 1, pp[j].first.second, pp[j].first.second);
			if (x >= pp[j].second){
				continue;
			}
			int sit = query(1, 0, MAX - 1, pp[j].second);
			add(1, 0, MAX - 1, sit, pp[j].first.second, pp[j].second);
		}
	}
	return printf("%I64d\n", ans), 0;
}