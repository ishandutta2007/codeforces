#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 5e5 + 7;
int nxt[MAX_N], perm[MAX_N], cl[MAX_N];

bool cmp(pair <int, int> a, pair <int, int> b) {
	if (a.first != b.first) return (a.first < b.first);
	return (a.second > b.second);
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n + 1; i++) cl[i] = 0;
		bool flag = 1;
		int cur_max = 0;
		vector <pair <int, int>> poses;
		int bal = 0;
		vector <int> st;
		//cout << "Test: " << endl;
		//cout << n << endl;
		for (int i = 1; i <= n; i++) {
			//bal -= cl[i];
			poses.push_back({bal, i});
			//cout << i << ' ' << bal << endl;
			cin >> nxt[i];
			if (nxt[i] == -1) nxt[i] = i + 1;
			nxt[i]--;
			bal++;
			cl[nxt[i]]++;
			if (!st.empty() && nxt[i] > st.back()) {
				flag = 0;
			}
			cur_max = max(cur_max, nxt[i]);
			bal -= cl[i];
			if (st.empty() || nxt[i] <= st.back()) st.push_back(nxt[i]);
			while (!st.empty() && st.back() == i) st.pop_back();
		}
		//cout << n << ' ' << cur_max << endl;
		if (!flag) {
			cout << -1 << "\n";
			continue;
		}
		sort(poses.begin(), poses.end(), cmp);
		int cur = n;
		for (pair <int, int> elem : poses) {
			perm[elem.second] = cur--;
		}
		for (int i = 1; i <= n; i++) cout << perm[i] << ' ';
		cout << "\n";
	}
	return 0;
}