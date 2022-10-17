#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 3e5 + 10;
int p[N], sz[N], f[N], xx[N][2], ans = 0;
int cl[N];
vector<int> have[N];
int find(int v) {
	return p[v] == v ? v : find(p[v]);
}

int get(int v) {
	return p[v] == v ? f[v] : f[v] ^ get(p[v]);
}


void add_comp(int v) {
	if (cl[v] == -1) {
		ans += min(xx[v][0], xx[v][1]);
	}
	else {
		ans += xx[v][cl[v]];
	}
}

void del_comp(int v) {
	if (cl[v] == -1) {
		ans -= min(xx[v][0], xx[v][1]);
	}
	else {
		ans -= xx[v][cl[v]];
	}
}

void merge(int a, int b, int kek) {
	int aa = a, bb = b;
	//cout << aa << ' ' << bb << '\n';
	a = find(a), b = find(b);
	if (a == b) {
		return;
	}
	if (sz[a] < sz[b]) {
		swap(a, b);
		swap(aa, bb);
	}
	int c1 = get(aa), c2 = get(bb);
	del_comp(a);
	del_comp(b);
	if (kek) {
		if (c1 != c2) {
			xx[a][0] += xx[b][0];
			xx[a][1] += xx[b][1];
			if (cl[b] != -1) {
				cl[a] = cl[b];
			}
		}
		else {
			f[b] ^= 1;
			xx[a][0] += xx[b][1];
			xx[a][1] += xx[b][0];
			if (cl[b] != -1) {
				cl[a] = cl[b] ^ 1;
			}
		}
	}
	else {
		if (c1 == c2) {
			xx[a][0] += xx[b][0];
			xx[a][1] += xx[b][1];
			if (cl[b] != -1) {
				cl[a] = cl[b];
			}	
		}
		else {
			f[b] ^= 1;
			xx[a][0] += xx[b][1];
			xx[a][1] += xx[b][0];
			if (cl[b] != -1) {
				cl[a] = cl[b] ^ 1;
			}	
		}
	}
	p[b] = a;
	sz[a] += sz[b];
	add_comp(a);
}

int mn[N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s;	
	cin >> s;
	for (int i = 0; i < k; i++) {
		int cnt;
		cin >> cnt;
		mn[i + 1] = n + 1;
		for (int j = 0; j < cnt; j++) {
			int x;
			cin >> x;
			have[x].pb(i + 1);
			mn[i + 1] = min(mn[i + 1], x);
		}
	}
	for (int i = 1; i <= k; i++) {
		p[i] = i;
		sz[i] = 1;
		xx[i][0] = 1;
		xx[i][1] = 0;
		f[i] = 0;
		cl[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0') {
			if (SZ(have[i]) == 1) {
				del_comp(find(have[i][0]));
				cl[find(have[i][0])] = get(have[i][0]);
				add_comp(find(have[i][0]));	
			}
			else {
				merge(have[i][0], have[i][1], 1);
			}
		}
		else {
			if (have[i].empty()) {
				cout << ans << '\n';
				continue;
			}
			if (SZ(have[i]) == 1) {
				del_comp(find(have[i][0]));
				cl[find(have[i][0])] = get(have[i][0]) ^ 1;
				add_comp(find(have[i][0]));
				cout << ans << '\n';
				continue;
			}
			merge(have[i][0], have[i][1], 0);
		}
		cout << ans << '\n';
	}
}