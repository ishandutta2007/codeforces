#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;

const int MAXN = 2e5;
typedef pair <long long, long long> point;

int n;
bool color[MAXN];
vector <int> edge[MAXN];

int max_ans = 0;

int dfs(int i, int p) {
	vector <int> d;
	for (int j: edge[i]) {
		if (j == p) continue;
		d.pb(dfs(j, i) + (color[i] != color[j]));
	}
	sort(d.rbegin(), d.rend());
	if (d.size() == 0)
		return 0;
	if (d.size() == 1) {
		max_ans = max(max_ans, d[0]);
	} else {
		max_ans = max(max_ans, d[0] + d[1]);
	}
	return d[0];
}

int main() {
	ios::sync_with_stdio(0);
	//freopen("input.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> color[i];
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(0, -1);
	cout << (max_ans + 1) / 2 << endl;
}