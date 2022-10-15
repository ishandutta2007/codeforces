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
		string s;
		cin >> s;
		int c[2]={};
		for(char d : s)
			++c[d-'0'];
		cout << (min(c[0], c[1])&1?"DA":"NET") << "\n";
	}
}