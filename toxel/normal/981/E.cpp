#include<bits/stdc++.h>

const int N = 10010;

std::bitset <N> set[N];

const int MAX = 1 << 14;

std::bitset <N> seg[MAX << 1];
std::vector <int> lazy[MAX << 1];

void merge(std::bitset <N> &a, std::vector <int> &b){
	for (auto u : b){
		a |= a << u;
	}
}

void pull(int sit){
	if (sit < MAX)
	seg[sit] = seg[sit << 1] | seg[sit << 1 | 1];
	merge(seg[sit], lazy[sit]);
}

void add(int sit, int ql, int qr, int l, int r, int value){
	if (ql <= l && qr >= r){
		lazy[sit].push_back(value);
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid){
		add(sit << 1, ql, qr, l, mid, value);
	}
	if (qr > mid){
		add(sit << 1 | 1, ql, qr, mid + 1, r, value);
	}
}

void add(int ql, int qr, int value){
	add(1, ql, qr, 0, MAX - 1, value);
}

int main(){
	for (int i = 0; i < MAX << 1; ++ i){
		seg[i].set(0);
	}
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0, l, r, x; i < q; ++ i){
		scanf("%d%d%d", &l, &r, &x);
		add(l, r, x);
	}
	for (int i = (MAX << 1) - 1; i; -- i){
		pull(i);
	}
	std::vector <int> ans;
	for (int i = 1; i <= n; ++ i){
		if (seg[1].test(i)){
			ans.push_back(i);
		}
	}
	printf("%d\n", (int) ans.size());
	for (auto u : ans){
		printf("%d ", u);
	}
	putchar('\n');
	return 0;
}