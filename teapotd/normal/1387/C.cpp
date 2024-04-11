#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

using ull = unsigned long long;
constexpr ull INF = 1ull << 63;

ull add(ull a, ull b) {
	if (a >= INF || b >= INF) {
		return INF;
	}
	return a+b;
}

struct Matrix {
	int n;
	vector<ull> M;

	Matrix(int _n = 0) : n(_n), M(_n*_n, INF) { }

	const ull* operator[](int i) const { return &M[i*n]; }
	ull* operator[](int i) { return &M[i*n]; }

	Matrix& operator+=(const Matrix& r) {
		rep(i, 0, sz(M)) M[i] = min(M[i], r.M[i]);
		return *this;
	}

	Matrix operator*(const Matrix& r) const {
		static Vi nice;
		Matrix ret(n);

		rep(i, 0, n) {
			nice.clear();
			rep(k, 0, n) if ((*this)[i][k] < INF) nice.pb(k);
			rep(j, 0, n) each(k, nice) {
				ret[i][j] = min(ret[i][j], add((*this)[i][k], r[k][j]));
			}
		}
		return ret;
	}
};

struct Aho {
	vector<array<int, 2>> nxt;
	vector<bool> acc;
	Vi suf;

	Aho() {
		nxt.pb({-1, -1});
		nxt.pb({1, 1});
		acc.resize(2);
	}

	void add(const Vi& s) {
		int cur = 0;
		each(e, s) {
			if (nxt[cur][e] == -1) {
				acc.pb(0);
				nxt.pb({-1, -1});
				nxt[cur][e] = sz(nxt)-1;
			}
			cur = nxt[cur][e];
		}
		acc[cur] = 1;
	}

	void build() {
		queue<int> que;
		suf.resize(sz(nxt), -1);

		rep(i, 0, 2) {
			int& j = nxt[0][i];
			if (j != -1) {
				suf[j] = 0;
				que.push(j);
			} else {
				j = 0;
			}
		}

		while (!que.empty()) {
			int i = que.front();
			que.pop();
			rep(j, 0, 2) {
				int& e = nxt[i][j];
				if (e != -1) {
					suf[e] = nxt[suf[i]][j];
					que.push(e);
				} else {
					e = nxt[suf[i]][j];
				}
			}
			acc[i] = acc[i] || acc[suf[i]];
		}
	}

	Matrix getMatrix(int e) {
		Matrix ret(sz(nxt));
		rep(i, 0, sz(nxt)) {
			int j = nxt[i][e];
			if (acc[j]) j = 1;
			ret[i][j] = 1;
		}
		return ret;
	}
};

int main() {
	int g, n, m; cin >> g >> n >> m;
	vector<vector<Vi>> mutations(g);

	rep(i, 0, n) {
		int a, k; cin >> a >> k;
		Vi mut(k);
		each(j, mut) cin >> j;
		mutations[a].pb(move(mut));
	}

	Aho aho;

	rep(i, 0, m) {
		int k; cin >> k;
		Vi tmp(k);
		each(j, tmp) cin >> j;
		aho.add(tmp);
	}

	int dim = sz(aho.nxt);
	vector<Matrix> dp(g, {dim});
	aho.build();
	dp[0] = aho.getMatrix(0);
	dp[1] = aho.getMatrix(1);

	bool chg = 1;

	while (chg) {
		chg = 0;
		rep(i, 2, g) {
			Matrix mat(dim);
			each(mut, mutations[i]) {
				Matrix tmp(dim);
				rep(j, 0, dim) tmp[j][j] = 0;
				each(j, mut) tmp = tmp*dp[j];
				mat += tmp;
			}

			rep(j, 0, sz(mat.M)) if (dp[i].M[j] != mat.M[j]) {
				chg = 1;
				dp[i] = mat;
				break;
			}
		}
	}

	rep(i, 2, g) {
		ull ans = INF;
		rep(j, 0, dp[i].n) if (j != 1) ans = min(ans, dp[i][0][j]);
		if (ans < INF) {
			cout << "NO " << ans << '\n';
		} else {
			cout << "YES\n";
		}
	}
	return 0;
}