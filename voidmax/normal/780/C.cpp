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
const int p = 1e9 + 7, MAXN = 2e5 + 1;

int n, r;
int color[MAXN];
vector <int> edge[MAXN];

void dfs(int i, int p = -1, int c = -1) {
	int cnt = 0;
	for (int j: edge[i]) {
		if (j == p) continue;
		while (cnt == color[i] || cnt == c) {
			++cnt;
		}
		r = max(r, cnt + 1);
		color[j] = cnt;
		dfs(j, i, color[i]);
		++cnt;
	}
}

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n;
	for (int t = n - 1; t--;) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(0);
	cout << r << endl;
	for (int i = 0; i < n; ++i) {
		cout << color[i] + 1 << ' ';
	}
	cout << endl;
}