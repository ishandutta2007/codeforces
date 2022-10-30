#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, p;
	string s;
	cin >> n >> p >> s;
	for(int i=p; i<n; ++i) {
		if(s[i]=='.'&&s[i-p]!='.')
			s[i]=1-(s[i-p]-'0')+'0';
	}
	for(int i=n-1-p; i>=0; --i) {
		if(s[i]=='.'&&s[i+p]!='.')
			s[i]=1-(s[i+p]-'0')+'0';
	}
	for(int i=0; i<n; ++i)
		if(s[i]=='.')
			s[i]=i/p%2+'0';
	for(int i=p; i<n; ++i) {
		if(s[i]!=s[i-p]) {
			cout << s;
			return 0;
		}
	}
	cout << "No";
}