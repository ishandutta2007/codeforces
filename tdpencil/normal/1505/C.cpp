#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
const int mxN=2e5;
string s;
int main() {
	int t=1;
	cin >> s;
	bool works = true;
	for(int i =2; i < s.size(); i++) {
		if(((s[i-1]-'A') + (s[i-2]-'A'))%26 != (s[i]-'A')) {
			works = false;
		}
	}
	cout << (works?"YES\n" : "NO\n");
}