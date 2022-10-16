#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using ld = long double;

const int INF = 1e8;
const ll LINF = 1e17;

const int N = 1001;

int n, m, a[N][N], xh[N], yh[N];
vector<int> xv[N], yv[N];

int get_xv(int i, int j) {
	int l = 0, r = xv[i].size()-1;
	while(l < r) {
		int m = (l+r)/2;
		if(xv[i][m] == a[i][j]) l = r = m;
		if(xv[i][m] < a[i][j]) l = m + 1;
		if(xv[i][m] > a[i][j]) r = m - 1;
	}
	return r+1;
}

int get_yv(int i, int j) {
	int l = 0, r = yv[j].size()-1;
	while(l < r) {
		int m = (l+r)/2;
		if(yv[j][m] == a[i][j]) l = r = m;
		if(yv[j][m] < a[i][j]) l = m + 1;
		if(yv[j][m] > a[i][j]) r = m - 1;
	}
	return r+1;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	}

	for(int i = 0; i < n; ++i) {
		set<int> values;
		for(int j = 0; j < m; ++j) 
			values.insert(a[i][j]);
		xv[i] = vector<int>(values.begin(), values.end());
	}

	for(int i = 0; i < m; ++i) {
		set<int> values;
		for(int j = 0; j  < n; ++j)
			values.insert(a[j][i]);
		yv[i] = vector<int>(values.begin(), values.end());
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			int xx = get_xv(i, j), yy = get_yv(i, j);
			int dx = xx > yy ? xx - yy : 0;
			int dy = xx < yy ? yy - xx : 0;
			cout << max(xv[i].size() + dy, yv[j].size() + dx) << ' ';
		}

		cout << endl;
	}
}