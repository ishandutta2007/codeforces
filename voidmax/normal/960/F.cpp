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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

typedef long double base;
typedef pair<base, base> point;

const int MAXN = 1e5 + 1;

int n, m;
set<pair<int, int>> cnt[MAXN];

int main() {
	srand(time(0));
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cnt[i].insert({-1, 0});
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		auto it = cnt[a].lower_bound(mp(c, -1));	
		--it;
		auto cur_ans = *it;
		cur_ans.x = c;
		cur_ans.y++;
		chkmax(ans, cur_ans.y);
		while (true) {
			auto it = cnt[b].upper_bound(cur_ans);
			if (it == cnt[b].end()) break;
			if (it -> y < cur_ans.y) {
				cnt[b].erase(it);
			} else {
				break;
			}
		}
		it = cnt[b].upper_bound(cur_ans);
		--it;
		if (cur_ans.y < it -> y) continue;
		cnt[b].insert(cur_ans);
	}
	cout << ans << endl;
}