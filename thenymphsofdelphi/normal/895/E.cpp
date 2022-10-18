#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 17, lg = 32;
int n, q;

double it[N << 2];

struct lazy{
	double a, b;
	lazy() : a(1), b(0) {}
	lazy(double x, double y) : a(x), b(y) {}
}   lz[N << 2];

lazy& operator += (lazy &a, const lazy &b){
	a.a *= b.a;
	a.b *= b.a;
	a.b += b.b;
	return a;
}

void init(int l = 0, int r = n, int id = 1){
	if (l + 1 == r){
		cin >> it[id];
		return;
	}
	int mid = l + r >> 1;
	init(l, mid, id << 1);
	init(mid, r, id << 1 | 1);
	it[id] = it[id << 1] + it[id << 1 | 1];
}

void push(int id, int l, int r){
	int mid = l + r >> 1;
	lazy &x = lz[id];
	it[id << 1] = it[id << 1] * x.a + x.b * (mid - l);
	it[id << 1 | 1] = it[id << 1 | 1] * x.a + x.b * (r - mid);
	lz[id << 1] += lz[id];
	lz[id << 1 | 1] += lz[id];
	lz[id] = lazy();
}

void upd(int s, int e, lazy x, int l = 0, int r = n, int id = 1){
	if (s <= l && r <= e){
		it[id] = it[id] * x.a + x.b * (r - l);
		lz[id] += x;
		return;
	}
	if (e <= l || r <= s){
		return;
	}
	int mid = l + r >> 1;
	push(id, l, r);
	upd(s, e, x, l, mid, id << 1);
	upd(s, e, x, mid, r, id << 1 | 1);
	it[id] = it[id << 1] + it[id << 1 | 1];
}

double get(int s, int e, int l = 0, int r = n, int id = 1){
	if (s <= l && r <= e){
		return it[id];
	}
	if (e <= l || r <= s){
		return 0;
	}
	int mid = l + r >> 1;
	push(id, l, r);
	return get(s, e, l, mid, id << 1) + get(s, e, mid, r, id << 1 | 1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, l, r, x, y;
	cout << fixed << setprecision(5);
	cin >> n >> q;
	init();
	while (q--){
		cin >> t >> l >> r;
		l--;
		if (t == 1){
			cin >> x >> y;
			x--;
			long double a = get(l, r) / (r - l), b = get(x, y) / (y - x);
			upd(l, r, lazy({(long double) (r - l - 1) / (r - l), b / (r - l)}));
			upd(x, y, lazy({(long double) (y - x - 1) / (y - x), a / (y - x)}));
		}
		else{
			cout << get(l, r) << '\n';
		}
	}
}