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
		int n;
		string s;
		cin >> n >> s;
		string a="", b="";
		bool ch=0;
		for(int i=0; i<n; ++i) {
			if(s[i]=='2') {
				if(ch) {
					a+='2';
					b+='0';
				} else {
					a+='1';
					b+='1';
				}
			} else if(s[i]=='1') {
				a+='1';
				b+='0';
				if(!ch) {
					ch=1;
					swap(a, b);
				}
			} else {
				a+='0';
				b+='0';
			}
		}
		cout << a << "\n" << b << "\n";
	}
}