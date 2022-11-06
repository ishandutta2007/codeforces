#include <bits/stdc++.h>
#define x fisrt
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
using namespace std;

typedef pair<int, int> point;

const string FILENAME = "input";

const int MAXN = 2e5;

int n;
vector<int> edge[MAXN];

void sum(set<int> &a, set<int> &b) {
	if (a.size() < b.size()) swap(a, b);
	vector<int> bad;
	for (auto i : b) {
		if (a.count(i)) {
			bad.pb(i);
		}
	}
	for (auto i : bad) {
		a.erase(i);
		b.erase(i);
	}
	for (auto i : b) {
		a.insert(i);
	}
}

void dfs(int i, set<int> &a, int h = 0) {
	for (auto j : edge[i]) {
		set<int> b;
		dfs(j, b, h + 1);
		sum(a, b);
	}
 	a.insert(h);
 	// cout << i + 1 << ":"; for (auto i : a) cout << i << ' '; cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	//read(FILENAME);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		edge[p - 1].pb(i);
	}
	set<int> ans;
	dfs(0, ans);
	cout << ans.size() << endl;
}