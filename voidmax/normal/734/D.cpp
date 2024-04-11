#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;

const int MAXN = 1e5;
typedef pair <long long, long long> point;

int n;
point a;
int dir_all_x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dir_all_y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
set <pair <long long, char>> que[8];

int main() {
	ios::sync_with_stdio(0);
	//freopen("input.in", "r", stdin);
	cin >> n >> a.x >> a.y;
	for (int i = 0; i < n; ++i) {
		char f;
		point b;
		cin >> f >> b.x >> b.y;
		point c = {a.x - b.x, a.y - b.y};
		for (int j = 0; j < 8; ++j) {
			long long d = 0;
			if (dir_all_x[j])
				d = c.x / dir_all_x[j];
			if (dir_all_y[j])
				d = c.y / dir_all_y[j];
			if (d < 0) continue;
			if (dir_all_x[j] * d == c.x && dir_all_y[j] * d == c.y) {
				que[j].insert({d, f});
			}
		}		
	}
	for (int j = 0; j < 8; ++j) {
		if (que[j].size()) {
			if (((*que[j].begin()).y == 'Q') || ((*que[j].begin()).y == 'B' && (j % 2 == 0)) || ((*que[j].begin()).y == 'R' && (j % 2 == 1))) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}