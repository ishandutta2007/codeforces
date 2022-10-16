#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using ld = long double;

const int INF = 1e8;
const ll LINF = 1e17;

const int N = 5006;

int n, res[N], k[4], c[4];
string a, b;
vector<int> cnt[4];

#define ID(i) ((a[(i)] == '1' ? 1 : 0)+(b[(i)] == '1' ? 2 : 0))

bool check() {
	for(int i = 0; i < 4; ++i)
		if(k[i] < 0 || k[i] > c[i]) return false;
	return true;
}

bool solve() {
	if(c[1] <= n/2 && c[2] <= n/2) {
		int m = c[2] + c[3];
		for(k[3] = 0; k[3] <= c[3]; ++k[3]) 
		for(k[2] = 0; k[2] <= c[2]; ++k[2]) {
			k[1] = m - 2*k[3] - k[2];
			k[0] = n/2 - k[1] - k[2] - k[3];
			if(check()) return true;
		}
		return false;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i)
		cnt[ID(i)].push_back(i);
	for(int i = 0; i < 4; ++i)
		c[i] = cnt[i].size();

	if(solve()) {
		for(int i = 0; i < 4; ++i)
		for(int j = 0; j < k[i]; ++j)
			cout << cnt[i][j] + 1 << ' ';
	}
	else cout << -1;
}