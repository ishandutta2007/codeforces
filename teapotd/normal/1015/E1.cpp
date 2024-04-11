#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

constexpr int MAX_N = 1001;
constexpr int DIRS = 4;

constexpr Pii dirs[] = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int n, m;
char board[MAX_N][MAX_N];
int rays[4][MAX_N][MAX_N];

int vert[MAX_N][MAX_N], hor[MAX_N][MAX_N];

vector<pair<Pii, int>> stars;

void computeRays(int dir) {
	int dx = dirs[dir].x, dy = dirs[dir].y;
	auto& dp = rays[dir];

	rep(i, 0, n) rep(j, 0, m) {
		dp[i][j] = (board[i][j] == '*');
	}

	int startX = (dx < 0 ? 0 : n-1);
	int startY = (dy < 0 ? 0 : m-1);
	int stepX = (dx < 0 ? 1 : -1);
	int stepY = (dy < 0 ? 1 : -1);

	for (int i = startX; i >= 0 && i < n; i += stepX) {
		for (int j = startY; j >= 0 && j < m; j += stepY) {
			int a = i+dx, b = j+dy;
			if (dp[i][j] && a >= 0 && b >= 0 && a < n && b < m) {
				dp[i][j] = dp[a][b] + 1;
			}
		}
	}
}

void placeStar(int i, int j) {
	int len = INT_MAX;
	each(d, rays) len = min(len, d[i][j]-1);
	if (len <= 0) return;

	stars.pb({ {i+1, j+1}, len });

	vert[i-len][j]++;
	vert[i+len+1][j]--;
	hor[i][j-len]++;
	hor[i][j+len+1]--;
}

void run() {
	cin >> n >> m;
	rep(i, 0, n) cin >> board[i];

	rep(i, 0, DIRS) computeRays(i);
	rep(i, 0, n) rep(j, 0, m) placeStar(i, j);

	rep(i, 0, n) {
		rep(j, 1, m) hor[i][j] += hor[i][j-1];
	}

	rep(j, 0, m) {
		rep(i, 1, n) vert[i][j] += vert[i-1][j];
	}

	rep(i, 0, n) rep(j, 0, m) {
		if (board[i][j] == '*' && vert[i][j] <= 0 && hor[i][j] <= 0) {
			cout << "-1\n";
			return;
		}
	}

	cout << sz(stars) << endl;
	each(s, stars) cout << s.x.x << ' ' << s.x.y << ' ' << s.y << '\n';
	cout << flush;
}