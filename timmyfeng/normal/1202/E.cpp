#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5;

int cnt[MX], term[MX + 1], link[MX + 1];
int to[MX + 1][26];
int sz = 1;
string t, s[MX];

void add(string& s) {
	int cur = 0;
	for (auto i : s) {
		if (!to[cur][i - 'a']) {
			to[cur][i - 'a'] = sz++;
		}
		cur = to[cur][i - 'a'];
	}
	++term[cur];
}

void aho() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i) {
			if (to[u][i]) {
				link[to[u][i]] = u ? to[link[u]][i] : 0;
				term[to[u][i]] += term[link[to[u][i]]];
				q.push(to[u][i]);
			} else {
				to[u][i] = to[link[u]][i];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> t >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		add(s[i]);
	}

	aho();
	int cur = 0;
	for (int i = 0; i < t.size(); ++i) {
		cur = to[cur][t[i] - 'a'];
		cnt[i] = term[cur];
	}

	memset(to, 0, sizeof to);
	memset(term, 0, sizeof term);
	memset(link, 0, sizeof link);
	sz = 1;
	for (int i = 0; i < n; ++i) {
		reverse(s[i].begin(), s[i].end());
		add(s[i]);
	}
	aho();

	cur = 0;
	ll ans = 0;
	for (int i = t.size() - 1; i; --i) {
		cur = to[cur][t[i] - 'a'];
		ans += (ll)cnt[i - 1] * term[cur];
	}
	cout << ans << '\n';
}