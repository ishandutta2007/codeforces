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
	int N, M;
	cin >> N >> M;
	vector<string> V(N);
	for(int i = 0; i < N; i++) cin >> V[i];
	vector< vector<char> > S(N, vector<char>(M, 1));
	for(int i = 0; i < N; i++) {
		int l = M, r = -1, cnt = 0;
		for(int j = 0; j < M; j++) if(V[i][j] == '#') {
			r = max(r, j);
			l = min(l, j);
			cnt++;
		}
		if(cnt != 0 && cnt != r-l+1) {
			cout << "-1\n";
			return 0;
		}
		if(cnt)
			for(int j = 0; j < M; j++) if(V[i][j] == '.') S[i][j] = 0;
	}
	for(int i = 0; i < M; i++) {
		int l = N, r = -1, cnt = 0;
		for(int j = 0; j < N; j++) if(V[j][i] == '#') {
			r = max(r, j);
			l = min(l, j);
			cnt++;
		}
		if(cnt != 0 && cnt != r-l+1) {
			cout << "-1\n";
			return 0;
		}
		if(cnt)
			for(int j = 0; j < N; j++) if(V[j][i] == '.') S[j][i] = 0;
	}
	for(int i = 0; i < N; i++) {
		bool has_S = false;
		for(int j = 0; j < M; j++) if(S[i][j]) has_S = true;
		if(!has_S) {
			cout << "-1\n";
			return 0;
		}
	}
	for(int i = 0; i < M; i++) {
		bool has_S = false;
		for(int j = 0; j < N; j++) if(S[j][i]) has_S = true;
		if(!has_S) {
			cout << "-1\n";
			return 0;
		}
	}
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};
	vector< vector<char> > vis(N, vector<char>(M, 0));
	queue< pair<int, int> > q;
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(vis[i][j] || V[i][j] == '.') continue;
		q.push({i, j});
		vis[i][j] = 1;
		while(!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			for(int k = 0; k < 4; k++) {
				int x = p.ff+dx[k], y = p.ss+dy[k];
				if(x < 0 || y < 0 || x >= N || y >= M) continue;
				if(V[x][y] == '#' && !vis[x][y]) {
					vis[x][y] = 1;
					q.push({x, y});
				}
			}
		}
		ans++;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing