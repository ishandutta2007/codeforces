#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int ans = (s[0]-'0'-1);
		int ans2= ans*10 + (s.size() * (s.size()+1)/2);
		cout << ans2 << '\n';
	}
}