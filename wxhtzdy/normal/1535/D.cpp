#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int k;
	cin >> k;
	string s;
	cin >> s;
	int n = (1 << k);
	vector<int> par(n + 1, -1), ls(n + 1, -1), rs(n + 1);
	int l = k;
	vector<int> id;
	for (int i = 0; i < n - 1; i++) {
		id.push_back(i);
	}
	vector<int> svi;
	int nxt = 0;
	vector<int> cnt(n);
	for (int i = 0; i < (1 << (k - 1)); i++) {
		svi.push_back(nxt);
		cnt[nxt] = 1;
		nxt++;
	}
	for (int j = k - 2; j >= 0; j--) {
		vector<int> cur;
		for (int i = 0; i < (1 << j); i++) {
			cur.push_back(nxt);
			nxt++;
		}
		int pos = 0;
		for (int i = 0; i < (int) cur.size(); i++) {
			ls[cur[i]] = svi[pos++];
			rs[cur[i]] = svi[pos++];
			par[ls[cur[i]]] = cur[i];
			par[rs[cur[i]]] = cur[i];
		}
		swap(svi, cur);
	}
	for (int i = 0; i < n; i++) {
		if (ls[i] == -1) {
			cnt[i] = (s[i] == '?' ? 2 : 1);
		} else {
			if (s[i] == '?') {
				cnt[i] = cnt[ls[i]] + cnt[rs[i]];
			}
			if (s[i] == '0') {
				cnt[i] = cnt[ls[i]];
			}
			if (s[i] == '1') {
				cnt[i] = cnt[rs[i]];
			}
		}
	}
	function<void(int)> update = [&](int i) {
		while (true) {
			if (ls[i] == -1) {
				cnt[i] = (s[i] == '?' ? 2 : 1);
			} else {
				if (s[i] == '?') {
					cnt[i] = cnt[ls[i]] + cnt[rs[i]];
				}
				if (s[i] == '0') {
					cnt[i] = cnt[ls[i]];
				}
				if (s[i] == '1') {
					cnt[i] = cnt[rs[i]];
				}
			}
			i = par[i];
			if (i == -1) break;
		}
	};
	int qq;
	cin >> qq;
	while (qq--) {
		int pos;
		cin >> pos;
		--pos;
		char c;
		cin >> c;
		s[pos] = c;
		update(pos);
		cout << cnt[n - 2] << '\n';
	}
}