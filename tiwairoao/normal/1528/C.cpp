#include <bits/stdc++.h>

const int N = 300000;

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = getchar();
	return x;
}

struct seg{
	int l, r;
	friend bool operator < (const seg &a, const seg &b) {
		return a.r < b.r;
	}
}a[N + 5];
std::set<seg>st;

std::vector<int>G1[N + 5], G2[N + 5];
void adde1(int x, int y) {G1[x].push_back(y);}
void adde2(int x, int y) {G2[x].push_back(y);}

int dcnt;
void dfs2(int x) {
	a[x].l = (++dcnt);
	for (auto to : G2[x]) dfs2(to);
	a[x].r = dcnt; 
}

int ans, nw;
void dfs1(int x) {
	seg p = *st.lower_bound(a[x]);
	if (p.l <= a[x].l && a[x].r <= p.r) st.erase(p), nw--;
	st.insert(a[x]), nw++, ans = std::max(ans, nw);
	for (auto to : G1[x]) dfs1(to);
	st.erase(a[x]), nw--;
	if (p.l <= a[x].l && a[x].r <= p.r) st.insert(p), nw++;
}

void solve() {
	int n = read();
	for (int i = 1; i <= n; i++) G1[i].clear(), G2[i].clear();
	for (int i = 2; i <= n; i++) adde1(read(), i);
	for (int i = 2; i <= n; i++) adde2(read(), i);
	dcnt = 0, dfs2(1);

	st.clear(), st.insert((seg){n + 1, n + 1});
	nw = ans = 0, dfs1(1);
	printf("%d\n", ans);
}

int main() {
	for (int t = read(); t; t--) solve();
}