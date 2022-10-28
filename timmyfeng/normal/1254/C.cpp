#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1000 + 1;

int n, dir[MX];
ll dist[MX];

ll qry_dist(int a, int b, int c) {
	cout << 1 << " " << a << " " << b << " " << c << endl;
	ll res;
	cin >> res;
	return res;
}

bool qry_side(int a, int b, int c) {
	cout << 2 << " " << a << " " << b << " " << c << endl;
	int res;
	cin >> res;
	return res == 1;
}

bool cmp(int a, int b) {
	return dist[a] < dist[b];
}

void print(int d, bool rev) {
	vector<int> pts;
	for (int i = 1; i <= n; ++i) {
		if (dir[i] == d) {
			pts.push_back(i);
		}
	}

	if (rev) {
		sort(pts.rbegin(), pts.rend(), cmp);
	} else {
		sort(pts.begin(), pts.end(), cmp);
	}

	for (auto& i : pts) {
		cout << " " << i;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dir[2] = 1;
	for (int i = 3; i <= n; ++i) {
		dir[i] = qry_side(1, 2, i);
	}

	for (int i = 3; i <= n; ++i) {
		dist[i] = qry_dist(1, 2, i);
	}

	int a = 0;
	int b = 0;
	for (int i = 1; i <= n; ++i) {
		if (dir[i] && dist[i] >= dist[a]) {
			a = i;
		} else if (!dir[i] && dist[i] >= dist[b]) {
			b = i;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (i == a || i == b) {
			dir[i] = -1;
		} else {
			dir[i] += qry_side(a, b, i) ? 2 : 0;
		}
	}

	cout << 0;
	print(0, false);
	cout << " " << b;
	print(2, true);
	print(3, false);
	cout << " " << a;
	print(1, true);
	cout << endl;
}