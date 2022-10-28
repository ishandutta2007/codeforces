#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;
vector<int> row[MX + 1], col[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		row[x].push_back(y);
		col[y].push_back(x);
	}
	for (auto& i : row) {
		sort(i.begin(), i.end());
	}
	for (auto& i : col) {
		sort(i.begin(), i.end());
	}

	int dir = 0, r = 1, c = 1;
	long long vstd = 0;
	int mxr = n, mxc = m, mnr = 2, mnc = 1;
	while (true) {
		if (dir == 0) {
			int dest = mxc;
			for (auto i : row[r]) {
				if (i - 1 > mxc) break;
				if (i - 1 >= c) {
					dest = i - 1;
					break;
				}
			}
			if (dest <= c && vstd) break;
			vstd += dest - c;
			c = dest;
			mxc = c - 1;
		} else if (dir == 1) {
			int dest = mxr;
			for (auto i : col[c]) {
				if (i - 1 > mxr) break;
				if (i - 1 >= r) {
					dest = i - 1;
					break;
				}
			}
			if (dest <= r) break;
			vstd += dest - r;
			r = dest;
			mxr = r - 1;
		} else if (dir == 2) {
			int dest = mnc;
			for (auto i : row[r]) {
				if (i + 1 > c) break;
				if (i + 1 >= mnc) {
					dest = i + 1;
				}
			}
			if (dest >= c) break;
	   		vstd += c - dest;
			c = dest;
			mnc = c + 1;		
		} else {
			int dest = mnr;
			for (auto i : col[c]) {
				if (i + 1 > r) break;
				if (i + 1 >= mnr) {
					dest = i + 1;
				}
			}
			if (dest >= r) break;
	   		vstd += r - dest;
			r = dest;
			mnr = r + 1;		
		}
		(dir += 1) %= 4;
	}
	cout << ((long long)m * n - k == vstd + 1 ? "Yes" : "No") << '\n';
}