#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int chr_to_num[256];
char num_to_chr[4];

struct board{
	vector <vector <int>> b;
	int n, m;
	board() {}
	board(int n, int m) {
		b.resize(n);
		for (int i = 0; i < n; i++) b[i].resize(m);
		this->n = n;
		this->m = m;
	}
	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << num_to_chr[b[i][j]];
			}
			cout << '\n';
		}
	}
};

const int MAX_N = 3e5 + 7;
board b, best;
int best_res = MAX_N;
int dp[MAX_N + 1][4][4];
pair <int, int> prv[MAX_N + 1][4][4];



void init() {
	chr_to_num['A'] = 0;
	chr_to_num['G'] = 1;
	chr_to_num['C'] = 2;
	chr_to_num['T'] = 3;
	num_to_chr[0] = 'A';
	num_to_chr[1] = 'G';
	num_to_chr[2] = 'C';
	num_to_chr[3] = 'T';
}

pair <int, int> get_rest(int a, int b) {
	vector <int> kek;
	for (int i = 0; i < 4; i++) {
		if (a != i && b != i) kek.push_back(i);
	}
	return make_pair(kek[0], kek[1]);
}

void solve_1(int n, int m) {
	for (int n1 = 0; n1 < 4; n1++) {
		for (int n2 = n1 + 1; n2 < 4; n2++) {
			pair <int, int> rest = get_rest(n1, n2);
			int n3 = rest.first, n4 = rest.second;
			int now_s = 0;
			board now(n, m);
			for (int i = 0; i < n; i += 2) {
				int now_s1 = 0;
				for (int j = 0; j < m; j++) {
					int now_v = (j % 2 == 0 ? n1 : n2);
					if (b.b[i][j] != now_v) now_s1++;
				}
				int now_s2 = 0;
				for (int j = 0; j < m; j++) {
					int now_v = (j % 2 == 0 ? n2 : n1);
					if (b.b[i][j] != now_v) now_s2++;
				}
				if (now_s1 < now_s2) {
					now_s += now_s1;
					for (int j = 0; j < m; j++) now.b[i][j] = (j % 2 == 0 ? n1 : n2);
				} else {
					now_s += now_s2;
					for (int j = 0; j < m; j++) now.b[i][j] = (j % 2 == 0 ? n2 : n1);
				}
			}
			for (int i = 1; i < n; i += 2) {
				int now_s1 = 0;
				for (int j = 0; j < m; j++) {
					int now_v = (j % 2 == 0 ? n3 : n4);
					if (b.b[i][j] != now_v) now_s1++;
				}
				int now_s2 = 0;
				for (int j = 0; j < m; j++) {
					int now_v = (j % 2 == 0 ? n4 : n3);
					if (b.b[i][j] != now_v) now_s2++;
				}
				if (now_s1 < now_s2) {
					now_s += now_s1;
					for (int j = 0; j < m; j++) now.b[i][j] = (j % 2 == 0 ? n3 : n4);
				} else {
					now_s += now_s2;
					for (int j = 0; j < m; j++) now.b[i][j] = (j % 2 == 0 ? n4 : n3);
				}
			}
			if (now_s < best_res) {
				best_res = now_s;
				best = now;
			}
		}
	}
}

void solve_2(int n, int m) {
	int calc_odd[m][4], calc_even[m][4];
	int odd = n / 2, even = n / 2;
	if (n % 2 == 0) even++;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			calc_odd[i][j] = calc_even[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0) {
				calc_even[j][b.b[i][j]]++;
			} else {
				calc_odd[j][b.b[i][j]]++;
			}
		}
	}
	for (int n1 = 0; n1 < 4; n1++) {
		for (int n2 = 0; n2 < 4; n2++) {
			dp[0][n1][n2] = 0;
			for (int i = 1; i <= m; i++) dp[i][n1][n2] = MAX_N;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int n1 = 0; n1 < 4; n1++) {
			for (int n2 = 0; n2 < 4; n2++) {
				if (n1 == n2) continue;
				pair <int, int> rest = get_rest(n1, n2);
				int n3 = rest.first, n4 = rest.second;
				int val1 = n - calc_even[i][n3] - calc_odd[i][n4];
				int val2 = n - calc_even[i][n4] - calc_odd[i][n3];
				if (dp[i + 1][n3][n4] > dp[i][n1][n2] + val1) {
					dp[i + 1][n3][n4] = dp[i][n1][n2] + val1;
					prv[i + 1][n3][n4] = make_pair(n1, n2);
				}
				if (dp[i + 1][n4][n3] > dp[i][n1][n2] + val2) {
					dp[i + 1][n4][n3] = dp[i][n1][n2] + val2;
					prv[i + 1][n4][n3] = make_pair(n1, n2);
				}
			}
		}
	}
	for (int n1 = 0; n1 < 4; n1++) {
		for (int n2 = 0; n2 < 4; n2++) {
			if (dp[m][n1][n2] < best_res) {
				best_res = dp[m][n1][n2];
				board now(n, m);
				int now_i = n1, now_j = n2;
				for (int j = m - 1; j >= 0; j--) {
					now.b[0][j] = now_i;
					now.b[1][j] = now_j;
					int new_i = prv[j + 1][now_i][now_j].first, new_j = prv[j + 1][now_i][now_j].second;
					now_i = new_i;
					now_j = new_j;
				}
				for (int i = 2; i < n; i++) {
					for (int j = 0; j < m; j++) {
						now.b[i][j] = now.b[i - 2][j];
					}
				}
				best = now;
			}
		}
	}
}

int main() {
	init();
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	b = board(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			b.b[i][j] = chr_to_num[c];
		}
	}
	solve_1(n, m);
	solve_2(n, m);
	best.print();
	return 0;
}