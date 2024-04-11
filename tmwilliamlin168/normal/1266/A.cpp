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
		bool h0=0, he=0;
		int s3=0;
		for(char c : s) {
			if(!h0&&c=='0')
				h0=1;
			else {
				if(c&1^1)
					he=1;
				s3+=(c-'0');
			}
		}
		if(h0&&he&&s3%3==0)
			cout << "red\n";
		else
			cout << "cyan\n";
	}
}