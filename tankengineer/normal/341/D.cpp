#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int n, m;

struct Fenwich1D {
	long long tra[N], trb[N];

	Fenwich1D() {
		memset(tra, 0, sizeof(tra));
		memset(trb, 0, sizeof(trb));
	}

	void change(int x, long long val) {
		if (x == 0) {
			return;
		}
		tra[0] ^= val;
		for (int i = x; i <= n; i += i & -i) {
			tra[i] ^= val;
			trb[i] ^= x & 1 ? val : 0ll;
		}
	}

	long long ask(int x) {
		if (x == 0) {
			return 0;
		}
		long long ret = x & 1 ? tra[0] : 0ll;
		for (int i = x; i; i -= i & -i) {
			ret ^= x & 1 ? tra[i] : 0ll;
			ret ^= trb[i];
		}
		return ret;
	}
};

struct Fenwich2D {
	Fenwich1D tra[N], trb[N];

	void change(int x, int y, long long val) {
		if (x == 0 || y == 0) {
			return;
		}
		tra[0].change(y, val);
		for (int i = x; i <= n; i += i & -i) {
			tra[i].change(y, val);
			trb[i].change(y, x & 1 ? val : 0ll);
		}
	}

	long long ask(int x, int y) {
		if (x == 0 || y == 0) {
			return 0;
		}
		long long ret = x & 1 ? tra[0].ask(y) : 0ll;
		for (int i = x; i; i -= i & -i) {
			ret ^= x & 1 ? tra[i].ask(y) : 0ll;
			ret ^= trb[i].ask(y);
		}
		return ret;
	}
} tr;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	while (m--) {
		int type, x0, y0, x1, y1;
		cin >> type >> x0 >> y0 >> x1 >> y1;
		if (type == 2) {
			long long val;
			cin >> val;
			tr.change(x1, y1, val);
			tr.change(x1, y0 - 1, val);
			tr.change(x0 - 1, y1, val);
			tr.change(x0 - 1, y0 - 1, val);
		} else {
			long long ans = tr.ask(x1, y1) ^ tr.ask(x1, y0 - 1) ^ tr.ask(x0 - 1, y1) ^ tr.ask(x0 - 1, y0 - 1);
			cout << ans << endl;
		}
	}
	return 0;
}