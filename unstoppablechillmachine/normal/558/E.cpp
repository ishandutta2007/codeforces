#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

struct Block {
	vector<int> cnt;
	bool is_rev;
	Block(vector<int> a, bool need) {
		cnt = a;
		is_rev = need;
	}
	pair<vector<int>, vector<int>> split(int left_len) {
		vector<int> l(26), r(26);
		if (is_rev) {
			for (int i = 25; i >= 0; i--) {
				if (left_len >= cnt[i]) {
					l[i] = cnt[i];
					r[i] = 0;
					left_len -= cnt[i];
				}
				else {
					l[i] = left_len;
					r[i] = cnt[i] - left_len;
					left_len = 0;
				}
			}
		}
		else {
			for (int i = 0; i < 26; i++) {
				if (left_len >= cnt[i]) {
					l[i] = cnt[i];
					r[i] = 0;
					left_len -= cnt[i];
				}
				else {
					l[i] = left_len;
					r[i] = cnt[i] - left_len;
					left_len = 0;
				}
			}
		}
		return make_pair(l, r);
	}
	void merge(Block bl) {
		for (int i = 0; i < 26; i++) {
			cnt[i] += bl.cnt[i];
		}
	}
	void out() {
		if (is_rev) {
			for (int i = 25; i >= 0; i--) {
				for (int j = 0; j < cnt[i]; j++) {
					cout << char('a' + i);
				}
			}
		}
		else {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < cnt[i]; j++) {
					cout << char('a' + i);
				}
			}
		}
	}
};

signed main() {
	int n, q;
	cin >> n >> q;
	vector<Block> kek;
	vector<int> id(n + 1);
	set<int> st;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		vector<int> h(26);
		h[c - 'a']++;
		kek.emplace_back(h, false);
		id[i] = SZ(kek) - 1;
		st.insert(i);
	}
	st.insert(n + 1);
	for (int i = 0; i < q; i++) {
		int l, r;
		bool is_rev;
		cin >> l >> r >> is_rev;
		if (is_rev) {
			is_rev = false;
		}
		else {
			is_rev = true;
		}
		if (st.find(l) == st.end()) {
			int l2 = *(--st.upper_bound(l)), cur_block = id[l2];
			auto musorka = kek[cur_block].split(l - l2);
			bool need = kek[id[l2]].is_rev;
			kek.emplace_back(musorka.F, need);
			id[l2] = SZ(kek) - 1;
			kek.emplace_back(musorka.S, need);
			id[l] = SZ(kek) - 1;
			st.insert(l);
		}
		if (st.find(r + 1) == st.end()) {
			int cl = *(--st.upper_bound(r + 1)), cur_block = id[cl];
			auto musorka = kek[cur_block].split(r - cl + 1);
			bool need = kek[id[cl]].is_rev;
			kek.emplace_back(musorka.F, need);
			id[cl] = SZ(kek) - 1;
			kek.emplace_back(musorka.S, need);
			id[r + 1] = SZ(kek) - 1;
			st.insert(r + 1);
		}
		auto it = st.find(l);
		vector<int> vals;
		Block nw(vector<int>(26, 0), is_rev);
		while (it != st.end() && *it <= r) {
			vals.pb(*it);
			nw.merge(kek[id[*it]]);
			it++;
		}
		for (auto it : vals) {
			st.erase(it);
		}
		st.insert(l);
		kek.pb(nw);
		id[l] = SZ(kek) - 1;
	}
	for (int l : st) {
		if (l <= n) kek[id[l]].out();
	}
	cout << '\n';
}