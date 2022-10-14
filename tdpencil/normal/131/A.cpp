#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
#define pb push_back
// ll m, k, x, y;

// string s;
ll n, m,k;
const int mxN = 3e5+1;
const int M = 1e9+7;
void solve() {
	string s; cin >> s;
	bool caps=1;
	bool c1=1,c2=1;
	for(int i = 1; i < s.size(); i++) {
		c1&=isupper(s[i]);
	}

	for(int i = 0; i < s.size(); i++)
		c2&=isupper(s[i]);

	caps&=(c1|c2);
	
	if(caps) {
		for(int i = 0; i < s.size(); i++) {
			if(isupper(s[i])) cout << (char) tolower(s[i]);
			else cout << (char) toupper(s[i]);
		}
	} else {
		cout << s << "\n";
	}

}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int t = 1; cin >> t;
	int t = 1;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}