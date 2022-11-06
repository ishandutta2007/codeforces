#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <random>  
#include <ctime>
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 1e6 + 1;

bool used[MAXN];
int n, m;
int h[MAXN];
vector <int> edge[MAXN];
vector <pair <int, pair <int, int>>> ans;

int dfs(int i) {
	if (used[i]) return -1;
	used[i] = true;
	vector <int> bad;
	for (int j : edge[i]) {
		if (used[j] && h[j] < h[i]) continue;
		if (!used[j]) {
			h[j] = h[i] + 1;
		}
		int q = dfs(j);
		if (q == -1) {
			bad.pb(j);
		} else {
			ans.pb({i, {j, q}});
		}
	}
	while (bad.size() >= 2) {
		int j = bad.back();
		bad.pop_back();
		int q = bad.back();
		bad.pop_back();
		ans.pb({j, {i, q}});
	}
	bad.pb(-1);
	return bad[0];
}

int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FILENAME);
	srand(time(0));
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i);
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i.x << ' ' << i.y.x << ' ' << i.y.y << '\n';
	}
}