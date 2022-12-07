#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 2e5 + 2020;
const int M = 1 << 17;

int n, k;
int cnt[N][17];
int have[M];
vector<int> masks[17], all[N];
char s[N];

void add(int mask) {
	rep(bit, 0, k)
		if (!(mask >> bit & 1)) {
			masks[bit].push_back(mask + (1 << bit));
		}
}

bool solve(int x) {
	memset(have, 0, sizeof have);
	rep(i, 0, k)
		masks[i].clear();
	rep(i, 0, n + 1)
		all[i].clear();
	all[0].push_back(0);

	rep(i, x, n + 1) {
		for (auto mask : all[i - x])
			add(mask);
		int d = 0;
		rep(j, 0, k) 
			d += (cnt[i][j] - cnt[i - x][j] > 0);
		rep(j, 0, k)
			if (d == 0 || (d == 1 && cnt[i][j] - cnt[i - x][j] > 0)) {
				for (auto mask : masks[j]) {
					if (!have[mask]) {
						if (mask == (1 << k) - 1)
							return 1;
						have[mask] = 1;
						all[i].push_back(mask);
					}
				}
				masks[j].clear();
			}
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> k >> s + 1;

	rep(i, 1, n + 1) 
		rep(j, 0, k)
			cnt[i][j] = cnt[i - 1][j] + (s[i] - 'a' == j);

	//solve(1);
	//return 0;

	int l = 0, r = n;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (solve(m))
			l = m;
		else
			r = m - 1;
	}
	cout << l << endl;
	return 0;
}