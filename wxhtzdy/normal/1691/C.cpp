#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> ones;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				ones.push_back(i);
			}
		}
		if(ones.empty()){
			cout << 0 << "\n";
			continue;
		}
		int needl = ones[0];
		int needr = n - ones.back() - 1;
		if(needl > k && needr <= k){
			ones.back() = n - 1;
		}else if(needl <= k && needr > k){
			ones[0] = 0;
		}else if(needl + needr <= k){
			ones[0] = 0;
			ones.back() = n - 1;
		}else if(needr <= k){
			ones.back() = n - 1;
		}
		s = string(n, '0');
		for(int i : ones) s[i] = '1';
		int ans = 0;
		for(int i = 0; i < n - 1; i++){
			ans += (s[i] - '0') * 10;
			ans += (s[i + 1] - '0');
		}
		cout << ans << "\n";
	}
}