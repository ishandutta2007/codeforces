#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define ll long long
void dbg(vt<int> &a) {for(auto &edge: a) cout << edge << " ";}
int main() {
	string s, t;
	cin >> s >> t;
	for(auto &c: s)
		c = tolower(c);
	for(auto &c: t)
		c = tolower(c);
	if(s < t) {
		cout << -1 << "\n";
	} else if(t < s) {
		cout << 1 << "\n";
	} else {
		cout << 0 << "\n";
	}
}