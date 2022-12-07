#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 444000;
const int P = 998244353;

int n1, n2, w = 1, m, q, sum[N][2], fa[N], id[N], col[N], cnt;
ll ans;

int find(int x) {
	if (fa[x] == x) return x;
	int p = find(fa[x]);
	col[x] ^= col[fa[x]];
	return fa[x] = p;
}

void merge(int x, int y) {
	int px = find(x), py = find(y), d = col[x] ^ col[y] ^ 1;
	if (px == py) return;
	if (d == 1) {
		ans = (ans - sum[px][1] + sum[px][0] + P) % P;
		swap(sum[px][0], sum[px][1]);
		col[px] = 1;
	}
	fa[px] = py;
	sum[py][0] = (sum[py][0] + sum[px][0]) % P;
	sum[py][1] = (sum[py][1] + sum[px][1]) % P;
}

void add() {
	int a, b;
	cin >> a >> b;
	b += n1;
	w = (2 * w) % P;
	sum[++cnt][0] = w;
	fa[cnt] = cnt;
	if (id[a] > id[b]) swap(a, b);
	if (!id[a] && !id[b]) 
		id[a] = id[b] = cnt;
	else if (!id[a]) {
		merge(id[b], cnt);
		id[a] = cnt;
		id[b] = 0;
	}
	else {
		merge(id[a], cnt);
		merge(id[b], cnt);
		id[a] = id[b] = 0;
	}	
}
 
int main() {
	cin >> n1 >> n2 >> m;
	while (m--) add();
	cin >> q;
	while (q--) {
		int e;
		cin >> e;
		if (e == 1) add(), cout << ans << endl;
		else {
			vector<int> ans;
			rep(i, 1, cnt) {
				find(i);
				if (col[i]) ans.push_back(i);
			}
			cout << ans.size() << endl;
			for (auto x : ans) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}