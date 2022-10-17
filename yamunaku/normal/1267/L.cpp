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
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

void solve() {
	int h, w, k; cin >> h >> w >> k;
	string s; cin >> s;
	sort(s.begin(), s.end());
	vector<string> a(h);
	rep(i, h) {
		a[i].resize(w,'?');
	}
	int tmp = 0;
	int le = 0;
	rep(j, w){
		Rep(i, le, k) {
			a[i][j] = s[tmp];
			tmp++;
		}
		while (le < k - 1 && a[le][j] < a[k - 1][j])le++;
	}
	rep(i, h)rep(j, w)if (a[i][j] == '?') {
		a[i][j] = s[tmp]; tmp++;
	}
	sort(a.begin(), a.end());
	rep(i, h) {
		cout << a[i] << endl;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}