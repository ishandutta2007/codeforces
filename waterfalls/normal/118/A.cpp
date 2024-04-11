#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	string ans;
	for (char c: s) {
		if (c<='Z') c+='a'-'A';
		if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y') continue;
		ans+='.';
		ans+=c;
	}
	cout << ans;

	return 0;
}