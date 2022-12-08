#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>

using namespace std;

using P = pair<int, int>;
#define rep(i, n) for(int i=0;i<n;++i)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define stop char nyaa;cin>>nyaa;

int a[100][100];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}
	int ans = n+1;
	int chk = n;
	rep(i, n - 1) {
		vector<int> d(m);
		int sum = 0;
		rep(j, m) {
			d[j] = a[j][i] - a[j][n - 1];
			sum += d[j];
		}
		sort(d.begin(), d.end());
		int tmp = 0;
		rep(j, m) {
			if (sum >= 0)break;
			sum -= d[j];
			tmp++;
		}
		if (ans > tmp) {
			ans = tmp; chk = i;
		}
	}
	vector<P> d(m); int sum = 0;
	rep(j, m) {
		
		d[j] = { a[j][chk] - a[j][n - 1],j+1 };
		sum += d[j].first;
	}
	sort(d.begin(), d.end());
	vector<int> ers;
	rep(j, m) {
		if (sum >= 0)break;
		sum -= d[j].first; ers.push_back(d[j].second);
	}
	cout << ers.size() << endl;
	rep(i, ers.size()) {
		if (i > 0)cout << " ";
		cout << ers[i];
	}
	cout << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}