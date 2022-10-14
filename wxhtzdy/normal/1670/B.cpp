#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
		vector<int> sp(26);
		for(int i = 0; i < k; i++){
			char c; cin >> c;
			sp[c - 'a'] = 1;
		}
		int ans = 0, lst = 0;
		for(int i = 0; i < n; i++){
			if(sp[s[i] - 'a']){
				ans = max(ans, i - lst);
				lst = i;
			}
		}
		cout << ans << "\n";
	}
}