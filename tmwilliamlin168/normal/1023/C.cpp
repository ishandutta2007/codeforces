#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	string s, t;
	cin >> n >> k >> s;
	for(int i=0; i<n; ++i) {
		if(s[i]==')'&&k<n) {
			t.pop_back();
			k+=2;
		} else
			t+=s[i];
	}
	cout << t;
}