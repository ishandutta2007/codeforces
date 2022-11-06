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
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FileName = "input";

const int MAXN = 3e5 + 100;

int n;
vector <int> lay[MAXN];
vector <pair <int, int>> edge[MAXN];

int dfs(vector <int> &v) {
	if (v.size() < 2) return 0;
	vector <int> u[26];
	for (int i: v) {
		for (auto j: edge[i]) {
			u[j.x].pb(j.y);
		}
	}
	int cnt = (int)v.size() - 1;
	for (int i = 0; i < 26; ++i)
		cnt += dfs(u[i]);
	return cnt;
}


int nans = -1, p = 0;

void check(int h) {
	int ans = 0;
	for (int i: lay[h]) {
		vector <int> v;
		for (auto j: edge[i]) {
			v.pb(j.y);
		}
		if (v.size())
			ans += dfs(v) + 1;
	}
	//cout << ans << ' ' << h << endl;
	if (nans < ans)  {
		nans = ans;
		p = h;
	}
}

void dfs_h(int i, int h = 0) {
	lay[h].pb(i);
	for (auto j: edge[i]) {
		dfs_h(j.y, h + 1);
	}
}

int main(int argc, char const *argv[]) {
    srand(time(0));
    //read(FileName);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
    	int a, b;
    	char c;
    	cin >> a >> b >> c;
    	--a, --b, c -= 'a';
    	edge[a].pb({c, b});
    }
    dfs_h(0);
    for (int h = 0; h <= n; ++h) {
    	check(h);
    }
    cout << n - nans << '\n' << p + 1 << endl;
}