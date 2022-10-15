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
		int l=0, r=s.size()-1;
		while(l<s.size()&&s[l]=='0')
			++l;
		while(~r&&s[r]=='0')
			--r;
		int c=0;
		for(int i=l; i<=r; ++i)
			c+=s[i]!='1';
		cout << c << "\n";
	}
}