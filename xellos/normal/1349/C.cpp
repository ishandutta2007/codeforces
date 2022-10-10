// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<string> S(N);
	for(int i = 0; i < N; i++) cin >> S[i];

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	vector< vector<int> > comp(N, vector<int>(M, -1));
	vector<int> comp_sz;
	queue< pair<int, int> > q;
	int C = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(comp[i][j] != -1) continue;
		comp[i][j] = C;
		comp_sz.push_back(0);
		q.push({i, j});
		while(!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			comp_sz[C]++;
			for(int k = 0; k < 4; k++) {
				if(x+dx[k] < 0 || y+dy[k] < 0 || x+dx[k] >= N || y+dy[k] >= M) continue;
				if(comp[x+dx[k]][y+dy[k]] != -1) continue;
				if(S[x+dx[k]][y+dy[k]] != S[x][y]) continue;
				comp[x+dx[k]][y+dy[k]] = C;
				q.push({x+dx[k], y+dy[k]});
			}
		}
		C++;
	}

	vector< vector<int> > D(N, vector<int>(M, -1));
	vector< vector<int> > col_fin_comp(N, vector<int>(M));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(comp_sz[comp[i][j]] == 1) continue;
		D[i][j] = 0;
		col_fin_comp[i][j] = S[i][j]-'0';
		q.push({i, j});
	}
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int k = 0; k < 4; k++) {
			if(x+dx[k] < 0 || y+dy[k] < 0 || x+dx[k] >= N || y+dy[k] >= M) continue;
			if(D[x+dx[k]][y+dy[k]] != -1) continue;
			D[x+dx[k]][y+dy[k]] = D[x][y]+1;
			col_fin_comp[x+dx[k]][y+dy[k]] = col_fin_comp[x][y];
			q.push({x+dx[k], y+dy[k]});
		}
	}

	for(int i = 0; i < Q; i++) {
		int r, c;
		cat p;
		cin >> r >> c >> p;
		r--, c--;
		if(D[r][c] == -1 || p < D[r][c]) cout << S[r][c] << "\n";
		else cout << (col_fin_comp[r][c]+p)%2 << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing