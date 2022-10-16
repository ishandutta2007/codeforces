#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+7;
const int INF = 1e9;

int a[N], b[N], sgt[4*N], n, m;

void sgt_build(int v, int vl, int vr) {
	if(vl == vr) sgt[v] = INF;
	else {
		int vm = (vl+vr)/2;
		sgt_build(2*v+1, vl, vm);
		sgt_build(2*v+2, vm+1, vr);
		sgt[v] = INF;
	}
}

void sgt_upd(int v, int vl, int vr, int l, int r, int dx) {
	if(sgt[v] != INF && vl != vr) sgt[2*v+1] = sgt[2*v+2] = sgt[v], sgt[v] = INF;

	if(vl >= l && vr <= r) sgt[v] = dx;
	else if(vl <= r && vr >= l) {
		int vm = (vl+vr)/2;
		sgt_upd(2*v+1, vl, vm, l, r, dx);
		sgt_upd(2*v+2, vm+1, vr, l, r, dx);
	}
}

int sgt_ask(int v, int vl, int vr, int i) {
	if(vl == vr) return sgt[v];
	else {
		if(sgt[v] != INF) sgt[2*v+1] = sgt[2*v+2] = sgt[v], sgt[v] = INF;
		int vm = (vl+vr)/2;
		return i <= vm 
			? sgt_ask(2*v+1, vl, vm, i)
			: sgt_ask(2*v+2, vm+1, vr, i);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	for(sgt_build(0, 0, n-1); m--; ) {
		int t; cin >> t;
		if(t == 1) {
			int x, y, k; cin >> x >> y >> k; --x; --y;
			sgt_upd(0, 0, n-1, y, y+k-1, x-y);
		}
		if(t == 2) {
			int i; cin >> i; --i;
			int j = sgt_ask(0, 0, n-1, i);
			cout << (j == INF ? b[i] : a[i + j]) << endl;
		}
	}
}