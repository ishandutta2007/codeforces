#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, L = 101, MOD = 1000000007;
int n, m;

struct Poly {
	int l, num[L];

	Poly(int l = L - 1) : l(l) {
		memset(num, 0, sizeof(num));
	}

	int& operator [] (int i) {
		return num[i];
	}

	const int& operator [] (int i) const {
		return num[i];
	}
};

Poly& operator += (Poly &a, const Poly &b) {
	for (int i = 0; i <= a.l; ++i) {
		if ((a[i] += b[i]) >= MOD) {
			a[i] -= MOD;
		}
	}
	return a;
}

Poly& operator -= (Poly &a, const Poly &b) {
	for (int i = 0; i <= a.l; ++i) {
		if ((a[i] -= b[i]) < 0) {
			a[i] += MOD;
		}
	}
	return a;
}

void mul(Poly &a) {
	for (int i = a.l; i >= 1; --i) {
		a[i] += a[i - 1];
		if (a[i] >= MOD) {
			a[i] -= MOD;
		}
	}
}

int a[N];
Poly p[N];

vector<int> add[N];
vector<pair<int, int> > sub[N];
int cnt[N];

int main() {
	p[0][0] = 1;	
	for (int i = 1; i <= 100000; ++i) {
		p[i] = p[i - 1];
		mul(p[i]);
	}
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < m; ++i) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l, --r;
		add[l].push_back(k);
		sub[r].push_back(make_pair(k + r - l, k));
	}
	Poly sum[L];
	for (int i = 0; i < L; ++i) {
		sum[i].l = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			if (cnt[j]) {
				mul(sum[j]);
			}
		}
		for (int j = 0; j < (int)add[i].size(); ++j) {
			int k = add[i][j];
			sum[k] += p[k];
			++cnt[k];
		}
		for (int j = 0; j <= 100; ++j) {
			if ((a[i] += sum[j][j]) >= MOD) {
				a[i] -= MOD;
			}
		}
		for (int j = 0; j < (int)sub[i].size(); ++j) {
			int k = sub[i][j].second, kk = sub[i][j].first;
			sum[k] -= p[kk];
			--cnt[k];
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}