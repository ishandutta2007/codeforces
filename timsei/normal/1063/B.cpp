#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int L[N][N], R[N][N], n, m, x, y, r, c;
char s[N][N];

deque < pair <int, int> > q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int D[] = {0, 0, 0, 0};
bool K[N][N];

#define A L

void BFS(int x, int y) {
	while(!q.empty()) q.pop_front();
	q.push_front(make_pair(x, y));
	memset(K, 0, sizeof(K));
	memset(A, -1, sizeof(A));
	A[x][y] = 0;
	while(!q.empty()) {
		pair <int, int> ind = q.front();
		q.pop_front();
		int x = ind.first, y = ind.second, X, Y;
		if(K[x][y]) continue;
		K[x][y] = 1;
		for(int i = 0; i < 4; ++ i) {
			X = x + dx[i], Y = y + dy[i];
			if(X == 0 || Y == 0 || X == n + 1 || Y == m + 1) continue;
			if(K[X][Y] || s[X][Y] == '*') continue;
			int val = D[i];
			if(val + A[x][y] < A[X][Y] || A[X][Y] == -1) {
				A[X][Y] = val + A[x][y];
				if(val == 0) q.push_front(make_pair(X, Y));
				else q.push_back(make_pair(X, Y));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> r >> c;
	cin >> x >> y;
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", s[i] + 1);
	}
	D[1] = 1;
	BFS(r, c);
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(K[i][j]) {
				int l = L[i][j], r = (j - c) + l;
	//cerr << i <<" " << j <<" " << l <<" " << r << " " << x <<" " << y << endl;
				if(l > x || r > y) continue;
				++ cnt;
			}
		}
	}
	cout << cnt << endl;
}