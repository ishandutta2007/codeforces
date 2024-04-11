#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		pair<string, int> ans=make_pair(s, 1);
		for(int i=2; i<=n; ++i) {
			string t=s.substr(i-1), u=s.substr(0, i-1);
			if((n-(i-1))%2==1)
				reverse(u.begin(), u.end());
			ans=min(make_pair(t+u, i), ans);
		}
		cout << ans.first << "\n" << ans.second << "\n";
	}
}