#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 101;

int n, m, e[N][N], t[N][N], g[N][N];
char s[N][N];
vector <vector<pair<int, int>>> res;

bool done(int i, int j) {
	int cnt = 0;
	for (int a = i; a < i + 2; ++a)
		for (int b = j; b < j + 2; ++b)
			cnt += t[a][b];
	return !cnt;
}

int w[] = {0, 3, 2, 1, 4};

void solve(int i, int j) {
	int cnt = 0;
	for (int a = i; a < i + 2; ++a)
		for (int b = j; b < j + 2; ++b)
			cnt += g[a][b] = t[a][b];
	vector <vector<pair<int, int>>> cur;
	vector <int> ran(4);
	iota(ran.begin(), ran.end(), 0);
	while (true) {
		while (!done(i, j)) {
			random_shuffle(ran.begin(), ran.end());
			vector <pair<int, int>> now;
			for (int g = 0; g < 3; ++g) {
				int x = i + (ran[g] & 1), y = j + ran[g] / 2;
				now.push_back({x, y});
				t[x][y] ^= 1;
			}
			cur.push_back(now);
		}
		if((int)cur.size() <= w[cnt]) {
			for (auto x : cur)
				res.push_back(x);
			return;
		}		
		cur.clear();		
		for (int a = i; a < i + 2; ++a)
			for (int b = j; b < j + 2; ++b)
				t[a][b] = g[a][b];
		//~ cout << g[i][j] << " " << g[i+1][j] << " " << g[i][j+1] << " " << g[i+1][j+1] << endl;
	}
}

void solve() {
	res.clear();
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for(int j = 0; j < m; ++j)
			e[i][j] = t[i][j] = s[i][j] - '0';
	}
	while (true) {
		for (int i = 0; i + 1 < n; i += 2)
			for (int j = 0; j + 1 < m; j += 2)
				solve(i, j);
		for (int i = 0; i < n - 1; ++i)
			for (int j = 0; j < m - 1; ++j)
				solve(i, j);
		if ((int)res.size() <= 3* n * m) break;
		res.clear();
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				t[i][j] = e[i][j];
	}	
	printf("%d\n", (int)res.size());
	for (auto x : res) {
		for (auto y : x)
			printf("%d %d ", y.first + 1, y.second + 1);
		printf("\n");
	}
}

int main() {	
	srand(time(0));
	int cases;
	scanf("%d", &cases);
	while(cases--)
		solve();
	return 0;
}