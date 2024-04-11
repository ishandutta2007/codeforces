#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

struct Level {
	int fast, slow;
	double chance;
};

constexpr int MAX_N = 51;
constexpr int MAX_TIME = MAX_N*100 + 1;

int n, timeLim;
vector<Level> elems;
double dp[MAX_N][MAX_TIME];

double solve(double guess) {
	rep(t, 0, timeLim+1) dp[n][t] = 0;
	rep(t, timeLim+1, MAX_TIME) dp[n][t] = guess;

	for (int i = n-1; i >= 0; i--) {
		auto& e = elems[i];
		rep(t, 0, MAX_TIME-e.slow) {
			dp[i][t] = (dp[i+1][t+e.fast] + e.fast) * e.chance;
			dp[i][t] += (dp[i+1][t+e.slow] + e.slow) * (1-e.chance);
			if (i > 0) dp[i][t] = min(dp[i][t], guess);
		}
	}

	return dp[0][0];
}

int main() {
	cin.sync_with_stdio(0);
	cout << fixed << setprecision(12);

	cin >> n >> timeLim;
	elems.resize(n);

	each(e, elems) {
		cin >> e.fast >> e.slow >> e.chance;
		e.chance /= 100;
	}

	double begin = 0, end = 1e18;

	rep(i, 0, 128) {
		double mid = (begin+end) / 2;
		if (solve(mid) > mid) {
			begin = mid;
		} else {
			end = mid;
		}
	}

	cout << begin << '\n';
	return 0;
}