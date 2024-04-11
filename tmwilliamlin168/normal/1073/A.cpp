#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
	string s;
	cin >> n >> s;
	for(int i=0; i<n-1; ++i) {
		if(s[i]!=s[i+1]) {
			cout << "YES\n" << s[i] << s[i+1];
			return 0;
		}
	}
	cout << "NO";
}