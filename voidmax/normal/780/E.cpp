#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp push_back
#define all(a) a.begin(), a.end()
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)

using namespace std;

typedef long long base;
typedef pair <int, int> point;

const string FILENAME = "input";
const int MAXN = 2e5 + 1;

int n, m, k, c;
bool used[MAXN];
vector <int> edge[MAXN];
set <int> cnt[MAXN];
int d[MAXN], p[MAXN];
set <pair <int, int>> need;
vector <int> ans[MAXN];
bool res[MAXN];

int L = 0;

void add(int i) {
	if (ans[L].size() == c)
		++L;
	ans[L].pb(i);
}

void dfs(int i) {
	res[i] = true;
	if (ans[L].size() == c) {
		++L;
	}
	add(i);
	for (int j: edge[i]) {
		if (res[j]) continue;
		dfs(j);
		add(i);
	}
}


int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n >> m >> k;
	c = (2 * n + k - 1) / k;
	for (int i = m; i--;) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(0);
	for (int i = 0; i < k; ++i) {
		if (ans[i].size() == 0)
			ans[i].pb(0);
		cout << ans[i].size() << ' ';
		for (int j: ans[i]) {
			cout << j + 1 << ' ';
		}
		cout << '\n';
	}
}