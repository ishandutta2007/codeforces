#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define len(v) ((int)v.size())

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	for (T x : v) {
		os << x << " ";
	}
	return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
	for (T &x : v) {
		is >> x;
	}
	return is;
}

void run();

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
}

const int N = (1 << 20);

vector<int> S(N * 2);
vector<int> C(N * 2);
void add(int i, int tl, int tr, int price, int cnt) {
	if (tl + 1 == tr) {
		S[i] += cnt * price;
		C[i] += cnt;
	} else {
		int m = (tl + tr) / 2;
		if (price < m) {
			add(i * 2 + 1, tl, m, price, cnt);
		} else {
			add(i * 2 + 2, m, tr, price, cnt);
		}
		S[i] = S[i * 2 + 1] + S[i * 2 + 2];
		C[i] = C[i * 2 + 1] + C[i * 2 + 2];
	}
}

int query(int i, int tl, int tr, int k) {
	if (tl + 1 == tr) {
		return min(k, C[i]) * tl;
	} else {
		int m = (tl + tr) / 2;
		int rez = 0;
		if (C[i * 2 + 1] <= k) {
			k -= C[i * 2 + 1];
			rez += S[i * 2 + 1];
			return rez + query(i * 2 + 2, m, tr, k);
		} else {
			return query(i * 2 + 1, tl, m, k);
		}
	}
}

vector<vector<pii>> ADD(N), DEL(N);

void run() {
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		int l, r, c, p;
		cin >> l >> r >> c >> p;
		ADD[l].emplace_back(p, c);
		DEL[r + 1].emplace_back(p, c);
	}
	int rez = 0;
	for (int i = 1; i <= n; i++) {
		for (pii p : ADD[i]) {
			add(0, 0, N, p.first, p.second);
		}
		for (pii p : DEL[i]) {
			add(0, 0, N, p.first, -p.second);
		}
		// cout << query(0, 0, N, k) << endl;
		rez += query(0, 0, N, k);
	}
	cout << rez << endl;
}