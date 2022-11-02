#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

struct Fenwich {
	int n;
	int tr[N];

	Fenwich() {
		memset(tr, 0, sizeof(tr));
	}

	void add(int pos, int delta) {
		while (pos <= n) {
			tr[pos] += delta;
			pos += pos & -pos;
		}
	}

	int ask(int pos) {
		int ret = 0;
		while (pos) {
			ret += tr[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

Fenwich pre, suf;

int n, k, a, b;

int capb[N], capa[N];

int main() {
	int q;
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	pre.n = n;
	suf.n = n;
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int di, ai;
			scanf("%d%d", &di, &ai);
			int df = min(capb[di - 1] + ai, b) - capb[di - 1];
			if (df) {
				capb[di - 1] += df;
				pre.add(di, df);
			}
			df = min(capa[n - di] + ai, a) - capa[n - di];
			if (df) {
				capa[n - di] += df;
				suf.add(n - di + 1, df);
			}
		} else {
			int pi;
			scanf("%d", &pi);
			int ans = pre.ask(pi - 1);
			if (pi + k <= n) {
				ans += suf.ask(n - (pi + k) + 1);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}