#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int N = 5e5 + 10;
int nxt[N], a[N];
vector<int> t[4 * N];

vector<int> merge(vector<int> &a, vector<int> &b) {
	vector<int> res;
	int ptr = 0;
	for (auto it : a) {
		while (ptr < SZ(b) && b[ptr] < it) {
			res.pb(b[ptr++]);
		}
		res.pb(it);
	}
	for (int i = ptr; i < SZ(b); i++) {
		res.pb(b[i]);
	}
	return res;
}

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = {nxt[l]};
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	t[v] = merge(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int a, int b, int vl) {
	if (l > b || r < a) {
		return INF;
	}
	if (l >= a && r <= b) {
		int id = upper_bound(all(t[v]), vl) - t[v].begin();
		return (id == SZ(t[v]) ? INF : t[v][id]);
	}
	int mid = (l + r) / 2;
	return min(get(2 * v, l, mid, a, b, vl), get(2 * v + 1, mid + 1, r, a, b, vl));
}

signed main() {
	int n;
	cin >> n;
	unordered_map<int, int> lst;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for (int i = n; i >= 1; i--) {
		if (lst.find(a[i]) == lst.end()) {
			nxt[i] = n + 1;
		}
		else {
			nxt[i] = lst[a[i]];
		}
		lst[a[i]] = i;
	}
	/*for (int i = 1; i <= n; i++) {
		cout << nxt[i] << ' ';
	}
	cout << '\n';*/
	nxt[n + 1] = n + 1;
	build(1, 1, n);
	vector<int> ans;
	int cur = 1;
	for (;;) {
		pair<int, int> best = {n + 1, n + 1};
		for (int i = cur; i + 3 < best.F; i++) {
			best = min(best, make_pair(nxt[nxt[nxt[i]]], i));
			if (nxt[i] != n + 1) {
				best = min(best, make_pair(get(1, 1, n, i + 1, nxt[i] - 1, nxt[i]), i));
			}
		}
		if (best.F == n + 1) {
			break;
		}
		ans.pb(a[best.S]);
		ans.pb(a[best.F]);
		ans.pb(a[best.S]);
		ans.pb(a[best.F]);
		cur = best.F + 1;	
	}
	cout << SZ(ans) << '\n';
	for (auto it : ans) {
			cout << it << ' ';
	}
	cout << '\n';
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}