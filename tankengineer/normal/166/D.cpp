#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

vector<pair<int, int> > v;

bool buy(const int i, const int j) {
	return j != -1 && (v[i].second + v[j].second >= 0 && 
		(v[i].first == v[j].first || v[i].first - 1 == v[j].first));
}

const int N = 100005 << 1;
long long dp[N][4];
pair<int, int> fa[N][4], pa[N][4];

void update(const int ti, const int tj, const int oi, const int oj, const int delta, const pair<int, int> tr) {
	if (dp[ti][tj] < dp[oi][oj] + delta) {
		dp[ti][tj] = dp[oi][oj] + delta;
		fa[ti][tj] = make_pair(oi, oj);
		pa[ti][tj] = tr;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<pair<int, int>, int> > tmp;
	for (int i = 0; i < n; ++i) {
		int tc, ts;
		scanf("%d%d", &tc, &ts);
		tmp.push_back(make_pair(make_pair(ts, -tc), i + 1));
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int td, tl;
		scanf("%d%d", &td, &tl);
		++tl;
		tmp.push_back(make_pair(make_pair(tl, td), i + 1));
	}
	for (int i = 0; i < (int)tmp.size(); ++i) {
		v.push_back(tmp[i].first);
	}
	sort(v.begin(), v.end());		
	sort(tmp.begin(), tmp.end());
	int lastshoe = -1, currentshoe = -1;
	for (int i = 0; i < (int) v.size(); ++i) {
		if (v[i].second < 0) {
			lastshoe = currentshoe;
			currentshoe = i;
			for (int j = 0; j < 4; ++j) {
				update(i + 1, j >> 1, i, j, 0, make_pair(0, 0));
			}
		} else {
			for (int j = 0; j < 4; ++j) {
				update(i + 1, j, i, j, 0, make_pair(0, 0));
				if (~j & 1) {
					if (buy(i, lastshoe)) {
						update(i + 1, j | 1, i, j, -v[lastshoe].second, make_pair(tmp[i].second, tmp[lastshoe].second));
					}
				}
				if (~j & 2) {
					if (buy(i, currentshoe)) {
						update(i + 1, j | 2, i, j, -v[currentshoe].second, make_pair(tmp[i].second, tmp[currentshoe].second));
					}
				}
			}
		}
	}
	int ed = v.size(), ansi = 0;
	for (int j = 0; j < 4; ++j) {
		if (dp[ed][j] > dp[ed][ansi]) {
			ansi = j;
		}
	}
	cout << dp[ed][ansi] << endl;
	vector<pair<int, int> > met;
	while (ed) {
		if (pa[ed][ansi].first) {
			met.push_back(pa[ed][ansi]);
		}
		pair<int, int> f = fa[ed][ansi];
		ed = f.first, ansi = f.second;
	}
	printf("%d\n", (int)met.size());
	for (int i = 0; i < (int)met.size(); ++i) {
		printf("%d %d\n", met[i].first, met[i].second);
	}
	return 0;
}