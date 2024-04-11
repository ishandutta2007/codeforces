#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, m, A[N][N], X[N * N], Y[N * N], B[N][N];
bool vis[N * N];

int calc(int x, int y) {
	return (x - 1) * m + y;
}

int dx[] = {0, 0, 1};
int dy[] = {1, -1, 0};

vector < vector <int> > ans;

int P[8];

void doit() {
	vector <int> now;
	now.clear();
	now.push_back(P[1]); now.push_back(P[2]); now.push_back(P[5]); now.push_back(P[4]);
	ans.push_back(now);
	now.clear();
	now.push_back(P[1]); now.push_back(P[3]); now.push_back(P[6]); now.push_back(P[2]);
	ans.push_back(now);
	now.clear();
	now.push_back(P[1]); now.push_back(P[2]); now.push_back(P[4]); now.push_back(P[5]); now.push_back(P[6]); now.push_back(P[3]);
	ans.push_back(now);
	now.clear();
}

void Swap(int x, int y, int dir) {
 	if(dir == 1) {
 		//(x, y) -> (x, y - 1)
		if(x + 1 <= n) {
			vector <int> now;
			now.clear();
			now.push_back(A[x][y]);
			now.push_back(A[x][y - 1]);
			now.push_back(A[x + 1][y - 1]);
			now.push_back(A[x + 1][y]);
			ans.push_back(now);
			B[x][y - 1] = A[x][y], 
			B[x + 1][y - 1] = A[x][y - 1], 
			B[x + 1][y] = A[x + 1][y - 1], 
			B[x][y] = A[x + 1][y];
			A[x][y] = B[x][y];
			A[x][y - 1] = B[x][y - 1];
			A[x + 1][y] = B[x + 1][y];
			A[x + 1][y - 1] = B[x + 1][y - 1];
			return;
		}
 		Swap(x, y - 1, 0);
 		return;
	}
	if(!dir) {
		if(x + 1 <= n) {
			vector <int> now;
			now.clear();
			now.push_back(A[x][y]);
			now.push_back(A[x][y + 1]);
			now.push_back(A[x + 1][y + 1]);
			now.push_back(A[x + 1][y]);
			ans.push_back(now);
			B[x][y + 1] = A[x][y], 
			B[x + 1][y + 1] = A[x][y + 1], 
			B[x + 1][y] = A[x + 1][y + 1], 
			B[x][y] = A[x + 1][y];
			A[x][y] = B[x][y];
			A[x][y + 1] = B[x][y + 1];
			A[x + 1][y] = B[x + 1][y];
			A[x + 1][y + 1] = B[x + 1][y + 1];
			return;			
		}
		if(y + 2 <= m) {
			int who = -1;
			if(x + 1 <= n) who = 1;
			P[1] = A[x][y], P[2] = A[x][y + 1], P[3] = A[x][y + 2];
			P[4] = A[x + who][y], P[5] = A[x + who][y + 1], P[6] = A[x + who][y + 2];
		}
		else {
			int who = -1;
			if(x + 1 <= n) who = 1;
			P[1] = A[x][y + 1], P[2] = A[x][y], P[3] = A[x][y - 1];
			P[4] = A[x + who][y + 1], P[5] = A[x + who][y], P[6] = A[x + who][y - 1];
		}
		doit();
		swap(A[x][y], A[x][y + 1]);
	}
	else {
		if(y + 1 <= m) {
			vector <int> now;
			now.clear();
			now.push_back(A[x + 1][y]);
			now.push_back(A[x][y]);
			now.push_back(A[x][y + 1]);
			now.push_back(A[x + 1][y + 1]);
			ans.push_back(now);
			B[x][y] = A[x + 1][y];
			B[x][y + 1] = A[x][y];
			B[x + 1][y + 1] = A[x][y + 1];
			B[x + 1][y] = A[x + 1][y + 1];
			A[x][y] = B[x][y];
			A[x + 1][y] = B[x + 1][y];
			A[x][y + 1] = B[x][y + 1];
			A[x + 1][y + 1] = B[x + 1][y + 1];
			return;			
		}
		if(x + 2 <= n) {
			int who = -1;
			if(y + 1 <= m) who = 1;
			P[1] = A[x][y], P[2] = A[x + 1][y], P[3] = A[x + 2][y];
			P[4] = A[x][y + who], P[5] = A[x + 1][y + who], P[6] = A[x + 2][y + who];
		}
		else {
			int who = -1;
			if(y + 1 <= m) who = 1;
			P[1] = A[x + 1][y], P[2] = A[x][y], P[3] = A[x - 1][y];
			P[4] = A[x + 1][y + who], P[5] = A[x][y + who], P[6] = A[x - 1][y + who]; 
		}
		doit();
		swap(A[x][y], A[x + 1][y]);
	}
}

void move(int x1, int y1, int x2, int y2) {
	while(y1 < y2) {
		Swap(x1, y1, 0);
		++ y1;
	}
	while(y1 > y2) {
		Swap(x1, y1, 1);
		-- y1;
	}
	while(x1 > x2) {
		Swap(x1 - 1, y1, 2);
		-- x1;
	}
	while(x1 < x2) {
		throw;
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j)
		scanf("%d", &A[i][j]);
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(calc(i, j) == A[i][j]) {
				continue;
			}
			else {
				int X, Y;
				for(int k = 1; k <= n; ++ k) {
					for(int l = 1; l <= m; ++ l) {
						if(A[k][l] == calc(i, j)) {
							X = k, Y = l;
							break;
						}
					}
				}
				//cerr << X <<" " << Y <<" " << i <<" " << j << endl;
				move(X, Y, i, j);
			}
		}
	}
	/*for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) cout << A[i][j] <<" ";
		puts("");
	}
	puts("");*/
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < (int) ans.size(); ++ i) {
		printf("%d ", (int)ans[i].size());
		for(int j = 0; j < (int) ans[i].size(); ++ j) printf("%d ", ans[i][j]);
		puts("");
	}
}