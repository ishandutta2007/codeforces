#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5, M = 1 << 20 | 5;
int minv[M], siz[M], tag[M];
void update(int x){
	int ls = x << 1, rs = ls | 1;
	minv[x] = min(minv[ls], minv[rs]);
	siz[x] = (minv[ls] == minv[x]) * siz[ls] + (minv[rs] == minv[x]) * siz[rs];
	minv[x] += tag[x];
}
void modify(int x, int l, int r, int s, int t, int u){
	if (l == s && r == t) {
		minv[x] += u;
		tag[x] += u;
		return ;
	}
	int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
	if (t <= mid) modify(ls, l, mid, s, t, u);
	else if (s > mid) modify(rs, mid + 1, r, s, t, u);
	else modify(ls, l, mid, s, mid, u), modify(rs, mid + 1, r, mid + 1, t, u);
	update(x);
}
void flip(int x, int l, int r, int p){
	if (l == r) { siz[x] ^= 1; return ; }
	int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
	if (p <= mid) flip(ls, l, mid, p);
	else flip(rs, mid + 1, r, p);
	update(x);
}
int find(int x, int l, int r){
	if (l == r) return l;
	int ls = x << 1, rs = ls | 1, mid = (l + r) >> 1;
	if (minv[x] == minv[ls] && siz[ls] > 0) return find(ls, l, mid);
	return find(rs, mid + 1, r);
}
int T, n, p[N], q[N];
vector<pair<int, int>> obj[N];
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (cin >> T; T; --T) {
		vector<int> r;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			flip(1, 1, n, i);
			if (1 <= p[i] && p[i] <= n) obj[p[i]].pb(i, i);
			if (i + 1 < p[i]) obj[i].pb(i + 1, p[i] - 1);
		}
		for (int i = 1; i <= n; ++i) for (auto g : obj[i]) modify(1, 1, n, g.fi, g.se, 1);
		for (int t = 1, x; t <= n; ++t) {
			if (minv[1] != 0 || siz[1] == 0) break;
			x = find(1, 1, n), flip(1, 1, n, x), r.pb(x);
			for (auto g : obj[x]) modify(1, 1, n, g.fi, g.se, -1);
			obj[x].clear();
		}
		for (int i = 1; i <= n; ++i) {
			for (auto g : obj[i]) modify(1, 1, n, g.fi, g.se, -1);
			obj[i].clear();
		}
		while (siz[1]) flip(1, 1, n, find(1, 1, n));
		if (r.size() == n) {
			for (int i = 0; i < r.size(); ++i) q[r[i]] = n - i;
			for (int i = 1; i <= n; ++i) cout << q[i] << " \n"[i == n];
		} else cout << "-1\n";
	}
}