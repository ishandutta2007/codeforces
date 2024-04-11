#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

char s[N+1];
int n, m, l, r;
struct Result {
	int a, b, c;
} sgt_data[4*N];

Result neutral() {
	return { 0, 0, 0 };
}

Result merge(const Result& l, const Result& r) {
	Result res; int t = min(l.b, r.c);
	res.a = l.a + r.a + t * 2;
	res.b = l.b + r.b - t;
	res.c = l.c + r.c - t;
	return res;
}

void sgt_bld(int v, int vl, int vr) {
	if(vl == vr) {
		sgt_data[v].a = 0;
		sgt_data[v].b = s[vr] == '(';
		sgt_data[v].c = s[vr] == ')';
	}
	else {
		int vm = (vl+vr)/2;
		sgt_bld(2*v+1, vl,   vm);
		sgt_bld(2*v+2, vm+1, vr);
		sgt_data[v] = merge(sgt_data[2*v+1], sgt_data[2*v+2]);
	}
}

Result sgt_query(int v, int vl, int vr, int l, int r) {
	if(vl >  r || vr <  l) return neutral();
	if(vl >= l && vr <= r) return sgt_data[v];
	else {
		int vm = (vl+vr)/2;
		return merge(
			sgt_query(2*v+1, vl,   vm, l, r),
			sgt_query(2*v+2, vm+1, vr, l, r)
		);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(cin >> s; s[n]; ) ++n;
	sgt_bld(0, 0, n-1);
	for(cin >> m; m--;) {
		int l, r; cin >> l >> r;
		cout << sgt_query(0, 0, n-1, l-1, r-1).a << endl;
	}
}