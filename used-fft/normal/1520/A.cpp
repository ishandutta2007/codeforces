#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		string s; cin >> s;
		vector<int> cnt(26);
		bool ok = true;
		for(int i=0; i<n; ++i){
			int j = s[i] - 'A';
			if(cnt[j]){
				if(s[i-1] - 'A' != j) ok = false;
			}else ++cnt[j];
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}

}