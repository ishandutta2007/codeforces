#include <bits/stdc++.h>
using namespace std;
#define int long long

string xx = "UD";

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		string s; cin >> s;

		int ind = 0;
		for(char i : s) if(i == xx[ind]) ind = 1;
		string res;

		for(int i=0; i<n; ++i){
			if(s[i] == 'L') res.push_back('L');
			else if(s[i] == 'R') res.push_back('R');
			else res.push_back(xx[ind]);
		}

		cout << res << '\n';
	}	
}