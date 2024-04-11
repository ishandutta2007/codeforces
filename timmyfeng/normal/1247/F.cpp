#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;
int par[MX], len[MX];
vector<int> chd[MX];
vector<int> bb, seq;

void dfs1(int u) {
	len[u] = 1;
	for (auto c : chd[u]) {
		dfs1(c);
		len[u] = max(len[u], len[c] + 1);
	}
}

bool cmp(int a, int b) {
	return len[a] < len[b];
}

void dfs2(int u) {
	bb.push_back(u);
	sort(chd[u].begin(), chd[u].end(), cmp);
	int prev = -1;
	for (auto c : chd[u]) {
		dfs2(c);
		if (~prev) {
			for (int i = 0; i < len[prev]; ++i) {
				seq.push_back(c);
			}
		}
		prev = c;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		par[i] = p;
		chd[p].push_back(i);
	}

	dfs1(0);
	dfs2(0);

	for (auto i : bb) {
		cout << i << ' ';
	}
	cout << '\n';
	cout << seq.size() << '\n';
	for (auto i : seq) {
		cout << i << ' ';
	}
	cout << '\n';
}