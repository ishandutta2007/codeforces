#include<bits/stdc++.h>
using namespace std;
const int N(7077);
int LOSS(10), WIN(20), LOOP(0);
int dp[N][2], cnt[N][2];
vector<int> s[2];
int main() {
	int n;
	cin >> n;
	for(int d(0); d < 2; d++) {
		int x;
		scanf("%d", &x);
		for(int i(0); i < x; i++) {
			int y;
			cin >> y;
			s[d].push_back(y);
		}
	}
	dp[0][0] = dp[0][1] = LOSS;
	vector<pair<int, int> > q;
	q.emplace_back(0, 0);
	q.emplace_back(0, 1);
	for(int op(0); op < (int)q.size(); op++) {
		int v(q[op].first), d(q[op].second);
		for(int i : s[d ^ 1]) {
			if(dp[(v + n - i) % n][d ^ 1] == LOOP) {
				if(dp[v][d] == LOSS) {
					dp[(v + n - i) % n][d ^ 1] = WIN;
					q.emplace_back((v + n - i) % n, d ^ 1);
				}else {
					cnt[(v + n - i) % n][d ^ 1]++;
					if(cnt[(v + n - i) % n][d ^ 1] == (int)s[d ^ 1].size()) {
						dp[(v + n - i) % n][d ^ 1] = LOSS;
						q.emplace_back((v + n - i) % n, d ^ 1);
					}
				}
			}
		}
	}
	for(int d(0); d < 2; d++) {
		for(int i(1); i < n; i++) {
			printf("%s%c", dp[i][d] == WIN ? "Win" : dp[i][d] == LOSS ? "Lose" : "Loop", i == n - 1 ? '\n' : ' ');
		}
	}
}