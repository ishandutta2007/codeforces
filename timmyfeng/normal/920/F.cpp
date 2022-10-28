#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

const int MX = 3e5 + 1;
const int MXA = 1e6 + 1;

ll st[MX * 2];
int d[MXA], n;

void upd(int a) {
	a += n;
	st[a] = d[st[a]];
	for (a /= 2; a; a /= 2) {
		st[a] = st[a * 2] + st[a * 2 + 1];
	}
}

ll qry(int a, int b) {
	ll res = 0;
	for (a += n, b += n; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			res += st[a++];
		}
		if (b % 2 == 0) {
			res += st[b--];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int k = 1; k < MXA; ++k) {
		int j = k;
		d[k] = 1;
		for (int i = 2; i * i <= j; ++i) {
			if (j % i)
				continue;
			int cnt = 0;
			while (j % i == 0) {
				j /= i;
				++cnt;
			}
			d[k] *= cnt + 1;
		}
		if (j > 1) {
			d[k] *= 2;
		}
	}

	int m;
	cin >> n >> m;
	set<int> todo;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		st[i + n] = a;
		if (a > 2) {
			todo.insert(i);
		}
	}

	for (int i = n - 1; i; --i) {
		st[i] = st[i * 2] + st[i * 2 + 1];
	}

	while (m--) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 1) {
			auto it_l = todo.lower_bound(a - 1);
			auto it_r = todo.lower_bound(b);
			vector<int> chk;
			while (it_l != it_r) {
				upd(*it_l);
				chk.push_back(*it_l);
				++it_l;
			}

			for (auto i : chk) {
				if (st[n + i] <= 2) {
					todo.erase(i);
				}
			}
		} else {
			cout << qry(a - 1, b - 1) << '\n';
		}
	}
}