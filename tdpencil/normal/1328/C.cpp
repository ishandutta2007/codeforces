#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string a, b;
		bool u=1;
		for(int i=0;i<n;i++) {
			if(s[i]=='0') {
				a+='0';
				b+='0';
			} else if(s[i]=='1') {
				if(u)
					a+='1',b+='0';
				else
					a+='0',b+='1';
				if(u)
					u=!u;
			} else if(s[i]=='2') {
				if(u)
					a+='1',b+='1';
				else
					a+='0',b+='2';
			}
		}
		cout << a << '\n';
		cout << b << '\n';
	}
}