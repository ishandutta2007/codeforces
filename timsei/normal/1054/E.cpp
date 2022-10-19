#include <bits/stdc++.h>
using namespace std;

const int N = 305;

string s[N][N], t[N][N];
deque <int> S[N][N];
int n, m, x, y;

struct Opt {
	int x1, y1, x2, y2;
};

vector < Opt > get(int x) {
	vector < Opt > ans;
	ans.clear();
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(x) reverse(s[i][j].begin(), s[i][j].end());
			S[i][j].clear();
			for(int k = 0; k < (int)s[i][j].size(); ++ k)
			S[i][j].push_back(s[i][j][k] - '0');
		}
	}
	for(int i = 2; i < n; ++ i) {
		for(int j = 2; j < m; ++ j) {
			while(S[i][j].size()) {
				int now = S[i][j].back();
				S[i][j].pop_back();
				if(now) S[n][j].push_front(1), ans.push_back((Opt) {i, j, n, j});
				else S[1][j].push_front(0), ans.push_back((Opt){i, j, 1, j});
			}
		}
	}
	while(S[1][1].size()) {
		int now = S[1][1].back();
		S[1][1].pop_back();
		if(now) S[n][1].push_front(1), ans.push_back((Opt) {1, 1, n, 1});
		else S[1][m].push_front(0), ans.push_back((Opt){1, 1, 1, m});
	}
	while(S[n][m].size()) {
		int now = S[n][m].back();
		S[n][m].pop_back();
		if(now) S[n][1].push_front(1), ans.push_back((Opt){n, m, n, 1});
		else S[1][m].push_front(0), ans.push_back((Opt){n, m, 1, m});
	}
	int j = 1;
	for(int i = 2; i < n; ++ i) {
		while(S[i][j].size()) {
			int now = S[i][j].back();
			S[i][j].pop_back();
			if(now) S[n][j].push_front(1), ans.push_back((Opt) {i, j, n, j});
			else S[1][j].push_front(0), ans.push_back((Opt){i, j, 1, j});
		}		
	}
	j = m;
	for(int i = 2; i < n; ++ i) {
		while(S[i][j].size()) {
			int now = S[i][j].back();
			S[i][j].pop_back();
			if(now) S[n][j].push_front(1), ans.push_back((Opt) {i, j, n, j});
			else S[1][j].push_front(0), ans.push_back((Opt){i, j, 1, j});
		}		
	}	
	for(int i = 1; i <= m; ++ i) {
		while(S[1][i].size()) {
			int now = S[1][i].back();
			if(!now) {
				if(i == 1) break;
			}
			S[1][i].pop_back();
			if(now) S[n][i].push_front(1), ans.push_back((Opt){1, i, n, i});
			else S[1][1].push_front(0), ans.push_back((Opt){1, i, 1, 1});
		}
		while(S[n][i].size()) {
			int now = S[n][i].back();
			if(now) {
				if(i == m) break;
			}
			S[n][i].pop_back();
			if(now) {
				S[n][m].push_front(1), ans.push_back((Opt){n, i, n, m});
			}
			else S[1][i].push_front(0), ans.push_back((Opt){n, i, 1, i});
		}
		while(S[1][i].size()) {
			int now = S[1][i].back();
			if(!now) {
				if(i == 1) break;
			}
			S[1][i].pop_back();
			if(now) S[n][i].push_front(1), ans.push_back((Opt){1, i, n, i});
			else S[1][1].push_front(0), ans.push_back((Opt){1, i, 1, 1});
		}
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j)
		cin >> s[i][j];
	}
	vector < Opt > A = get(0);
	//cerr << A.size() << endl;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j)
		cin >> s[i][j];
	}
	vector < Opt > B = get(1);
	cout << A.size() + B.size() << endl;
	for(int i = 0; i < (int) A.size(); ++ i) {
		printf("%d %d %d %d\n", A[i].x1, A[i].y1, A[i].x2, A[i].y2);
	}
	reverse(B.begin(), B.end());
	for(int i = 0; i < (int) B.size(); ++ i) {
		printf("%d %d %d %d\n", B[i].x2, B[i].y2, B[i].x1, B[i].y1);
	}
}