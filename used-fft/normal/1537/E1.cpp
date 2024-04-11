#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

const int INF = 1e18;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	string res;
	for(int i=0; i<n; ++i){
		int curr = 0;
		string c;
		for(int j=0; j<k; ++j){
			c += s[curr];
			++curr;
			if(curr > i) curr = 0;
		}
		if(res.empty()) res = c;
		res = min(res, c);
	}
	cout << res nl;
}