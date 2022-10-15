#include<bits/stdc++.h>
using namespace std;
const int N(111111);
int mx[N * 4], sum[N * 4], a[N];
int inf(1e9);
void pushdown(int k) {
	sum[k * 2] += sum[k];
	mx[k * 2] += sum[k];
	sum[1 + k * 2] += sum[k];
	mx[1 + k * 2] += sum[k];
	sum[k] = 0;
}
void modify(int k, int le, int ri, int ql, int qr, int delta) {
	if(ql <= le && ri <= qr) {
		sum[k] += delta;
		mx[k] += delta;
	}else {
		pushdown(k);
		int mid(le + ri >> 1);
		if(ql <= mid)
			modify(k * 2, le, mid, ql, qr, delta);
		if(qr >= mid + 1)
			modify(k * 2 + 1, mid + 1, ri, ql, qr, delta);
		mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
	}
}
void activate(int k, int le, int ri, int x) {
	if(le == ri) {
		mx[k] = sum[k];
	}else {
		pushdown(k);
		int mid(le + ri >> 1);
		if(x <= mid)
			activate(k * 2, le, mid, x);
		else
			activate(k * 2 + 1, mid + 1, ri, x);
		mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
	}
}
int find(int k, int le, int ri) {
	if(mx[k] < 0)
		return -1;
	if(le == ri) {
		return a[le];
	}else {
		int mid(le + ri >> 1);
		pushdown(k);
		if(mx[k * 2 + 1] >= 0) {
			return find(k * 2 + 1, mid + 1, ri);
		}else {
			return find(k * 2, le, mid);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	fill(mx + 1, mx + 4 * n + 1, -inf);
	for(int i(1); i <= n; i++) {
		int t, tp;
		cin >> t >> tp;
		if(tp == 1) {
			int x;
			cin >> x;
			a[t] = x;
			if(t > 1) 
				modify(1, 1, n, 1, t - 1, +1);
			activate(1, 1, n, t);
		}else {
			if(t > 1)
				modify(1, 1, n, 1, t - 1, -1);
		}
		cout << find(1, 1, n) << endl;
	}

}