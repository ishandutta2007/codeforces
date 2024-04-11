#include <iostream>
#include <unordered_map>
#define int long long

using namespace std;

unordered_map <string, int> to_num;

const int MAX_N = 1e5 + 7, MAX_M = 47;
bool good[MAX_M][MAX_N];
int friends[MAX_M];
unordered_map <int, int> mem;

int rec(int mask) {
	if (mem.find(mask) != mem.end()) return mem[mask];
	if (mask == 0) {
		mem[mask] = 0;
		return 0;
	}
	int ans = 1;
	int fi = 63 - __builtin_clzll(mask);
	ans = max(ans, rec(mask ^ (1ll << fi)));
	ans = max(ans, 1 + rec(mask & friends[fi]));
	mem[mask] = ans;
	return ans;
}

signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			good[j][i] = 1;
			friends[j] = 0;
		}
	}
	int last = -1;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 1) last = i;
		else {
			string s;
			cin >> s;
			int tt = to_num.size();
			if (to_num.find(s) == to_num.end()) to_num[s] = tt;
			int num = to_num[s];
			//cout << num << ' ' << last << endl;
			good[num][last] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int ok = 1;
			for (int k = 0; k < n; k++) {
				if (!good[i][k] && !good[j][k]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
			    //cout << i << ' ' << j << endl;
				friends[i] |= (1ll << j);
				friends[j] |= (1ll << i);
			}
		}
	}
	cout << rec((1ll << m) - 1) << endl;
	return 0;
}