#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans=0;
	cin >> n;
	unordered_map<string, int> mp;
	string s;
	for(int i=0; i<n; ++i) {
		cin >> s;
		++mp[s];
	}
	for(int i=0; i<n; ++i) {
		cin >> s;
		if(mp[s]>0)
			--mp[s];
		else
			++ans;
	}
	cout << ans;
}