#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int dp[N][N], n, m, x, y;
string s[N], chg;
int A[N][N], C[N];
int d[10];

void doit(string &s, int *A) {
	for(int i = 0; i < (int) s.size(); ++ i) {
		if(s[i] == '?') {
			A[s.size() - 1 - i] = -1;
			continue;
		}
		A[s.size() - 1 - i] = s[i] - '0';
	}
}

void Max(int &x, int y) {
	x = max(x, y);
}

int Rk[N], id[N], tmp[N];
vector <int> T[10], D[N];

void getRk(int x) {
	for(int i = 0; i <= 9; ++ i) T[i].clear();
	for(int i = 0; i <= n; ++ i) D[i].clear();
	for(int i = 1; i <= n; ++ i) D[Rk[i]].push_back(i);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < (int)D[i].size(); ++ j) {
			T[A[D[i][j]][x]].push_back(D[i][j]);
		}
	}
	int tot = 0;
	for(int i = 0; i <= 9; ++ i) {
		for(int j = 0; j < (int)T[i].size(); ++ j) {
			id[++ tot] = T[i][j];	
		}
	}
	for(int i = 1; i <= tot; ++ i) {
		if(Rk[id[i]] == Rk[id[i - 1]] && A[id[i]][x] == A[id[i - 1]][x]) {
			tmp[id[i]] = tmp[id[i - 1]];
		}
		else tmp[id[i]] = i;
	}
	for(int i = 1; i <= n; ++ i) Rk[i] = tmp[i];
}

main() {
	cin >> chg; m = chg.size();
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> s[i], m = max((int)s[i].size(), m);
	++ m;
	for(int i = 0; i <= 9; ++ i) scanf("%d", &d[i]);
	doit(chg, C);
	for(int i = 1; i <= n; ++ i) {
		doit(s[i], A[i]);
	}
	for(int i = 0; i <= m + 1; ++ i) {
		for(int j = 0; j <= n + 1; ++ j)
		dp[i][j] = -1e9;
	}
	for(int i = 1; i <= n; ++ i) Rk[i] = i, id[i] = i;
	for(int i = 0; i <= 9; ++ i) T[i].clear();
	dp[0][0] = 0;
	for(int i = 0; i <= m; ++ i) {
		int l = 0, r = 9;
		if(C[i] !=- 1) l = r = C[i];
		if(i == (int)chg.size() - 1) l = max(l, 1);
		for(int j = l; j <= r; ++ j) {
			int a, b;
			a = b = 0;
			for(int k = 1; k <= n; ++ k) {
				if(i >= chg.size() && i >= s[k].size()) {
					continue;
				}
				if(A[k][i] + j >= 10) ++ a;
				b += d[(A[k][i] + j) % 10];
			}
			for(int k = 0; k <= n; ++ k) {
				Max(dp[i + 1][a], dp[i][k] + b);
				if(k != n) {
					if(i >= chg.size() && i >= s[id[k + 1]].size()) {
						b += d[1];
						continue;
					}
					if(A[id[k + 1]][i] + j == 9) ++ a;
					b -= d[(A[id[k + 1]][i] + j) % 10];
					b += d[(A[id[k + 1]][i] + j + 1) % 10];
				}
			}
		}
		getRk(i);
		reverse(id + 1, id + n + 1);
	}
	cout << dp[m + 1][0] << endl;
}