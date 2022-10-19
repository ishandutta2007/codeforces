#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

#define int long long

int n, m, S[N];

struct NODE {
	int p, c;
	friend bool operator < (NODE a, NODE b) {
		return a.c < b.c;
	}
	void input(void) {
		cin >> p >> c;
	}
}T[N];

vector <NODE> who[N], E;

int dp[N][N];

main(void) {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) T[i].input(), ++ S[T[i].p], who[T[i].p].push_back(T[i]);
	for(int i = 1; i <= m; ++ i) sort(who[i].begin(), who[i].end());
	int ans = 1e18;
	for(int i = S[1]; i <= n; ++ i) {
		int now = i - S[1];
		bool ok = 1;
		int res = 0;
		E.clear();
		for(int j = 2; j <= m && ok; ++ j) {
			if(i + now <= who[j].size()) {
				ok  = 0;
				break;
			}
			else {
				if(who[j].size() < i) {
					for(int k = 0; k < (int) who[j].size(); ++ k) E.push_back(who[j][k]);
					continue;
				}
				int it = (who[j].size() - i) + 1;
				for(int k = 0; k < it; ++ k) res += who[j][k].c;
				now -= it;
				for(int k = it; k < (int) who[j].size(); ++ k) E.push_back(who[j][k]);
			}
		}
		if(now) {
			if(E.size() < now) {
				ok = 0;
				continue;
			}
			sort(E.begin(), E.end());
			for(int i = 0; i < now; ++ i) res += E[i].c;
		}
		if(ok)ans = min(ans, res);
	}
	cout << ans << endl;
}