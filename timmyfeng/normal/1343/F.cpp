#include <bits/stdc++.h> 
using namespace std;

vector<int> ans;
int n;

bool solve1(vector<set<int>>& s) {
	if ((int)ans.size() == n) return true;
	int nxt = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i].size() == 1u) {
			nxt = i;
		}
	}
	if (nxt == -1) return false;
	nxt = *s[nxt].begin();
	ans.push_back(nxt);
	for (auto& i : s) {
		i.erase(nxt);
	}
	return solve1(s);
}

bool chk(vector<set<int>>& s) {
	vector<bool> vstd(n - 1);
	for (int i = 1; i < n; ++i) {
		bool ok = false;
		for (int j = 0; j < i; ++j) {
			set<int> cur;
			for (int k = j; k <= i; ++k) {
				cur.insert(ans[k]);
			}
			int a = find(s.begin(), s.end(), cur) - s.begin();
			if (a != n - 1) {
				ok = true;
			}
		}
		if (!ok) return false;
	}
	return true;
}

void solve() {
	cin >> n;
	vector<set<int>> s(n - 1);
	vector<int> freq(n + 1);
	for (auto& i : s) {
		int k;
		cin >> k;
		while (k--) {
			int a;
			cin >> a;
			i.insert(a);
			++freq[a];
		}
	}

	for (int i = 1; i <= n; ++i) {
		auto s1 = s;
		for (auto& j : s1) {
			j.erase(i);
		}
		ans = {i};
		if (solve1(s1) && chk(s)) break;
	}

	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}