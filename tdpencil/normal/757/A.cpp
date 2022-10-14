#include <bits/stdc++.h>

#define ar array
#define ll long long

using namespace std;
const int mxN=2e5;

string s;
const string CH = "Bulbbasaur";
int ch[500];
int main() {
	int t=1;
	while(t--) {
		cin >> s;
		for(char c: s) {
			++ch[c];
		}	
		int ans=1e9;
		for(char c : CH) {
			if(c == 'a' || c == 'u') {
				ans=min(ch[c]/2, ans);
			} else {
				ans=min(ch[c], ans);
			}
		}
		cout << ans << '\n';
	}
}