#include<bits/stdc++.h>
using namespace std;
const int N(111);
int a[N], b[N], dp[N * N][N];
int main() {
	int n;
	cin >> n;
	int sum(0);
	for(int i(0); i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	vector<pair<int, int> > vec;
	for(int j(0); j < n; j++) {
		cin >> b[j];
		vec.push_back(make_pair(b[j], a[j]));
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	int cur(0);
	int ans1;
	for(int i(0); i < (int)vec.size(); i++) {
		cur += vec[i].first;
		if(cur >= sum) {
			ans1 = i + 1;
			break;
		}
	}
	memset(dp, 0x80, sizeof(dp));
	dp[0][0] = 0;
	int sumb(0);
	for(int i(0); i < n; i++) {
		for(int j(sumb); j >= 0; j--) {
			for(int k(min(i, ans1)); k >= 0; k--) {
				dp[j + b[i]][k + 1] = max(dp[j + b[i]][k + 1], dp[j][k] + a[i]);
			}
		}
		sumb += b[i];
	}
	int ans2(1e9);
	for(int j(sum); j <= sumb; j++) {
		ans2 = min(ans2, sum - dp[j][ans1]);
	}
	cout << ans1 << ' ' << ans2 << endl;
}