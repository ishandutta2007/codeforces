#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int n, k, A[N][N], dis[N][N];
char s[N][N];

bool cmp(pair <int, int> A, pair <int, int> B) {
	return s[A.first][A.second] < s[B.first][B.second];
}

bool vis[N][N];

pair <int, int> S[N], B[N];

void solve(vector < pair <int, int> > who) {
	int tot = who.size();
	for(int i = 0; i < (int) who.size(); ++ i) S[i + 1] = who[i]; 
	while(tot) {
		int cnt = 0;
		for(int i = 1;  i <= tot; ++ i) {
			int x = S[i].first, y = S[i].second;
			if(!vis[x + 1][y]) B[++ cnt] = make_pair(x + 1, y), vis[x + 1][y] = 1;
			if(!vis[x][y + 1]) B[++ cnt] = make_pair(x, y + 1), vis[x][y + 1] = 1;
		}
		sort(B + 1, B + cnt + 1, cmp);
		if(!cnt) return;
		putchar(s[B[1].first][B[1].second]);
		tot = 0;
		for(int i = 1; i <= cnt; ++ i) if(s[B[i].first][B[i].second] == s[B[1].first][B[1].second])
		S[++ tot] = B[i];
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", s[i] + 1);
		vis[0][i] = vis[i][0] = vis[i][n + 1] = vis[n + 1][i] = 1;
	}
	vis[n + 1][n + 1] = 1;
	dis[1][1] = (s[1][1] != 'a');
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			if(i + j == 2) continue;
			dis[i][j] = 1e9;
			if(i != 1) dis[i][j] = min(dis[i][j], dis[i - 1][j]);
			if(j != 1) dis[i][j] = min(dis[i][j], dis[i][j - 1]);
			dis[i][j] += (s[i][j] != 'a');
		}
	}
	// 2 * n - 1
	if(dis[n][n] <= k) {
		for(int i = 1; i <= 2 * n - 1; ++ i) printf("a");
		puts("");
		return 0;
	}
	for(int s = 2 * n; s >= 2; -- s) {
		vector < pair < int, int > > who;
		who.clear();
		for(int i = 1; i <= n; ++ i) {
			int j = s - i;
			if(j > n || j <= 0) continue;
			if(dis[i][j] <= k) who.push_back(make_pair(i, j));
		}
		if(who.size()) {
			for(int p = 1; p < s; ++ p) putchar('a');
			//cerr << endl <<"HERE" << endl;
			solve(who);
			return 0;
		}
	}
	putchar(s[1][1]);
	vector < pair <int, int> > who;
	who.clear();
	who.push_back(make_pair(1, 1));
	solve(who);
}