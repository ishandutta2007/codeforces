#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 2e9;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		string a, b; cin >> a >> b;

		int res = INF;

		// even
		array<int, 2> diff = {};

		for(int i=0; i<n; ++i){
			if(a[i] != b[i])
				++diff[a[i]-'0'];
		}

		if(diff[0] == diff[1]) res = min(res, diff[0] * 2);

		//odd
		for(int i=0; i<n; ++i){
			b[i] = "10"[b[i]-'0'];
		}

		diff = {0, 0};
		for(int i=0; i<n; ++i){
			if(a[i] != b[i])
				++diff[a[i]-'0'];
		}

		if(diff[0] +1 == diff[1]) res = min(res, diff[0] + diff[1]);

		if(res == INF) res = -1;

		cout << res << '\n';
	}
}