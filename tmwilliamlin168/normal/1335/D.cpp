#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s[9];
		for(int i=0; i<9; ++i) {
			cin >> s[i];
			for(int j=0; j<9; ++j)
				if(s[i][j]=='2')
					s[i][j]='1';
			cout << s[i] << "\n";
		}
	}
}