#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int N = (1 << 21) + 2020;
const int M = 1e6;

int n, q, a[N], tag[N], cnt[N];
pair<int, int> t[N];

void build(int u = 1, int l = 1, int r = M) {
	if (l == r) {
		t[u] = {0, 1};
		return;
	}
	int m = (l + r) / 2;
	build(2 * u, l, m);
	build(2 * u + 1, m + 1, r);
}

void push(int u) {
	for (auto x : {2 * u, 2 * u + 1}) {
		t[x].first += tag[u];
		tag[x] += tag[u];
	}
	tag[u] = 0;
}

void calc(int u) {
	t[u].first = min(t[2 * u].first, t[2 * u + 1].first);
	t[u].second = 0;
	for (auto x : {2 * u, 2 * u + 1})
		if (t[u].first == t[x].first)
			t[u].second += t[x].second;
}

void add(int a, int b, int c, int u = 1, int l = 1, int r = M) {
	if (r < a || b < l) 
		return;
	if (a <= l && r <= b) {
		t[u].first += c;
		tag[u] += c;
		return;
	}
	push(u);
	int m = (l + r) / 2;
	add(a, b, c, 2 * u, l, m);
	add(a, b, c, 2 * u + 1, m + 1, r);
	calc(u);
}

void upd(int p, int x) {
	int b = a[p];
	int c = a[p + 1];
	if (b > c) swap(b, c);
	add(b + 1, c, x);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	cin >> n >> q;
	rep(i, 1, n + 1)
		cin >> a[i], cnt[a[i]]++;
	a[0] = M;
	a[n + 1] = 0;
	
	build();
	
	rep(i, 1, M + 1)
		if (!cnt[i])
			add(i, i, 1e9);
	
	rep(i, 0, n + 1)
		upd(i, 1);
		
	while (q--) {
		int p, x;
		cin >> p >> x;
		
		add(a[p], a[p], 1e9);
		add(x, x, -1e9);
		
		upd(p - 1, -1);
		upd(p, -1);
		
		a[p] = x;
		
		upd(p - 1, 1);
		upd(p, 1);
		
		assert(t[1].first == 1);
		cout << t[1].second << endl;
	}
	
	return 0;
}