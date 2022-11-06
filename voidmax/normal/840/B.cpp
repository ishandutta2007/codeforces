// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
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
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;


const string FILENAME = "input";
const int MAXN = 3e5 + 1;

int n, m;
int d[MAXN];
vector <pair <int, int>> edge[MAXN];
vector <int> e[MAXN];

int p[MAXN], num[MAXN], powx[MAXN];
bool have[MAXN];
bool push[MAXN];
bool used[MAXN];

int id_cool, cnt_bad;
vector <int> comp;

vector <int> ans;

void dfs(int i) {
	//cout << i << endl;
	if (d[i] == -1) id_cool = i;
	comp.pb(i);
	for (auto j : edge[i]) {
		if (!used[j.x]) {
			powx[j.x] = 1;
			++powx[i];
			p[j.x] = i;
			num[j.x] = j.y;
			used[j.x] = true;
			e[i].pb(j.x);
			dfs(j.x);
		}
	}
	if (d[i] != -1) {
		if (powx[i] % 2 != d[i]) {
			++cnt_bad;
			push[i] = true;
			//cout << i << endl;
		}
	}
	//cout << i << ' ' << powx[i] << endl;
}

void dfs_push(int i) {
	for (auto j : e[i]) {
		dfs_push(j);
	}
	if (p[i] != -1) {
		if (!push[i]) {
			ans.pb(num[i]);
		}
		push[p[i]] ^= push[i];
	}
}

void test() {
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		used[i] = true;
		id_cool = -1;
		cnt_bad = 0;
		comp.clear();
		p[i] = -1;
		powx[i] = 0;
		dfs(i);
		if (id_cool != -1) {
			if (cnt_bad & 1) push[id_cool] = true;
		} else if (cnt_bad & 1) {
			cout << -1 << endl;
			exit(0);
		}
		dfs_push(i);
	}
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
   	//read(FILENAME);
   	cin >> n >> m;
   	for (int i = 0; i < n; ++i) {
   		cin >> d[i];
   	}
   	for (int i = 0; i < m; ++i) {
   		int a, b;
   		cin >> a >> b;
   		--a, --b;
   		edge[a].pb({b, i});
   		edge[b].pb({a, i});
   	}
   	test();
   	cout << ans.size() << '\n';
   	sort(ans.begin(), ans.end());
   	for (int i : ans) {
   		cout << i + 1 << '\n';
   	}
   	cout << "\n";
}