#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define sz(x) int(x.size())
const ll MOD = 1e9+7;
const ll M=1000;
ll A[M];
const double eps = 1e-9;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int level = 0;
	int n, t;
	// n = 4;
	// t = 8;
	cin >> n >> t;
	vector<vector<double>> levels(n);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			levels[i].push_back(0);
		}
	}
	while(t--) {
		levels[0][0]++;
		for(int i = 0; i < n - 1; i++) {
			for(int j = 0; j <= i; j++) {
				double k = max(levels[i][j] - 1, 0.0);
				levels[i][j] = min(levels[i][j], 1.0);
				levels[i+1][j] += k / 2;
				levels[i+1][j+1] += k / 2;
			}
		}
	}
	int ans=0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			if(levels[i][j] >= 1) {
				++ans;
				
			}
		}
		cout << "\n";
	}
	cout << ans << "\n";
}