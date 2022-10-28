#include <bits/stdc++.h>
using namespace std;

mt19937 rng(uint64_t(new char));
int rem = 4269;

void chk() {
    --rem;
    if (!rem) {
        while (true);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> pos(n);
	iota(pos.begin(), pos.end(), 0);

	int opt = 0;
	if (n >= (1 << 10)) {
		int cnt;
		do {
			opt = uniform_int_distribution<int>(0, pos.size() - 1u)(rng);
			cout << "? " << opt + 1 << ' ' << uniform_int_distribution<int>(1, pos.size())(rng) << endl;
			int res;
			cin >> res;
			chk();
			cnt = __builtin_popcount(res);
		} while (cnt > 8);
	}

	int pre = n;
	int zero = -1;
	while (true) {
		int cur = pre == n ? opt : uniform_int_distribution<int>(0, pos.size() - 1u)(rng);
		vector<int> nxt;
		int mn = 1 << 12;
		set<int> vals = {0};

		for (int i = 0; i < int(pos.size()); ++i) {
			if (i == cur)
				continue;
            
			cout << "? " << pos[cur] + 1 << ' ' << pos[i] + 1 << endl;
			int res;
			cin >> res;
			chk();

			vals.insert(res);
			if (res < mn) {
				mn = res;
				nxt.clear();
			}
			if (res == mn) {
				nxt.push_back(pos[i]);
			}
		}

		if (vals.size() == pos.size() && *vals.rbegin() < pre) {
			zero = pos[cur];
			break;
		}
		swap(nxt, pos);
		pre = mn;
	}

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		if (i == zero)
			continue;
		cout << "? " << zero + 1 << ' ' << i + 1 << endl;
		chk();
		cin >> ans[i];
	}

	cout << "! ";
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}