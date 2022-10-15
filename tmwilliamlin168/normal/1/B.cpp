#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	bool a=false;
	if(s[0]=='R') {
		for(int i=1; i<s.size(); ++i) {
			if(s[i]=='C'&&isdigit(s[i-1])) {
				a=true;
				break;
			}
		}
	}
	int r=0, c=0;
	if(a) {
		int i=1;
		for(; s[i]!='C'; ++i)
			r=r*10+s[i]-'0';
		for(++i; i<s.size(); ++i)
			c=c*10+s[i]-'0';
		string rs="";
		while(c>0) {
			rs=(char)('A'+(c-1)%26)+rs;
			if(!(c%26))
				c-=26;
			c/=26;
		}
		cout << rs << r << "\n";
	} else {
		int i=0;
		for(; isalpha(s[i]); ++i)
			r=r*26+s[i]-'A'+1;
		for(; i<s.size(); ++i)
			c=c*10+s[i]-'0';
		cout << "R" << c << "C" << r << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	while(n--)
		solve();
}