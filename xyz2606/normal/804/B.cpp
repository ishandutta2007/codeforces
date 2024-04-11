#include<bits/stdc++.h>
using namespace std;
int mod(1e9 + 7);
int main() {
	string st;
	cin >> st;
	int pw(0), ans(0);
	reverse(st.begin(), st.end());
	for(char c : st) {
		if(c == 'b') pw = (pw + 1) % mod;
		else {
			ans = (ans + pw) % mod;
			pw = pw * 2 % mod;
		}
	}
	cout << ans << endl;
}