#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int N = 411;
string s[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n; i ++) {
		string t; cin >> t;
		for(char c : t) {
			if(c == 'u')
				s[i] += "oo";
			else if(c == 'h') {
				while(s[i].size() && s[i].back() == 'k')
					s[i].pop_back();
				s[i] += 'h';
			} else
				s[i] += c;
		}
		//cout << s[i] << '\n';
	}
	
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		bool f = 1;
		for(int j = 0; j < i; j ++)
			if(s[i] == s[j]) {
				f = 0;
				break;
			}
		ans += f;
	}
	cout << ans << '\n';
	
	return 0;
}