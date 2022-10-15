#include <bits/stdc++.h>
using namespace std;

int n, a;
string s, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s >> t;
	for(int i=0; i<n-1; ++i) {
		if(s[i]!=t[i]&&s[i]!=s[i+1]&&s[i+1]!=t[i+1]) {
			swap(s[i], s[i+1]);
			++a;
		}
	}
	for(int i=0; i<n; ++i)
		a+=s[i]!=t[i];
	cout << a;
}